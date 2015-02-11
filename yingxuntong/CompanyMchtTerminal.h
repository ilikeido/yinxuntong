//
//  CompanyMchtTerminal.h
//  yingxuntong
//
//  Created by ilikeido on 15-2-11.
//  Copyright (c) 2015年 ilikeido. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  商户终端
 *
 */
@interface CompanyMchtTerminal : NSObject

@property(nonatomic,assign) int	mchtTerminalId	;	//	编号
@property(nonatomic,strong) NSString *	orgCode	;	//	组织机构编码
@property(nonatomic,strong) NSString *	mchtCode	;	//	商户号
@property(nonatomic,strong) NSString *	agreementCode	;	//	协议编码
@property(nonatomic,strong) NSString *	agreementId	;	//	协议编号
@property(nonatomic,strong) NSString *	termCode	;	//	终端号
@property(nonatomic,strong) NSString *	addTime	;	//	添加时间(yyyy-MM-DD HH:mm:ss)
@property(nonatomic,strong) NSString *	remark	;	//	备注

@end
