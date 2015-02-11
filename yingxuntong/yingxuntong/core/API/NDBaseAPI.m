//
//  NDBaseAPI.m
//  Pods
//
//  Created by ilikeido on 14-12-5.
//
//

#import "NDBaseAPI.h"
#import "ServerConfig.h"
#import "ShareValue.h"
#import <CommonCrypto/CommonDigest.h>
#import "LK_NSDictionary2Object.h"
#import "AFNetworking.h"
#import <objc/runtime.h>
#import <objc/message.h>

#define TIMEOUT_DEFAULT 30

#define SUCCESS_CODE @"1"

@interface NSString (md5)
-(NSString *) md5HexDigest;
@end

@implementation NSString (md5)

-(NSString *) md5HexDigest

{
    
    const char *original_str = [self UTF8String];
    
    unsigned char result[CC_MD5_DIGEST_LENGTH];
    
    CC_MD5(original_str, strlen(original_str), result);
    
    NSMutableString *hash = [NSMutableString string];
    
    for (int i = 0; i < 16; i++)
        
        [hash appendFormat:@"%02X", result[i]];
    
    return [hash lowercaseString];
    
}

@end

@implementation NDBasePage


@end


@interface NDBaseAPIRequest (){
    
}

@end

@implementation NDBaseAPIRequest

-(id)init{
    self = [super init];
    if (self) {
        
    }
    return self;
}

@end

@implementation NDBaseAPIResponse

@end

@implementation NDBaseAPI


+(AFHTTPClient *)client{
    static dispatch_once_t onceToken;
    static AFHTTPClient *_client;
    dispatch_once(&onceToken, ^{
        _client = [[AFHTTPClient alloc]initWithBaseURL:[NSURL URLWithString:BASE_SERVERLURL]];
    });
    return _client;
}


+(NSString *)getFailDescriptByErrorCode:(NSString *)errorCode{
    NSString *failDescription = @"";
    return failDescription;
}

+(void)filterParams:(NSMutableDictionary *)dict{
    unsigned int propertyCount = 0;
    static NSMutableArray *objectDefaultKeys ;
    if (objectDefaultKeys == nil) {
        objc_property_t *properties = class_copyPropertyList([NSObject class], &propertyCount);
        objectDefaultKeys = [[NSMutableArray alloc]init];
        for ( NSUInteger i = 0; i < propertyCount; i++ )
        {
            const char *	name = property_getName(properties[i]);
            NSString *		propertyName = [NSString stringWithCString:name encoding:NSUTF8StringEncoding];
            [objectDefaultKeys addObject:propertyName];
        }
        [objectDefaultKeys addObject:@"hash"];
        [objectDefaultKeys addObject:@"debugDescription"];
        [objectDefaultKeys addObject:@"description"];
    }
    for (NSString *key in objectDefaultKeys) {
        [dict removeObjectForKey:key];
    }
}

