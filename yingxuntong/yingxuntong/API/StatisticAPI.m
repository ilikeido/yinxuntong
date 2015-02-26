//
//  StatisticAPI.m
//  yingxuntong
//
//  Created by ilikeido on 15-2-25.
//  Copyright (c) 2015年 ilikeido. All rights reserved.
//

#import "StatisticAPI.h"

@implementation InstallStateCount

@end

@implementation InstallStateCountRequest

-(NSString *)method{
    return @"/statistic/company/install/area";
}

@end


@implementation InstallStateCountResponse

+(Class)__statisticsClass{
    return [InstallStateCount class];
}

@end


@implementation CompanyState

@end

@implementation CompanyStateRequest

-(NSString *)method{
    return @"/statistic/company/num";
}

@end


@implementation CompanyStateResponse

+(Class)__statisticsClass{
    return [CompanyState class];
}

@end

@implementation CompanyMchtNumber

@end

@implementation CompanyMchtNumberRequest

-(NSString *)method{
    return @"/statistic/mcht/num";
}

@end


@implementation CompanyMchtNumberResponse

+(Class)__statisticsClass{
    return [CompanyMchtNumber class];
}

@end


@implementation CompanyMchtGrade

@end

@implementation CompanyMchtGradeRequest

-(NSString *)method{
    return @"/statistic/mcht/grade";
}

@end


@implementation CompanyMchtGradeResponse

+(Class)__statisticsClass{
    return [CompanyMchtGrade class];
}

@end


@implementation CompanyMchtActive

@end

@implementation CompanyMchtActiveRequest

-(NSString *)method{
    return @"/statistic/mcht/active";
}

@end


@implementation CompanyMchtActiveResponse

+(Class)__statisticsClass{
    return [CompanyMchtActive class];
}

@end

@implementation OrgTransaction

@end

@implementation OrgTransactionPage

+(Class)__resultClass{
    return [OrgTransaction class];
}

@end

@implementation OrgTransactionRequest

-(NSString *)method{
    return @"/statistic/transaction/org/day";
}

@end


@implementation OrgTransactionResponse

@end


@implementation TotalStatisticData

@end

@implementation TerminalStatisticData

@end


@implementation TerminalStatisticPage

+(Class)__resultClass{
    return [TerminalStatisticData class];
}

@end

@implementation TerminalStatisticRequest

-(NSString *)method{
    return @"/statistic/transaction/terminal";
}

@end


@implementation TerminalStatisticResponse

@end

@implementation DayTerminalStatisticData

@end


@implementation DayTerminalStatisticPage

+(Class)__resultClass{
    return [DayTerminalStatisticData class];
}

@end

@implementation DayTerminalStatisticRequest

-(NSString *)method{
    return @"/statistic/transaction/terminal/day";
}

@end


@implementation DayTerminalStatisticResponse

@end


@implementation CompanyMchtStatisticData

@end


@implementation CompanyMchtStatisticPage

+(Class)__resultClass{
    return [CompanyMchtStatisticData class];
}

@end

@implementation CompanyMchtStatisticRequest

-(NSString *)method{
    return @"/statistic/transaction/mcht";
}

@end


@implementation CompanyMchtStatisticResponse

@end


@implementation DayCompanyMchtStatisticData

@end


@implementation DayCompanyMchtStatisticPage

+(Class)__resultClass{
    return [DayCompanyMchtStatisticData class];
}

@end

@implementation DayCompanyMchtStatisticRequest

-(NSString *)method{
    return @"/statistic/transaction/mcht/day";
}

@end


@implementation DayCompanyMchtStatisticResponse

@end


@implementation LoginStatistcData

@end

@implementation LoginStatistcPage

+(Class)__resultClass{
    return [LoginStatistcData class];
}

@end

@implementation LoginStatistcRequest

-(NSString *)method{
    return @"/statistic/user/login";
}

@end


@implementation LoginStatistcResponse

@end


@implementation StatisticAPI

