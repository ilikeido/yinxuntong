//
//  CompanyTerminalInfo.h
//  yingxuntong
//
//  Created by ilikeido on 15-2-11.
//  Copyright (c) 2015年 ilikeido. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  终端历史
 *
 */
@interface CompanyTerminalInfo : NSObject

@property(nonatomic,assign) int mchtTerminalId	;	//	编号
@property(nonatomic,strong) NSString *	orgCode	;	//	组织机构编码
@property(nonatomic,strong) NSString *	mchtCode	;	//	商户号
@property(nonatomic,strong) NSString *	agreementCode	;	//	协议编码
@property(nonatomic,strong) NSString *	agreementId	;	//	协议编号
@property(nonatomic,strong) NSString *	termCode	;	//	终端号
@property(nonatomic,strong) NSString *	addTime	;	//	添加时间(yyyy-MM-DD HH:mm:ss)
@property(nonatomic,strong) NSString *	remark	;	//	备注
@property(nonatomic,strong) NSString *	provinceId	;	//	省份
@property(nonatomic,strong) NSString *	cityId	;	//	城市
@property(nonatomic,strong) NSString *	countyId	;	//	区县
@property(nonatomic,strong) NSString *	settleDate	;	//	处理日期(yyyyMMdd)
@property(nonatomic,strong) NSString *	bankCode	;	//	联行号
@property(nonatomic,strong) NSString *	mchtName	;	//	商户名称
@property(nonatomic,strong) NSString *	installState	;	//	装机状态

@end
