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
#import "AgreementOperateLog.h"
#import "CredentialType.h"

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
    return @"/tsuser/list/step";
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

@implementation CompanySubmitNextRequest

-(NSString *)method{
    return @"/company/submitNext";
}

@end

@implementation CompanySubmitNextResponse

@end

@implementation AgreementOperHisRequest

-(NSString *)method{
    return @"/company/agreementOperHis";
}

@end

@implementation AgreementOperHisResponse

+(Class)__agreementOperHisClass{
    return [AgreementOperateLog class];
}

@end


@implementation GetCompanyfileListRequest

-(NSString *)method{
    return @"/companyfile/list";
}

@end

@implementation GetCompanyfileListResponse

+(Class)__credentialTypesClass{
    return [CredentialType  class];
}

@end

@implementation DelCompanyRequest

-(NSString *)method{
    return @"/company/delete";
}

@end

@implementation DelCompanyResponse


@end

@implementation CancelCompanyRequest

-(NSString *)method{
    return @"/company/cancle";
}

@end

@implementation CancelCompanyResponse


@end

@implementation UpdateCompanyFileRequest

-(NSString *)method{
    return @"/companyfile/update";
}

@end

@implementation UpdateCompanyFileResponse


@end

@implementation DelCompanyFileRequest

-(NSString *)method{
    return @"/companyfile/delete";
}

@end

@implementation DelCompanyFileResponse


@end

@implementation ShowCompanyRequest

-(NSString *)method{
    return @"/company/show";
}

@end

@implementation ShowCompanyResponse


@end

@implementation FeedbackUpdateRequest

-(NSString *)method{
    return @"/companyfeedback/update";
}

@end

@implementation FeedbackUpdateResponse

@end

@implementation FeedBackListRequest

-(NSString *)method{
    return @"/companyfeedback/list";
}

@end

@implementation FeedBackListResponse

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

/**
 *  协议申请/修改
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)updateCompanyByRequest:(CompanyUpdateRequest *)request completionBlockWithSuccess:(void(^)(CompanyUpdateResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail{
    [self request:request responseClass:[CompanyPageResponse class] completionBlockWithSuccess:^(NDBaseAPIResponse *response) {
        sucess((CompanyUpdateResponse *)response);
    } Fail:^(NSString *returnCode, NSString *failDescript) {
        fail(returnCode,failDescript);
    }];
}

/**
 *  协议提交下一操作
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)submitNextByRequest:(CompanySubmitNextRequest *)request completionBlockWithSuccess:(void(^)(CompanySubmitNextResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail{
    [self request:request responseClass:[CompanySubmitNextResponse class] completionBlockWithSuccess:^(NDBaseAPIResponse *response) {
        sucess((CompanySubmitNextResponse *)response);
    } Fail:^(NSString *returnCode, NSString *failDescript) {
        fail(returnCode,failDescript);
    }];
}



/**
 *  协议申请进度查询
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)queryAgreementOperHisByRequest:(AgreementOperHisRequest *)request completionBlockWithSuccess:(void(^)(AgreementOperHisResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail{
    [self request:request responseClass:[AgreementOperHisResponse class] completionBlockWithSuccess:^(NDBaseAPIResponse *response) {
        sucess((AgreementOperHisResponse *)response);
    } Fail:^(NSString *returnCode, NSString *failDescript) {
        fail(returnCode,failDescript);
    }];
}


/**
 *  协议图片列表
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)getCompanyfileListByRequest:(GetCompanyfileListRequest *)request completionBlockWithSuccess:(void(^)(GetCompanyfileListResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail{
    [self request:request responseClass:[GetCompanyfileListResponse class] completionBlockWithSuccess:^(NDBaseAPIResponse *response) {
        sucess((GetCompanyfileListResponse *)response);
    } Fail:^(NSString *returnCode, NSString *failDescript) {
        fail(returnCode,failDescript);
    }];
}

/**
 *  协议删除
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)delCompanyByRequest:(DelCompanyRequest *)request completionBlockWithSuccess:(void(^)(DelCompanyResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail{
    [self request:request responseClass:[DelCompanyResponse class] completionBlockWithSuccess:^(NDBaseAPIResponse *response) {
        sucess((DelCompanyResponse *)response);
    } Fail:^(NSString *returnCode, NSString *failDescript) {
        fail(returnCode,failDescript);
    }];
}

/**
 *  协议作废
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)cancelCompanyByRequest:(CancelCompanyRequest *)request completionBlockWithSuccess:(void(^)(CancelCompanyResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail{
    [self request:request responseClass:[CancelCompanyResponse class] completionBlockWithSuccess:^(NDBaseAPIResponse *response) {
        sucess((CancelCompanyResponse *)response);
    } Fail:^(NSString *returnCode, NSString *failDescript) {
        fail(returnCode,failDescript);
    }];
}



/**
 *  协议资料上传
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)updateCompanyFileByRequest:(UpdateCompanyFileRequest *)request completionBlockWithSuccess:(void(^)(UpdateCompanyFileResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail{
    [self request:request responseClass:[UpdateCompanyFileResponse class] completionBlockWithSuccess:^(NDBaseAPIResponse *response) {
        sucess((UpdateCompanyFileResponse *)response);
    } Fail:^(NSString *returnCode, NSString *failDescript) {
        fail(returnCode,failDescript);
    }];
}

/**
 *  协议资料删除
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)delCompanyFileByRequest:(DelCompanyFileRequest *)request completionBlockWithSuccess:(void(^)(DelCompanyFileResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail{
    [self request:request responseClass:[DelCompanyFileResponse class] completionBlockWithSuccess:^(NDBaseAPIResponse *response) {
        sucess((DelCompanyFileResponse *)response);
    } Fail:^(NSString *returnCode, NSString *failDescript) {
        fail(returnCode,failDescript);
    }];
}


/**
 *  协议详情
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)showCompanyByRequest:(ShowCompanyRequest *)request completionBlockWithSuccess:(void(^)(ShowCompanyResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail{
    [self request:request responseClass:[ShowCompanyResponse class] completionBlockWithSuccess:^(NDBaseAPIResponse *response) {
        sucess((ShowCompanyResponse *)response);
    } Fail:^(NSString *returnCode, NSString *failDescript) {
        fail(returnCode,failDescript);
    }];
}


/**
 *  协议跟踪反馈新增/修改
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)feedbackUpdateByRequest:(FeedbackUpdateRequest *)request completionBlockWithSuccess:(void(^)(FeedbackUpdateResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail{
    [self request:request responseClass:[FeedbackUpdateResponse class] completionBlockWithSuccess:^(NDBaseAPIResponse *response) {
        sucess((FeedbackUpdateResponse *)response);
    } Fail:^(NSString *returnCode, NSString *failDescript) {
        fail(returnCode,failDescript);
    }];
}


/**
 *  协议跟踪反馈列表
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)getFeedBackListByRequest:(FeedBackListRequest *)request completionBlockWithSuccess:(void(^)(FeedBackListResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail{
    [self request:request responseClass:[FeedBackListResponse class] completionBlockWithSuccess:^(NDBaseAPIResponse *response) {
        sucess((FeedBackListResponse *)response);
    } Fail:^(NSString *returnCode, NSString *failDescript) {
        fail(returnCode,failDescript);
    }];
}

@end
