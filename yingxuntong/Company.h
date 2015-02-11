//
//  Company.h
//  yingxuntong
//
//  Created by ilikeido on 15-2-11.
//  Copyright (c) 2015年 ilikeido. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  协议
 *
 */
@interface Company : NSObject

@property(nonatomic,assign) int	companyId	;//	编号
@property(nonatomic,strong) NSString *	agreementCode	;//	协议编码
@property(nonatomic,assign) int	userId	;//	申请用户编号
@property(nonatomic,assign) int	orgCode	;//	组织架构编码
@property(nonatomic,strong) NSString *	regName	;//	用户编号
@property(nonatomic,strong) NSString *	regAddress	;//	地址
@property(nonatomic,strong) NSString *	currentFlowStep	;//	当前步骤
@property(nonatomic,strong) NSString *	provinceId	;//	省份
@property(nonatomic,strong) NSString *	cityId	;//	城市
@property(nonatomic,strong) NSString *	countyId	;//	区县
@property(nonatomic,assign) int currentOperatorId	;//	当前操作人
@property(nonatomic,strong) NSString *	draftFlag	;//	http基址
@property(nonatomic,strong) NSString *	agreementStatus	;//	协议状态码
@property(nonatomic,strong) NSString *	agreementId	;//	协议编号(银联自增编号)
@property(nonatomic,strong) NSString *	developTypeIds	;//	协议来源id
@property(nonatomic,strong) NSString *	otherRemark	;//	银联备注
@property(nonatomic,strong) NSString *	developTypeId	;//	申请类型
@property(nonatomic,strong) NSString *	developAvenues	;//	拓展渠道机构号
@property(nonatomic,strong) NSString *	settlementAcctName	;//	商户结算户名
@property(nonatomic,strong) NSString *	contactPerson	;//	商户联系人
@property(nonatomic,strong) NSString *	mccCode	;//	MCC代码
@property(nonatomic,strong) NSString *	agreementApplyType	;//	协议类型id
@property(nonatomic,strong) NSString *	settlementAcctNo
;//	商户结算账号
@property(nonatomic,strong) NSString *	mchtDistrict	;//	商户区域
@property(nonatomic,strong) NSString *	developDistrict	;//	拓展区域
@property(nonatomic,strong) NSString *	bookInDate	;//	生成日期（yyyyMMdd）
@property(nonatomic,strong) NSString *	updateStateTime	;//	协议状态更新日期（yyyy-MM-dd HH:mm:ss）

@end