/**
 *  5.6.1	装机状态统计
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)getInstallStateCountByRequest:(InstallStateCountRequest *)request completionBlockWithSuccess:(void(^)(InstallStateCountResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail{
    [self request:request responseClass:[InstallStateCountResponse class] completionBlockWithSuccess:^(NDBaseAPIResponse *response) {
        sucess((InstallStateCountResponse *)response);
    } Fail:^(NSString *returnCode, NSString *failDescript) {
        fail(returnCode,failDescript);
    }];
}

/**
 *  5.6.2	协议状态统计
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)getCompanyStateByRequest:(CompanyStateRequest *)request completionBlockWithSuccess:(void(^)(CompanyStateResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail{
    [self request:request responseClass:[CompanyStateResponse class] completionBlockWithSuccess:^(NDBaseAPIResponse *response) {
        sucess((CompanyStateResponse *)response);
    } Fail:^(NSString *returnCode, NSString *failDescript) {
        fail(returnCode,failDescript);
    }];
}

/**
 *  5.6.3	商户数量统计
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)getCompanyMchtNumberByRequest:(CompanyMchtNumberRequest *)request completionBlockWithSuccess:(void(^)(CompanyMchtNumberResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail{
    [self request:request responseClass:[CompanyMchtNumberResponse class] completionBlockWithSuccess:^(NDBaseAPIResponse *response) {
        sucess((CompanyMchtNumberResponse *)response);
    } Fail:^(NSString *returnCode, NSString *failDescript) {
        fail(returnCode,failDescript);
    }];
}

/**
 *  5.6.4	商户等级统计
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)getCompanyMchtGradeByRequest:(CompanyMchtGradeRequest *)request completionBlockWithSuccess:(void(^)(CompanyMchtGradeResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail{
    [self request:request responseClass:[CompanyMchtGradeResponse class] completionBlockWithSuccess:^(NDBaseAPIResponse *response) {
        sucess((CompanyMchtGradeResponse *)response);
    } Fail:^(NSString *returnCode, NSString *failDescript) {
        fail(returnCode,failDescript);
    }];
}

/**
 *  5.6.5	商户活跃度统计
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)getCompanyMchtActiveByRequest:(CompanyMchtActiveRequest *)request completionBlockWithSuccess:(void(^)(CompanyMchtActiveResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail{
    [self request:request responseClass:[CompanyMchtActiveResponse class] completionBlockWithSuccess:^(NDBaseAPIResponse *response) {
        sucess((CompanyMchtActiveResponse *)response);
    } Fail:^(NSString *returnCode, NSString *failDescript) {
        fail(returnCode,failDescript);
    }];
}

/**
 *  5.6.6	机构交易统计(分页)
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)getOrgTransactionPageByRequest:(OrgTransactionRequest *)request completionBlockWithSuccess:(void(^)(OrgTransactionResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail{
    [self request:request responseClass:[OrgTransactionResponse class] completionBlockWithSuccess:^(NDBaseAPIResponse *response) {
        sucess((OrgTransactionResponse *)response);
    } Fail:^(NSString *returnCode, NSString *failDescript) {
        fail(returnCode,failDescript);
    }];
}

/**
 *  5.6.7	终端交易统计(分页)
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)getTerminalStatisticPageByRequest:(TerminalStatisticRequest *)request completionBlockWithSuccess:(void(^)(TerminalStatisticResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail{
    [self request:request responseClass:[TerminalStatisticResponse class] completionBlockWithSuccess:^(NDBaseAPIResponse *response) {
        sucess((TerminalStatisticResponse *)response);
    } Fail:^(NSString *returnCode, NSString *failDescript) {
        fail(returnCode,failDescript);
    }];
}

/**
 *  5.6.8	终端交易明细（分页）
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)getDayTerminalStatisticPageByRequest:(DayTerminalStatisticRequest *)request completionBlockWithSuccess:(void(^)(DayTerminalStatisticResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail{
    [self request:request responseClass:[DayTerminalStatisticResponse class] completionBlockWithSuccess:^(NDBaseAPIResponse *response) {
        sucess((DayTerminalStatisticResponse *)response);
    } Fail:^(NSString *returnCode, NSString *failDescript) {
        fail(returnCode,failDescript);
    }];
}


/**
 *  5.6.9	商户交易统计(分页)
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)getCompanyMchtStatisticPageByRequest:(CompanyMchtStatisticRequest *)request completionBlockWithSuccess:(void(^)(CompanyMchtStatisticResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail{
    [self request:request responseClass:[CompanyMchtStatisticResponse class] completionBlockWithSuccess:^(NDBaseAPIResponse *response) {
        sucess((CompanyMchtStatisticResponse *)response);
    } Fail:^(NSString *returnCode, NSString *failDescript) {
        fail(returnCode,failDescript);
    }];
}


/**
 *  5.6.10	商户交易明细 (分页)
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)getDayCompanyMchtStatisticPageByRequest:(DayCompanyMchtStatisticRequest *)request completionBlockWithSuccess:(void(^)(DayCompanyMchtStatisticResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail{
    [self request:request responseClass:[DayCompanyMchtStatisticResponse class] completionBlockWithSuccess:^(NDBaseAPIResponse *response) {
        sucess((DayCompanyMchtStatisticResponse *)response);
    } Fail:^(NSString *returnCode, NSString *failDescript) {
        fail(returnCode,failDescript);
    }];
}

/**
 *  5.6.11	用户登录情况统计 (分页)
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)getLoginStatistcPageByRequest:(LoginStatistcRequest *)request completionBlockWithSuccess:(void(^)(LoginStatistcResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail{
    [self request:request responseClass:[LoginStatistcResponse class] completionBlockWithSuccess:^(NDBaseAPIResponse *response) {
        sucess((LoginStatistcResponse *)response);
    } Fail:^(NSString *returnCode, NSString *failDescript) {
        fail(returnCode,failDescript);
    }];
}

@end
