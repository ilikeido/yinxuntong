//
//  UserAPI.h
//  yingxuntong
//
//  Created by ilikeido on 15-2-11.
//  Copyright (c) 2015年 ilikeido. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NDBaseAPI.h"
#import "Member.h"
#import "EnterpriseConfig.h"
#import "TsUser.h"

/**
 *  登录请求
 */
@interface LoginRequest : NDBaseAPIRequest

@property(nonatomic,strong) NSString *phoneNum;//用户名
@property(nonatomic,strong) NSString *password;//密码
@property(nonatomic,strong) NSString *deviceNo;//设备号(IMEI号)
@property(nonatomic,strong) NSString *deviceVersion;//设备版本号
@property(nonatomic,assign) int deviceType;//设备类型(1:android,2:ios)

@end

/**
 *  登录返回
 */
@interface LoginResponse : NDBaseAPIResponse

@property(nonatomic,strong) Member *member;//用户信息

@property(nonatomic,strong) EnterpriseConfig *enterpriseConfig;

@property(nonatomic,strong) NSString *subCode;//10:成功,01: 用户不存在或密码不正确, 02: 用户被禁用,03: 用户所在企业不存在或被禁用,无法登录,04,手机号或密码为空
@property(nonatomic,strong) NSString *subMsg;//返回子信息

@end

/**
 *  用户登录系统请求(系统-v2)
 */
@interface PosLoginRequest : NDBaseAPIRequest

@property(nonatomic,strong) NSString *phoneNum;//用户名
@property(nonatomic,strong) NSString *password;//密码


@end

/**
 *  用户登录返回(系统-v2)
 */
@interface PosLoginResponse : NDBaseAPIResponse

@property(nonatomic,strong) TsUser *user;//用户信息

@property(nonatomic,strong) NSString *subCode;//10:成功,01: 用户不存在或密码不正确, 02: 用户被禁用,03: 用户所在企业不存在或被禁用,无法登录,04,手机号或密码为空

@property(nonatomic,strong) NSString *subMsg;//返回子信息

@end

/**
 *  修改密码(机构用户)
 */
@interface RestPwdRequest : NDBaseAPIRequest

@property(nonatomic,assign) int userId;
@property(nonatomic,strong) NSString *userPwd;

@end

/**
 *  修改密码返回
 */
@interface RestPwdResponse : NDBaseAPIResponse

@end

/**
 *  用户列表
 */
@interface MemberListRequest : NDBaseAPIRequest

@property(nonatomic,strong) NSString *enterpriseId;//企业编号
@property(nonatomic,strong) NSString *memberId;//用户编号
@property(nonatomic,strong) NSString *orgCode;//组织机构编号，模糊匹配该机构编码下的所有组织结构
@property(nonatomic,strong) NSString *realName;//真实姓名

@property(nonatomic,strong) NSString *phoneNum;//电话号码

@property(nonatomic,strong) NSString *isMobileUser;//是否是手机用户(1:是,0:否)

@property(nonatomic,strong) NSString *orderField;//排序字段(参见Member相关属性)

@property(nonatomic,strong) NSString *orderDirection;//排序方式,升序/降序：ASC/DESC

@end

@interface MemberListResponse : NDBaseAPIResponse

@property(nonatomic,strong) NSArray *members;

@end


@interface UserAPI : NDBaseAPI

/**
 *  用户登录
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)posLoginByRequest:(PosLoginRequest *)request completionBlockWithSuccess:(void(^)(PosLoginResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail;

/**
 *  修改密码
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)restPwdByRequest:(RestPwdRequest *)request completionBlockWithSuccess:(void(^)(RestPwdResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail;


/**
 *  修改密码
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)memberListByRequest:(MemberListRequest *)request completionBlockWithSuccess:(void(^)(MemberListResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail;

@end
