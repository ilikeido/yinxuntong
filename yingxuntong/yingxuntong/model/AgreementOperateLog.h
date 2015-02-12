//
//  AgreementOperateLog.h
//  yingxuntong
//
//  Created by ilikeido on 15-2-11.
//  Copyright (c) 2015年 ilikeido. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  审核历史
 *
 */
@interface AgreementOperateLog : NSObject

@property(nonatomic,assign) int	id	;	//	编号
@property(nonatomic,strong) NSString *	operateTypeName	;	//	操作类型名
@property(nonatomic,assign) int	operaterType	;	//	操作类型
@property(nonatomic,strong) NSString *	operater	;	//	操作人
@property(nonatomic,strong) NSString *	agreementId	;	//	协议编号
@property(nonatomic,strong) NSString *	endTime	;	//	开始时间
@property(nonatomic,strong) NSString *	startTime	;	//	结束时间
@property(nonatomic,strong) NSString *	remark	;	//	备注

@end
