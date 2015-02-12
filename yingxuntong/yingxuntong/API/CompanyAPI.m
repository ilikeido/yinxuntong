//
//  CompanyAPI.m
//  yingxuntong
//
//  Created by ilikeido on 15-2-12.
//  Copyright (c) 2015年 ilikeido. All rights reserved.
//

#import "CompanyAPI.h"
#import "Step.h"
#import "TsUser.h"
#import "Company.h"

@implementation GetNextSetpListRequest

-(NSString *)method{
    return @"/step/list/next";
}

@end

@implementation GetNextSetpListResponse

+(Class)__nexStepsClass{
    return [Step class];
}

@end

@implementation GetStepUserListRequest

-(NSString *)method{
    return @"tsuser/list/step";
}

@end

@implementation GetStepUserListResponse

+(Class)__stepUsersClass{
    return [TsUser class];
}

@end

@implementation CompanyPage

+(Class)__resultClass{
    return [Company class];
}

@end

@implementation CompanyPageRequest

-(NSString *)method{
    return @"/company/page";
}

@end

@implementation CompanyPageResponse

@end


@implementation CompanyUpdateRequest

-(NSString *)method{
    return @"/company/update";
}


@end

@implementation CompanyUpdateResponse


@end


@implementation CompanyAPI

/**
 *  获取协议下一操作列表
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)getNextSetpListByRequest:(GetNextSetpListRequest *)request completionBlockWithSuccess:(void(^)(GetNextSetpListResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail{
    [self request:request responseClass:[GetNextSetpListResponse class] completionBlockWithSuccess:^(NDBaseAPIResponse *response) {
        sucess((GetNextSetpListResponse *)response);
    } Fail:^(NSString *returnCode, NSString *failDescript) {
        fail(returnCode,failDescript);
    }];
}


/**
 *  获取步骤操作人列表
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)getStepUserListByRequest:(GetStepUserListRequest *)request completionBlockWithSuccess:(void(^)(GetStepUserListResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail{
    [self request:request responseClass:[GetStepUserListResponse class] completionBlockWithSuccess:^(NDBaseAPIResponse *response) {
        sucess((GetStepUserListResponse *)response);
    } Fail:^(NSString *returnCode, NSString *failDescript) {
        fail(returnCode,failDescript);
    }];
}

/**
 *  协议分页查询
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)getCompanyPageByRequest:(CompanyPageRequest *)request completionBlockWithSuccess:(void(^)(CompanyPageResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail{
    [self request:request responseClass:[CompanyPageResponse class] completionBlockWithSuccess:^(NDBaseAPIResponse *response) {
        sucess((CompanyPageResponse *)response);
    } Fail:^(NSString *returnCode, NSString *failDescript) {
        fail(returnCode,failDescript);
    }];
}

@end
