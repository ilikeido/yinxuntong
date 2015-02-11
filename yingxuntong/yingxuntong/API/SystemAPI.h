//
//  SystemAPI.h
//  yingxuntong
//
//  Created by ilikeido on 15-2-11.
//  Copyright (c) 2015年 ilikeido. All rights reserved.
//

#import "NDBaseAPI.h"
#import "Version.h"

/**
 *  获取服务端时间请求
 */
@interface GetCurrentDateTimeRequest : NDBaseAPIRequest

@end

/**
 *  获取服务端时间返回
 */
@interface GetCurrentDateTimeResponse : NDBaseAPIResponse

@property(nonatomic,strong) NSString *currentDateTime;

@end

/**
 *  获取版本更新
 */
@interface GetVersionRequest : NDBaseAPIRequest

@property(nonatomic,strong) NSString *keyName;

@property(nonatomic,strong) NSString *devNo;

@end


/**
 *  版本更新信息
 */
@interface GetVersionResponse : NDBaseAPIResponse

@property(nonatomic,strong) Version *version;//版本更新信息

@end

/**
 *  数据字典请求
 */
@interface GetDataItemRequest : NDBaseAPIRequest

@property(nonatomic,strong) NSString *typeKey;

@end


/**
 *  数据字典返回
 */
@interface GetDataItemResponse : NDBaseAPIResponse

@end

@interface SystemAPI : NDBaseAPI

/**
 *  获取服务端时间
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)getCurrentDateTimeByRequest:(GetCurrentDateTimeRequest *)request completionBlockWithSuccess:(void(^)(GetCurrentDateTimeResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail;


/**
 *  获取版本更新信息
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)getVersionByRequest:(GetVersionRequest *)request completionBlockWithSuccess:(void(^)(GetVersionResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail;

/**
 *  获取数据字典
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)getDataItemsByRequest:(GetDataItemRequest *)request completionBlockWithSuccess:(void(^)(GetDataItemResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail;




@end
