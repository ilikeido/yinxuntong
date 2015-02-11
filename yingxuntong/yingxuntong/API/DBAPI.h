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

@interface GetCompanyDBRequest : NDBaseAPIRequest

@property(nonatomic,assign) int memberId;//登录用户编号

@property(nonatomic,assign) int enterpriseId;//所属企业编号

@property(nonatomic,assign) int syncType;//同步类型,1:自动，2：手动

@end

@interface GetInstitutionDBRequest: NDBaseAPIRequest

@property(nonatomic,assign) int userId;//登录用户编号

@property(nonatomic,assign) int syncType;//同步类型,1:自动，2：手动

@end

@interface SqliteDBResponse : NDBaseAPIResponse

@property(nonatomic,strong) SqlitDB *sqliteDb;//同步Db信息

@end

@interface DBAPI : NDBaseAPI



@end
