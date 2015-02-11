//
//  SystemAPI.m
//  yingxuntong
//
//  Created by ilikeido on 15-2-11.
//  Copyright (c) 2015年 ilikeido. All rights reserved.
//

#import "SystemAPI.h"

@implementation GetCurrentDateTimeRequest

-(NSString *)method{
    return @"/sfa/getCurrentDateTime";
}

@end

@implementation GetCurrentDateTimeResponse

@end

/**
 *  获取版本更新
 */
@implementation GetVersionRequest

-(NSString *)method{
    return @"/version/get";
}

@end

/**
 *  版本更新信息
 */
@implementation GetVersionResponse

@end

/**
 *  数据字典请求
 */
@implementation GetDataItemRequest

-(NSString *)method{
    return @"/dataitem/list";
}

@end


/**
 *  数据字典返回
 */
@implementation GetDataItemResponse

@end


@implementation SystemAPI

/**
 *  获取服务端时间
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)getCurrentDateTimeByRequest:(GetCurrentDateTimeRequest *)request completionBlockWithSuccess:(void(^)(GetCurrentDateTimeResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail{
    [self request:request responseClass:[GetCurrentDateTimeResponse class] completionBlockWithSuccess:^(NDBaseAPIResponse *response) {
        sucess((GetCurrentDateTimeResponse *)response);
    } Fail:^(NSString *returnCode, NSString *failDescript) {
        fail(returnCode,failDescript);
    }];
}

/**
 *  获取版本更新信息
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)getVersionByRequest:(GetVersionRequest *)request completionBlockWithSuccess:(void(^)(GetVersionResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail{
    [self request:request responseClass:[GetVersionResponse class] completionBlockWithSuccess:^(NDBaseAPIResponse *response) {
        sucess((GetVersionResponse *)response);
    } Fail:^(NSString *returnCode, NSString *failDescript) {
        fail(returnCode,failDescript);
    }];
}

/**
 *  获取数据字典
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)getDataItemsByRequest:(GetDataItemRequest *)request completionBlockWithSuccess:(void(^)(GetDataItemResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail{
    [self request:request responseClass:[GetDataItemResponse class] completionBlockWithSuccess:^(NDBaseAPIResponse *response) {
        sucess((GetDataItemResponse *)response);
    } Fail:^(NSString *returnCode, NSString *failDescript) {
        fail(returnCode,failDescript);
    }];
}




@end