/**
 *  向服务器发起请求
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)request:(NDBaseAPIRequest *)request responseClass:(Class)responseClass completionBlockWithSuccess:(void(^)(NDBaseAPIResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail{
    AFHTTPClient *client = [NDBaseAPI client];
    client.parameterEncoding = AFFormURLParameterEncoding;
    client.allowsInvalidSSLCertificate = YES;
    NSMutableDictionary *dict = (NSMutableDictionary *)request.lkDictionary;
    [NDBaseAPI filterParams:dict];
    NSLog(@"request:%@",dict);
    NSURLRequest *urlRequest = [client requestWithMethod:METHOD_POST path:BASE_SERVERPATH  parameters:dict];
    AFHTTPRequestOperation *operation =
    [client HTTPRequestOperationWithRequest:urlRequest success:^(AFHTTPRequestOperation *operation, id responseObject) {
        if(responseObject){
            NSData *responseData = (NSData *)responseObject;
            NSString *responseString = [[NSString alloc]initWithData:responseData encoding:NSUTF8StringEncoding];
            responseString  = [responseString stringByReplacingOccurrencesOfString:@"null" withString:@"\"\""];
            NSLog(@"url:%@|response:%@",urlRequest.URL,responseString);
            NSError *error = nil;
            //IOS5自带解析类NSJSONSerialization从response中解析出数据放到字典中
            NSDictionary *dict = [NSJSONSerialization JSONObjectWithData:responseData options:NSJSONReadingMutableLeaves error:&error];
            if (dict) {
                NDBaseAPIResponse *response = [dict objectByClass:responseClass];
                if (!response) {
                    dispatch_async(dispatch_get_main_queue(), ^{
                        fail(response.returnCode,@"服务器异常");
                    });
                    return ;
                }
                if (![response.returnCode isEqual: SUCCESS_CODE]) {
                    NSString *errorMessage = [self getFailDescriptByErrorCode:response.returnCode ];
                    NSString *message = response.msg;
                    if (errorMessage.length == 0) {
                        errorMessage = message;
                    }
                    dispatch_async(dispatch_get_main_queue(), ^{
                        fail(response.returnCode,errorMessage);
                    });
                    return;
                }
                sucess(response);
            }else{
                dispatch_async(dispatch_get_main_queue(), ^{
                    fail(@"-1",@"服务器异常");
                });
            }
        }
    } failure:^(AFHTTPRequestOperation *operation, NSError *error) {
        NSLog(@"url:%@,fail:%@",urlRequest.URL,[error localizedDescription]);
        dispatch_async(dispatch_get_main_queue(), ^{
            fail(@"-1",@"网络不给力");
        });
    }];
    [client enqueueHTTPRequestOperation:operation];
}


+(void)downloadFile:(NSURL *)url downloadProgress:(void(^)(float progress))downloadProgress successBlock:(void(^)(NSURL *filepath))success errorBlock:(void(^)(NSString *))errorBlock;
{
    NSString *saveDirectory =
    [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0];
    NSString *savePath = [saveDirectory stringByAppendingPathComponent:[NSString stringWithFormat:@"%@",[url lastPathComponent]]];
    NSURL *fileUrl = [NSURL fileURLWithPath:savePath];
    if ([[NSFileManager defaultManager] fileExistsAtPath:savePath]){
        success(fileUrl);
        return;
    }
    
    NSString *cacheDirectory = [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) objectAtIndex:0];
    NSString *downloadPath = [cacheDirectory stringByAppendingPathComponent:[NSString stringWithFormat:@"%@",[url lastPathComponent]]];
    NSURLRequest *request = [NSURLRequest requestWithURL:url];
    
    //检查文件是否已经下载了一部分
    unsigned long long downloadedBytes = 0;
    if ([[NSFileManager defaultManager] fileExistsAtPath:downloadPath]) {
        NSFileManager * filemanager = [NSFileManager defaultManager];
        NSDictionary * attributes = [filemanager attributesOfItemAtPath:downloadPath error:nil];
        // file size
        NSNumber *theFileSize;
        theFileSize = [attributes objectForKey:NSFileSize];
        downloadedBytes= [theFileSize intValue];
        if (downloadedBytes > 0) {
            NSMutableURLRequest *mutableURLRequest = [request mutableCopy];
            NSString *requestRange = [NSString stringWithFormat:@"bytes=%llu-", downloadedBytes];
            [mutableURLRequest setValue:requestRange forHTTPHeaderField:@"Range"];
            request = mutableURLRequest;
        }
    }
    //下载请求
    AFHTTPRequestOperation *operation = [[AFHTTPRequestOperation alloc] initWithRequest:request];
    //下载路径
    operation.outputStream = [NSOutputStream outputStreamToFileAtPath:downloadPath append:YES];
    //下载进度回调
    [operation setDownloadProgressBlock:^(NSUInteger bytesRead, long long totalBytesRead, long long totalBytesExpectedToRead) {
        //下载进度
        float progress = ((float)totalBytesRead + downloadedBytes) / (totalBytesExpectedToRead + downloadedBytes);
        downloadProgress(progress);
    }];
    //成功和失败回调
    [operation setCompletionBlockWithSuccess:^(AFHTTPRequestOperation *operation, id responseObject) {
        NSError *error = nil;
        BOOL flag =  [[NSFileManager defaultManager]copyItemAtPath:downloadPath toPath:savePath error:(&error)];
        if (!flag) {
            errorBlock(NSLocalizedString(@"RspMsgError",nil));
        }else{
            success(fileUrl);
        }
    } failure:^(AFHTTPRequestOperation *operation, NSError *error) {
        errorBlock(NSLocalizedString(@"NetworkNotGood", nil));
    }];
    [operation start];
}


@end
