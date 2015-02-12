//
//  CompanyFeedback.h
//  yingxuntong
//
//  Created by ilikeido on 15-2-11.
//  Copyright (c) 2015年 ilikeido. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  协议跟踪反馈
 *
 */
@interface CompanyFeedback : NSObject

@property(nonatomic,assign) int companyFeedbackId	;	//	编号
@property(nonatomic,assign) int	userId	;	//	用户编号
@property(nonatomic,strong) NSString *	realName	;	//	真实姓名
@property(nonatomic,strong) NSString *	companyId	;	//	协议编号
@property(nonatomic,strong) NSString *	content	;	//	反馈内容
@property(nonatomic,strong) NSString *	addTime	;	//	添加时间（yyyy-MM-dd HH:mm:ss）
@property(nonatomic,strong) NSString *	feedbackType	;	//	类型, 来自字典（字典类型typeKey= COMPANY_FEEDBACK_TYP）

@end
