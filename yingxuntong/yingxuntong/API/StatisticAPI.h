//
//  StatisticAPI.h
//  yingxuntong
//
//  Created by ilikeido on 15-2-25.
//  Copyright (c) 2015年 ilikeido. All rights reserved.
//

#import "NDBaseAPI.h"

/**
 *  装机状态统计
 */
@interface InstallStateCount : NSObject

@property(nonatomic,strong) NSString *name;

@property(nonatomic,assign) int count;

@end

/**
 *  5.6.1	装机状态统计
 */
@interface InstallStateCountRequest : NDBaseAPIRequest

@property(nonatomic,strong) NSString *orgCode;

@end

@interface InstallStateCountResponse : NDBaseAPIResponse

@property(nonatomic,strong) NSArray *statistics;

@end

//协议状态
@interface CompanyState : NSObject

@property(nonatomic,strong) NSString*	org_code	;//	机构编号
@property(nonatomic,strong) NSString*	org_name	;//	机构名称
@property(nonatomic,strong) NSString*	total_count	;//	协议总数
@property(nonatomic,strong) NSString*	receive	;//	提交审核数
@property(nonatomic,strong) NSString*	checking	;//	审核中数
@property(nonatomic,strong) NSString*	pass	;//	审核通过数
@property(nonatomic,strong) NSString*	destroy	;//	作废数

@end

/**
 *  5.6.2	协议状态统计
 */
@interface CompanyStateRequest : NDBaseAPIRequest

@property(nonatomic,strong) NSString *orgCode;//组织机构编码(要统计的)

@property(nonatomic,strong) NSString *showType;//统计方式{ 不为空时，输出各列列表数据}

@end

@interface CompanyStateResponse : NDBaseAPIResponse

@property(nonatomic,strong) NSArray * nameList	;//	机构名称列表(showType不为空时)
@property(nonatomic,strong) NSArray * receiveCountList	;//	提交审核数量列表(showType不为空时)
@property(nonatomic,strong) NSArray * checkingCountList	;//	审核中数量列表(showType不为空时)
@property(nonatomic,strong) NSArray * passCountList	;//	审核通过数量列表(showType不为空时)
@property(nonatomic,strong) NSArray * destroyCountList;//	作废数量列表(showType不为空时)
@property(nonatomic,strong) NSArray * totalCountList;//	总数列表(showType不为空时)
@property(nonatomic,strong) CompanyState *	conditionTotal	;//	条件统计结果
@property(nonatomic,strong) NSArray *	statistics	;//	列表统计结果

@end

//商户数量
@interface CompanyMchtNumber : NSObject

@property(nonatomic,strong) NSString*	org_name	;//	机构名称
@property(nonatomic,strong) NSString*	mcht_count	;//	商户总数
@property(nonatomic,strong) NSString*	total_count	;//	终端总数
@property(nonatomic,strong) NSString*	noinstall	;//	未安装数
@property(nonatomic,strong) NSString*	installed	;//	已安装数

@end

/**
 *  5.6.3	商户数量统计
 */
@interface CompanyMchtNumberRequest : NDBaseAPIRequest

@property(nonatomic,strong) NSString*	orgCode	;//	组织机构编码(要统计的)
@property(nonatomic,strong) NSString*	showType	;//	统计方式{ 不为空时，输出各列列表数据}

@end

@interface CompanyMchtNumberResponse : NDBaseAPIResponse

@property(nonatomic,strong) NSArray*	nameList	;//	机构名称列表(showType不为空时)
@property(nonatomic,strong) NSArray*	mchtCountList	;//	提交审核数量列表(showType不为空时)
@property(nonatomic,strong) NSArray*	installedCountList	;//	装机数量列表(showType不为空时)
@property(nonatomic,strong) NSArray*	unInstallCountList	;//	未装机数量列表(showType不为空时)
@property(nonatomic,strong) NSArray*	destroyCountList	;//	撤机数量列表(showType不为空时)
@property(nonatomic,strong) NSArray*	totalCountList	;//	终端数量列表(showType不为空时)
@property(nonatomic,strong) CompanyMchtNumber*	conditionTotal	;//	条件统计结果
@property(nonatomic,strong) NSArray*	statistics	;//	列表统计结果

@end


//商户等级
@interface CompanyMchtGrade : NSObject

@property(nonatomic,strong) NSString*	org_name	;//	机构名称
@property(nonatomic,strong) NSString*	total_count	;//	商户总数
@property(nonatomic,strong) NSString*	gradeTop	;//	一类商户数
@property(nonatomic,strong) NSString*	gradeMid	;//	二类商户数
@property(nonatomic,strong) NSString*	gradeLow	;//	三类商户数

@end



/**
 *  5.6.4	商户等级统计
 */
@interface CompanyMchtGradeRequest : NDBaseAPIRequest

