//
//  Member.h
//  yingxuntong
//
//  Created by ilikeido on 15-2-11.
//  Copyright (c) 2015年 ilikeido. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  商务用户
 *
 */
@interface Member : NSObject

@property(nonatomic,assign) int  memberId	;	//	用户编号
@property(nonatomic,assign) int  enterpriseId	;	//	企业编号
@property(nonatomic,strong) NSString *	memberName	;	//	账号
@property(nonatomic,strong) NSString *	realName	;	//	真实姓名
@property(nonatomic,strong) NSString *	phoneNum	;	//	联系电话
@property(nonatomic,strong) NSString *	orgCode	;	//	所属组织架构编号
@property(nonatomic,assign) int  isMobileUser	;	//	是否手机用户(1:是,0:否)
@property(nonatomic,strong) NSString *	email	;	//	EMAIL
@property(nonatomic,strong) NSString *	address	;	//	地址
@property(nonatomic,strong) NSString *	sex	;	//	性别(1:男,2:女)
@property(nonatomic,strong) NSString *	memo	;	//	备注
@property(nonatomic,assign) int  msgNotViewCount	;	//	未读消息数
@property(nonatomic,strong) NSString *	visitSeq	;	//	拜访序列号

@end
