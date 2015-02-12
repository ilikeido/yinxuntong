//
//  DBAPI.h
//  yingxuntong
//
//  Created by ilikeido on 15-2-11.
//  Copyright (c) 2015年 ilikeido. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NDBaseAPI.h"
#import "SqlitDB.h"
/**
 *  5.3.1	Sqlite db下载（商户）
 */
@interface GetCompanyDBRequest : NDBaseAPIRequest

@property(nonatomic,assign) int memberId;//登录用户编号

@property(nonatomic,assign) int enterpriseId;//所属企业编号

@property(nonatomic,assign) int syncType;//同步类型,1:自动，2：手动

@end

/**
 *  5.3.2	Sqlite db下载(机构)
 */
@interface GetInstitutionDBRequest: NDBaseAPIRequest

@property(nonatomic,assign) int userId;//登录用户编号

@property(nonatomic,assign) int syncType;//同步类型,1:自动，2：手动

@end


@interface SqliteDBResponse : NDBaseAPIResponse

@property(nonatomic,strong) SqlitDB *sqliteDb;//同步Db信息

@end

@interface DBAPI : NDBaseAPI

/**
 *  Sqlite db下载（商户）
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)getCompanyDBByRequest:(GetCompanyDBRequest *)request completionBlockWithSuccess:(void(^)(SqliteDBResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail;

/**
 *  Sqlite db下载（商户）
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)getInstitutionDBByRequest:(GetInstitutionDBRequest *)request completionBlockWithSuccess:(void(^)(SqliteDBResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail;


@end