@property(nonatomic,strong) NSString*	orgCode	;//	组织机构编码(要统计的)
@property(nonatomic,strong) NSString*	showType	;//	统计方式{ 不为空时，输出各列列表数据}

@end

@interface CompanyMchtGradeResponse : NDBaseAPIResponse

@property(nonatomic,strong) NSArray*	nameList	;//	机构名称列表(showType不为空时)
@property(nonatomic,strong) NSArray*	mchtCountList	;//	商户数量列表(showType不为空时)
@property(nonatomic,strong) NSArray*	topList	;//	一类数量列表(showType不为空时)
@property(nonatomic,strong) NSArray*	gradeMidList	;//	二类数量列表(showType不为空时)
@property(nonatomic,strong) NSArray*	gradeLowList	;//	三类数量列表(showType不为空时)
@property(nonatomic,strong) NSArray*	statistics	;//	列表统计结果

@end


//商户活跃度
@interface CompanyMchtActive : NSObject

@property(nonatomic,strong) NSString*	org_name	;//	机构名称
@property(nonatomic,strong) NSString*	total_count	;//	商户总数
@property(nonatomic,strong) NSString*	gradeTop	;//	活跃商户数
@property(nonatomic,strong) NSString*	gradeMid	;//	普通商户数
@property(nonatomic,strong) NSString*	gradeLow	;//	低活跃商户数
@property(nonatomic,strong) NSString*	gradeSleep	;//	睡眠商户数

@end

/**
 *  5.6.5	商户活跃度统计
 */
@interface CompanyMchtActiveRequest : NDBaseAPIRequest

@property(nonatomic,strong) NSString*	orgCode	;//	组织机构编码(要统计的)
@property(nonatomic,strong) NSString*	showType	;//	统计方式{ 不为空时，输出各列列表数据}

@end

@interface CompanyMchtActiveResponse : NDBaseAPIResponse

@property(nonatomic,strong) NSArray*	nameList	;//	机构名称列表(showType不为空时)
@property(nonatomic,strong) NSArray*	mchtCountList	;//	商户数量列表(showType不为空时)
@property(nonatomic,strong) NSArray*	topList	;//	活跃商户数量列表(showType不为空时)
@property(nonatomic,strong) NSArray*	gradeMidList	;//	普通商户数列表(showType不为空时)
@property(nonatomic,strong) NSArray*	gradeLowList	;//	低活跃商户数列表(showType不为空时)
@property(nonatomic,strong) NSArray*	gradeSleepList	;//	睡眠商户数列表(showType不为空时)
@property(nonatomic,strong) NSArray*	statistics	;//	列表统计结果

@end


/**
 *  机构交易
 */
@interface OrgTransaction : NSObject

@property(nonatomic,strong) NSString*	mchtNum	;//	商户数
@property(nonatomic,strong) NSString*	termNum	;//	终端数
@property(nonatomic,strong) NSString*	num	;//	交易笔数
@property(nonatomic,strong) NSString*	amout	;//	交易金额
@property(nonatomic,strong) NSString*	perNum	;//	客单价

@end

@interface OrgTransactionPage : NDBasePage

@end


/**
 *  5.6.6	机构交易统计(分页)
 */
@interface OrgTransactionRequest : NDBaseAPIRequest

@property(nonatomic,strong) NSString* likeOrgCode	;//	组织机构编码(要统计的)
@property(nonatomic,strong) NSString* startDate	;//	开始时间（yyyyMMdd）,默认当前月的第一天
@property(nonatomic,strong) NSString* endDate	;//	结束时间（yyyyMMdd），默认当天
@property(nonatomic,assign) int numPerPage	;//	每页显示几条，默认50
@property(nonatomic,assign) int pageNum;//	当前第几页

@end

@interface OrgTransactionResponse : NDBaseAPIResponse

@property(nonatomic,strong) OrgTransactionPage *page;

@end


/**
 *  总交易数据
 */
@interface TotalStatisticData : NSObject

@property(nonatomic,strong) NSString *totalNum;//总交易笔数
@property(nonatomic,strong) NSString *totalAmout;//总交易金额
@property(nonatomic,strong) NSString *totalPerNum;//总客单价

@end

/**
 *  终端交易数据
 */
@interface TerminalStatisticData : NSObject

@property(nonatomic,strong) NSString *	mchtName	;//商户名称
@property(nonatomic,strong) NSString *	mchtCode	;//	商户号
@property(nonatomic,strong) NSString *	termCode	;//	终端号
@property(nonatomic,strong) NSString *	mchtNum	;//	商户数
@property(nonatomic,strong) NSString *	termNum	;//	终端数
@property(nonatomic,strong) NSString *	num	;//	交易笔数
@property(nonatomic,strong) NSString *	amout	;//	交易金额
@property(nonatomic,strong) NSString *	perNum	;//	客单价

@end

