//
//  UserAPI.m
//  yingxuntong
//
//  Created by ilikeido on 15-2-11.
//  Copyright (c) 2015年 ilikeido. All rights reserved.
//
#import "UserAPI.h"
#import "FCUUID.h"
#import "ShareValue.h"

@implementation LoginRequest

-(NSString *)method{
    return @"/login";
}

@end

@implementation LoginResponse

@end

@interface PosLoginRequest()

@property(nonatomic,strong) NSString *deviceNo;//设备号(IMEI号)
@property(nonatomic,strong) NSString *deviceVersion;//设备版本号
@property(nonatomic,assign) int deviceType;//设备类型(1:android,2:ios)

@end

@implementation PosLoginRequest

-(NSString *)method{
    return @"/poslogin2";
}

-(id)init{
    self = [super init];
    if (self) {
        self.deviceNo = @"188d87b1bbe34ca5a28bc7ff77e8a6f8";//[FCUUID uuidForDevice];
        self.deviceVersion = [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"];
        self.deviceType = 2;
    }
    return self;
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
+(void)posLoginByRequest:(PosLoginRequest *)request completionBlockWithSuccess:(void(^)(PosLoginResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail;{
    [self request:request responseClass:[PosLoginResponse class] completionBlockWithSuccess:^(NDBaseAPIResponse *response) {
        PosLoginResponse *tResponse = (PosLoginResponse *)response;
        [ShareValue standardShareValue].user = tResponse.user;
        [ShareValue standardShareValue].rememberPwd = YES;
        if ([ShareValue standardShareValue].rememberPwd) {
            [ShareValue standardShareValue].save_userName = request.phoneNum;
            [ShareValue standardShareValue].save_pwd = request.password;
        }else{
            [ShareValue standardShareValue].save_userName = nil;
            [ShareValue standardShareValue].save_pwd = nil;
        }
        sucess(tResponse);
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
