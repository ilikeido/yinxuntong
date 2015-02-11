//
//  CompanyMcht.h
//  yingxuntong
//
//  Created by ilikeido on 15-2-11.
//  Copyright (c) 2015年 ilikeido. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  商户
 *
 */
@interface CompanyMcht : NSObject

@property(nonatomic,assign) int	companyId	;	//	编号
@property(nonatomic,strong) NSString *	mchtName	;	//	商户名称
@property(nonatomic,strong) NSString *	orgCode	;	//	组织架构编码
@property(nonatomic,strong) NSString *	mchtCode	;	//	商户号
@property(nonatomic,strong) NSString *	agreementCode	;	//	协议编码
@property(nonatomic,strong) NSString *	agreementId	;	//	协议编号
@property(nonatomic,strong) NSString *	provinceId	;	//	省份
@property(nonatomic,strong) NSString *	cityId	;	//	城市
@property(nonatomic,strong) NSString *	countyId	;	//	区县
@property(nonatomic,strong) NSString *	legalManIdcard	;	//	法人身份证
@property(nonatomic,strong) NSString *	legalMan	;	//	法人
@property(nonatomic,strong) NSString *	settleAcctNo	;	//	委托代付划拨信息:银行账号
@property(nonatomic,strong) NSString *	settlementAcctName	;	//	商户结算户名
@property(nonatomic,strong) NSString *	depositBankName	;	//	开户行名称
@property(nonatomic,strong) NSString *	acquirer	;	//	结算行机构号
@property(nonatomic,strong) NSString *	settlementBankName	;	//	结算行名称
@property(nonatomic,strong) NSString *	telphone	;	//	电话
@property(nonatomic,strong) NSString *	address	;	//	地址
@property(nonatomic,strong) NSString *	institutionCode	;	//	所属机构号
@property(nonatomic,strong) NSString *	bankCode	;	//	联行号
@property(nonatomic,strong) NSString *	installState	;	//	装机状态
@property(nonatomic,strong) NSString *	addTime	;	//	添加时间(yyyy-MM-DD HH:mm:ss)
@property(nonatomic,strong) NSString *	settleDate	;	//	处理日期(yyyyMMdd)
@property(nonatomic,strong) NSString *	updateTime	;	//	更新时间(yyyy-MM-DD HH:mm:ss)
@property(nonatomic,strong) NSString *	memo	;	//	备注

@end