@interface TerminalStatisticPage : NDBasePage

@end


/**
 *  5.6.7	终端交易统计(分页)
 */
@interface TerminalStatisticRequest : NDBaseAPIRequest

@property(nonatomic,strong) NSString *	likeOrgCode	;//	组织机构编码(要统计的)
@property(nonatomic,strong) NSString *	mchtName	;//	商户名称
@property(nonatomic,strong) NSString *	mchtCode	;//	商户号
@property(nonatomic,strong) NSString *	termCode	;//	终端号
@property(nonatomic,strong) NSString *	startDate	;//	开始时间（yyyyMMdd）,默认当前月的第一天
@property(nonatomic,strong) NSString *	endDate	;//	结束时间（yyyyMMdd），默认当天
@property(nonatomic,strong) NSString *	numPerPage	;//	每页显示几条，默认20
@property(nonatomic,strong) NSString *	pageNum	;//	当前第几页

@end


@interface TerminalStatisticResponse : NDBaseAPIResponse

@property(nonatomic,strong) TerminalStatisticPage *page;//统计结果
@property(nonatomic,strong) TotalStatisticData *tatalMap;//条件结果总计

@end

/**
 *  终端日交易数据
 */
@interface DayTerminalStatisticData : TerminalStatisticData

@property(nonatomic,strong)NSString *settleDate;

@end

/**
 *  终端日交易分页数据
 */
@interface DayTerminalStatisticPage : NDBasePage

@end

/**
 *  5.6.8	终端交易明细（分页）
 */
@interface DayTerminalStatisticRequest: NDBaseAPIRequest

@property(nonatomic,strong) NSString *	orgCode	;//	组织机构编码(要统计的)
@property(nonatomic,strong) NSString *	mchtName	;//	商户名称
@property(nonatomic,strong) NSString *	mchtCode	;//	商户号
@property(nonatomic,strong) NSString *	termCode	;//	终端号
@property(nonatomic,strong) NSString *	startDate	;//	开始时间（yyyyMMdd）,默认当前月的第一天
@property(nonatomic,strong) NSString *	endDate	;//	结束时间（yyyyMMdd），默认当天
@property(nonatomic,strong) NSString *	numPerPage	;//	每页显示几条，默认20
@property(nonatomic,strong) NSString *	pageNum	;//	当前第几页

@end

@interface DayTerminalStatisticResponse : NDBaseAPIResponse

@property(nonatomic,strong) DayTerminalStatisticPage *page;//统计结果
@property(nonatomic,strong) TotalStatisticData *tatalMap;//条件结果总计

@end


/**
 *  商户交易统计数据
 */
@interface  CompanyMchtStatisticData : NSObject

@property(nonatomic,strong) NSString *	mchtName	;//	商户名称
@property(nonatomic,strong) NSString *	mchtCode	;//	商户号
@property(nonatomic,strong) NSString *	mchtNum	;//	商户数
@property(nonatomic,strong) NSString *	termCount	;//	终端数
@property(nonatomic,strong) NSString *	num	;//	交易笔数
@property(nonatomic,strong) NSString *	amout	;//	交易金额
@property(nonatomic,strong) NSString *	perNum	;//	客单价

@end

@interface CompanyMchtStatisticPage : NDBasePage

@end

/**
 *  5.6.9	商户交易统计(分页)
 */
@interface CompanyMchtStatisticRequest : NDBaseAPIRequest

@property(nonatomic,strong) NSString *	likeOrgCode	;//	组织机构编码(要统计的)
@property(nonatomic,strong) NSString *	mchtName	;//	商户名称
@property(nonatomic,strong) NSString *	mchtCode	;//	商户号
@property(nonatomic,strong) NSString *	mchtLevel	;//	商户等级{0：所有，1：一级，2:二级，3：三级,4:睡眠商户}
@property(nonatomic,strong) NSString *	startDate	;//	开始时间（yyyyMMdd）,默认当前月的第一天
@property(nonatomic,strong) NSString *	endDate	;//	结束时间（yyyyMMdd），默认当天
@property(nonatomic,strong) NSString *	numPerPage	;//	每页显示几条，默认20
@property(nonatomic,strong) NSString *	pageNum	;//	当前第几页

@end


@interface CompanyMchtStatisticResponse : NDBaseAPIResponse

@property(nonatomic,strong) CompanyMchtStatisticPage *page;//统计结果
@property(nonatomic,strong) TotalStatisticData *tatalMap;//条件结果总计

@end


/**
 *  商户日交易明细
 */
@interface DayCompanyMchtStatisticData : CompanyMchtStatisticData

@property(nonatomic,strong) NSString *	settleDate	;//	交易日期（yyyyMMdd）

@end

@interface DayCompanyMchtStatisticPage : NDBasePage

@end

/**
 *  5.6.10	商户交易明细 (分页)
 */
