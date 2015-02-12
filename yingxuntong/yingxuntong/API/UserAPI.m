//
//  UserAPI.m
//  yingxuntong
//
//  Created by ilikeido on 15-2-11.
//  Copyright (c) 2015年 ilikeido. All rights reserved.
//
#import "UserAPI.h"

@implementation LoginRequest

-(NSString *)method{
    return @"/login";
}

@end

@implementation LoginResponse

@end

@implementation PosLoginRequest

-(NSString *)method{
    return @"/poslogin2";
}

@end

@implementation PosLoginResponse

@end

@implementation RestPwdRequest

-(NSString *)method{
    return @"/tsuser/restpwd/update";
}

@end

@implementation RestPwdResponse

@end

@implementation MemberListRequest

-(NSString *)method{
    return @"/member/list";
}

@end

@implementation MemberListResponse

+(Class)__membersClass{
    return [Member class];
}

@end



@implementation UserAPI

/**
 *  用户登录
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)posLoginRequestByRequest:(PosLoginRequest *)request completionBlockWithSuccess:(void(^)(PosLoginResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail{
    [self request:request responseClass:[PosLoginResponse class] completionBlockWithSuccess:^(NDBaseAPIResponse *response) {
        sucess((PosLoginResponse *)response);
    } Fail:^(NSString *returnCode, NSString *failDescript) {
        fail(returnCode,failDescript);
    }];
}

/**
 *  修改密码
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)restPwdByRequest:(RestPwdRequest *)request completionBlockWithSuccess:(void(^)(RestPwdResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail{
    [self request:request responseClass:[RestPwdResponse class] completionBlockWithSuccess:^(NDBaseAPIResponse *response) {
        sucess((RestPwdResponse *)response);
    } Fail:^(NSString *returnCode, NSString *failDescript) {
        fail(returnCode,failDescript);
    }];
}


/**
 *  修改密码
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)memberListByRequest:(MemberListRequest *)request completionBlockWithSuccess:(void(^)(MemberListResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail{
    [self request:request responseClass:[MemberListResponse class] completionBlockWithSuccess:^(NDBaseAPIResponse *response) {
        sucess((MemberListResponse *)response);
    } Fail:^(NSString *returnCode, NSString *failDescript) {
        fail(returnCode,failDescript);
    }];
}

@end
