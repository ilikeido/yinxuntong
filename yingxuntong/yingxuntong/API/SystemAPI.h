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

/**
 *  消息推送绑定请求
 */
@interface PushBindRequest : NDBaseAPIRequest

@property(nonatomic,strong) NSString *	userId	;//	用户编号
@property(nonatomic,strong) NSString *	userType	;//	用户类型{1:机构登录用户，2：商户登录用户}
@property(nonatomic,strong) NSString *	bindUserId	;//	绑定后的userId
@property(nonatomic,strong) NSString *	bindChannelId	;//	绑定后的channelId
@property(nonatomic,strong) NSString *	clientType	;//	终端类型{1:android,2:ios}

@end

/**
 *  消息推送绑定返回
 */
@interface PushBindResponse : NDBaseAPIResponse

@end

/**
 *  个人中心意见反馈请求
 */
@interface PersonFeedBackAddRequest : NDBaseAPIRequest

@property(nonatomic,strong) NSString *	userId	;//	用户编号
@property(nonatomic,strong) NSString *	memberId	;//	成员编号
@property(nonatomic,strong) NSString *	realName	;//	用户真实姓名
@property(nonatomic,strong) NSString *	content	;//
@property(nonatomic,strong) NSString *	imsi	;//
@property(nonatomic,strong) NSString *	imei	;//
@property(nonatomic,strong) NSString *	clientVersion	;//
@property(nonatomic,strong) NSString *	clientType	;//

@end

/**
 *  个人中心意见反馈返回
 */
@interface PersonFeedBackAddResponse : NDBaseAPIResponse

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

/**
 *  消息推送绑定
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)bindPushByRequest:(PushBindRequest *)request completionBlockWithSuccess:(void(^)(PushBindResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail;


/**
 *  个人中心意见反馈
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)addByPersonFeedBackRequest:(PersonFeedBackAddRequest *)request completionBlockWithSuccess:(void(^)(PersonFeedBackAddResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail;

@end