@interface DayCompanyMchtStatisticRequest : NDBaseAPIRequest

@property(nonatomic,strong) NSString *	mchtCode	;//	商户号
@property(nonatomic,strong) NSString *	startDate	;//	开始时间（yyyyMMdd）,默认当前月的第一天
@property(nonatomic,strong) NSString *	endDate	;//	结束时间（yyyyMMdd），默认当天
@property(nonatomic,strong) NSString *	numPerPage	;//	每页显示几条，默认20
@property(nonatomic,strong) NSString *	pageNum	;//	当前第几页

@end

@interface DayCompanyMchtStatisticResponse : NDBaseAPIResponse

@property(nonatomic,strong) DayCompanyMchtStatisticPage *page;

@end

@interface LoginStatistcData : NSObject

@property(nonatomic,strong) NSString * realName;//用户名称
@property(nonatomic,strong) NSString * sex;//性别（男，女）
@property(nonatomic,strong) NSString * address;//地址
@property(nonatomic,strong) NSString * loginNum;//登录次数

@end

@interface LoginStatistcPage : NDBasePage

@end

/**
 *  5.6.11	用户登录情况统计 (分页)
 */
@interface LoginStatistcRequest : NDBaseAPIRequest

@property(nonatomic,assign) int userType	;//	用户类型，来自登录用户
@property(nonatomic,strong) NSString * 	likeOrgCode	;//	条件机构编码(默认来自登录用户)
@property(nonatomic,strong) NSString * 	likeDeptCode	;//	条件部门编码(默认来自登录用户)
@property(nonatomic,strong) NSString * 	realName	;//	用户名，模糊匹配
@property(nonatomic,strong) NSString * 	startDate	;//	开始时间（yyyyMMdd）,默认当前月的第一天
@property(nonatomic,strong) NSString * 	endDate	;//	开始时间（yyyyMMdd）,默认当前月的第一天
@property(nonatomic,strong) NSString * 	noLogin	;//	是否查询未登录用户，{1：是，0：否}
@property(nonatomic,assign) int 	numPerPage	;//	每页显示几条，默认10
@property(nonatomic,assign) int 	pageNum	;//	当前第几页

@end

@interface LoginStatistcResponse : NDBaseAPIResponse

@property(nonatomic,strong) LoginStatistcPage *page;

@end

@interface StatisticAPI : NDBaseAPI

/**
 *  5.6.1	装机状态统计
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)getInstallStateCountByRequest:(InstallStateCountRequest *)request completionBlockWithSuccess:(void(^)(InstallStateCountResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail;

/**
 *  5.6.2	协议状态统计
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)getCompanyStateByRequest:(CompanyStateRequest *)request completionBlockWithSuccess:(void(^)(CompanyStateResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail;

/**
 *  5.6.3	商户数量统计
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)getCompanyMchtNumberByRequest:(CompanyMchtNumberRequest *)request completionBlockWithSuccess:(void(^)(CompanyMchtNumberResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail;

/**
 *  5.6.4	商户等级统计
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)getCompanyMchtGradeByRequest:(CompanyMchtGradeRequest *)request completionBlockWithSuccess:(void(^)(CompanyMchtGradeResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail;

/**
 *  5.6.5	商户活跃度统计
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)getCompanyMchtActiveByRequest:(CompanyMchtActiveRequest *)request completionBlockWithSuccess:(void(^)(CompanyMchtActiveResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail;

/**
 *  5.6.6	机构交易统计(分页)
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)getOrgTransactionPageByRequest:(OrgTransactionRequest *)request completionBlockWithSuccess:(void(^)(OrgTransactionResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail;

/**
 *  5.6.7	终端交易统计(分页)
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)getTerminalStatisticPageByRequest:(TerminalStatisticRequest *)request completionBlockWithSuccess:(void(^)(TerminalStatisticResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail;

/**
 *  5.6.8	终端交易明细（分页）
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)getDayTerminalStatisticPageByRequest:(DayTerminalStatisticRequest *)request completionBlockWithSuccess:(void(^)(DayTerminalStatisticResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail;


/**
 *  5.6.9	商户交易统计(分页)
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)getCompanyMchtStatisticPageByRequest:(CompanyMchtStatisticRequest *)request completionBlockWithSuccess:(void(^)(CompanyMchtStatisticResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail;


/**
 *  5.6.10	商户交易明细 (分页)
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)getDayCompanyMchtStatisticPageByRequest:(DayCompanyMchtStatisticRequest *)request completionBlockWithSuccess:(void(^)(DayCompanyMchtStatisticResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail;

/**
 *  5.6.11	用户登录情况统计 (分页)
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)getLoginStatistcPageByRequest:(LoginStatistcRequest *)request completionBlockWithSuccess:(void(^)(LoginStatistcResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail;


@end
