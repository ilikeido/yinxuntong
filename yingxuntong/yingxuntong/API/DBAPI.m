//
//  DBAPI.m
//  yingxuntong
//
//  Created by ilikeido on 15-2-11.
//  Copyright (c) 2015年 ilikeido. All rights reserved.
//

#import "DBAPI.h"

@implementation GetCompanyDBRequest

-(NSString *)method{
    return @"/syncdata/server2client";
}

@end

@implementation GetInstitutionDBRequest

-(NSString *)method{
    return @"/syncdata/server2client/institution";
}

@end

@implementation SqliteDBResponse

@end

@implementation DBAPI

/**
 *  Sqlite db下载（商户）
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)getCompanyDBByRequest:(GetCompanyDBRequest *)request completionBlockWithSuccess:(void(^)(SqliteDBResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail{
    [self request:request responseClass:[SqliteDBResponse class] completionBlockWithSuccess:^(NDBaseAPIResponse *response) {
        sucess((SqliteDBResponse *)response);
    } Fail:^(NSString *returnCode, NSString *failDescript) {
        fail(returnCode,failDescript);
    }];
}

/**
 *  Sqlite db下载（商户）
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)getInstitutionDBByRequest:(GetInstitutionDBRequest *)request completionBlockWithSuccess:(void(^)(SqliteDBResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail{
    [self request:request responseClass:[SqliteDBResponse class] completionBlockWithSuccess:^(NDBaseAPIResponse *response) {
        sucess((SqliteDBResponse *)response);
    } Fail:^(NSString *returnCode, NSString *failDescript) {
        fail(returnCode,failDescript);
    }];
}

@end
