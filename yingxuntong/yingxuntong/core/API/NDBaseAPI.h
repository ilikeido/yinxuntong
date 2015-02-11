//
//  NDBaseAPI.h
//  Pods
//
//  Created by ilikeido on 14-12-5.
//
//

#import <Foundation/Foundation.h>

@interface NDBasePage : NSObject

@property(nonatomic,strong) NSArray *result;
@property(nonatomic,assign) int pageSize;
@property(nonatomic,assign) int pageNum;
@property(nonatomic,assign) int totalCount;
@property(nonatomic,assign) BOOL isLastPage;

@end

@interface NDBaseAPIRequest : NSObject

@property(nonatomic,strong) NSString *method;

@end

@interface NDBaseAPIResponse : NSObject

@property(nonatomic,strong) NSString *returnCode;
@property(nonatomic,strong) NSString *apiMethod;
@property(nonatomic,strong) NSString *msg;

@end


@interface NDBaseAPI : NSObject

/**
 *  向服务器发起请求
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)request:(NDBaseAPIRequest *)request responseClass:(Class)responseClass completionBlockWithSuccess:(void(^)(NDBaseAPIResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail;

/**
 *  下载文件
 *
 *  @param url              文件url
 *  @param downloadProgress 下载进度
 *  @param success          成功后的block
 *  @param errorBlock       失败block
 */
+(void)downloadFile:(NSURL *)url downloadProgress:(void(^)(float progress))downloadProgress successBlock:(void(^)(NSURL *filepath))success errorBlock:(void(^)(NSString *))errorBlock;

@end
