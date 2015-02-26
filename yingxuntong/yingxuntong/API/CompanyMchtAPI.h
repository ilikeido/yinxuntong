//
//  CompanyMchtAPI.h
//  yingxuntong
//
//  Created by ilikeido on 15-2-26.
//  Copyright (c) 2015年 ilikeido. All rights reserved.
//

#import "NDBaseAPI.h"
#import "CompanyMcht.h"

@interface CompanyMchtPage : NDBasePage

@end


/**
 *  5.5.1	商户分页查询（X）
 */
@interface CompanyMchtPageRequest : NDBaseAPIRequest

@property(nonatomic,strong) NSNumber *	queryOnlySelf	;//	是否只查询自己(通过权限判断，如果有此权限记录，则传)
@property(nonatomic,strong) NSNumber *	selfUserId	;//	同上
@property(nonatomic,strong) NSString *	likeOrgCode	;//
@property(nonatomic,strong) NSString *	likeDeptCode	;//
@property(nonatomic,strong) NSString *	mchtName	;//
@property(nonatomic,strong) NSString *	startDate	;//
@property(nonatomic,strong) NSString *	endDate	;//
@property(nonatomic,strong) NSString *	mchtCode	;//
@property(nonatomic,assign) int pageNum	;//	当前第几页
@property(nonatomic,assign) int	numPerPage	;//	判断是否独立查询权限，如果是，传1,,否则传默认的10

@end


@interface CompanyMchtPageResponse :NDBaseAPIResponse

@property(nonatomic,strong)CompanyMchtPage *page;//商户分页列表

@end


/**
 *  5.5.2	商户终端列表（X）
 */
@interface CompanyMchtTerminalRequest : NDBaseAPIRequest

@property(nonatomic,strong) NSNumber *	mchtCode	;//	商户号

@end

@interface CompanyMchtTerminalResponse : NDBaseAPIResponse

@property(nonatomic,strong) NSArray *	companymchtterminals	;//	商户终端列表

@end


/**
 *  5.5.3	商户终端装机历史(分页)
 */

@interface CompanyTerminalInfoPage : NDBasePage

@end

@interface CompanyTerminalInfoPageRequest : NDBaseAPIRequest

@property(nonatomic,strong) NSNumber *	mchtCode	;//	商户号

@end

@interface CompanyTerminalInfoPageResponse : NDBaseAPIResponse

@property(nonatomic,strong) CompanyTerminalInfoPage *	page	;//	终端分页查询

@end




@interface CompanyMchtAPI : NDBaseAPI

/**
 *  5.5.1	商户分页查询（X）
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)getCompanyMchtPageByRequest:(CompanyMchtPageRequest *)request completionBlockWithSuccess:(void(^)(CompanyMchtPageResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail;


/**
 *  5.5.2	商户终端列表（X）
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)getCompanyMchtTerminalByRequest:(CompanyMchtTerminalRequest *)request completionBlockWithSuccess:(void(^)(CompanyMchtTerminalResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail;


/**
 *  5.5.3	商户终端装机历史(分页)
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)getCompanyTerminalInfoPageByRequest:(CompanyTerminalInfoPageRequest *)request completionBlockWithSuccess:(void(^)(CompanyTerminalInfoPageResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail;

@end
