//
//  CompanyMchtAPI.m
//  yingxuntong
//
//  Created by ilikeido on 15-2-26.
//  Copyright (c) 2015年 ilikeido. All rights reserved.
//

#import "CompanyMchtAPI.h"
#import "CompanyMchtTerminal.h"
#import "CompanyTerminalInfo.h"

@implementation CompanyMchtPage

+(Class)__resultClass{
    return [CompanyMcht class];
}

@end

@implementation CompanyMchtPageRequest

-(NSString *)method{
    return @"/companymcht/page";
}

@end

@implementation CompanyMchtPageResponse

@end


@implementation CompanyMchtTerminalRequest

-(NSString *)method{
    return @"/companyterminalinfo/list";
}

@end

@implementation CompanyMchtTerminalResponse

+(Class)__companymchtterminalsClass{
    return [CompanyMchtTerminal class];
}

@end

@implementation CompanyTerminalInfoPage

+(Class)__resultClass{
    return [CompanyTerminalInfo class];
}

@end

@implementation CompanyTerminalInfoPageRequest

-(NSString *)method{
    return @"/companyterminalinfo/page";
}

@end

@implementation CompanyTerminalInfoPageResponse

@end


@implementation CompanyMchtAPI

/**
 *  5.5.1	商户分页查询（X）
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)getCompanyMchtPageByRequest:(CompanyMchtPageRequest *)request completionBlockWithSuccess:(void(^)(CompanyMchtPageResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail{
    [self request:request responseClass:[CompanyMchtPageResponse class] completionBlockWithSuccess:^(NDBaseAPIResponse *response) {
        sucess((CompanyMchtPageResponse *)response);
    } Fail:^(NSString *returnCode, NSString *failDescript) {
        fail(returnCode,failDescript);
    }];
}


/**
 *  5.5.2	商户终端列表（X）
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)getCompanyMchtTerminalByRequest:(CompanyMchtTerminalRequest *)request completionBlockWithSuccess:(void(^)(CompanyMchtTerminalResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail{
    [self request:request responseClass:[CompanyMchtTerminalResponse class] completionBlockWithSuccess:^(NDBaseAPIResponse *response) {
        sucess((CompanyMchtTerminalResponse *)response);
    } Fail:^(NSString *returnCode, NSString *failDescript) {
        fail(returnCode,failDescript);
    }];
}


/**
 *  5.5.3	商户终端装机历史(分页)
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)getCompanyTerminalInfoPageByRequest:(CompanyTerminalInfoPageRequest *)request completionBlockWithSuccess:(void(^)(CompanyTerminalInfoPageResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail{
    [self request:request responseClass:[CompanyTerminalInfoPageResponse class] completionBlockWithSuccess:^(NDBaseAPIResponse *response) {
        sucess((CompanyTerminalInfoPageResponse *)response);
    } Fail:^(NSString *returnCode, NSString *failDescript) {
        fail(returnCode,failDescript);
    }];
}

@end
