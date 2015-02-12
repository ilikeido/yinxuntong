//
//  SysUser.h
//  yingxuntong
//
//  Created by ilikeido on 15-2-11.
//  Copyright (c) 2015年 ilikeido. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  系统用户
 *
 */
@interface SysUser : NSObject

@property(nonatomic,assign) int userId	;	//	用户编号
@property(nonatomic,strong) NSString *	userName	;	//	账号
@property(nonatomic,strong) NSString *	realName	;	//	真实姓名
@property(nonatomic,strong) NSString *	phoneNum	;	//	联系电话
@property(nonatomic,strong) NSString *	orgCode	;	//	所属银行机构编号
@property(nonatomic,strong) NSString *	deptCode	;	//	所属部门编码
@property(nonatomic,assign) int	userType	;	//	用户类型(1:银讯用户:银行用户,3代理用户)
@property(nonatomic,strong) NSString *	provinceCode	;	//	省份编号
@property(nonatomic,strong) NSString *	cityCode	;	//	城市编号
@property(nonatomic,strong) NSString *	countyCode	;	//	区县编号
@property(nonatomic,strong) NSString *	email	;	//	EMAIL
@property(nonatomic,strong) NSString *	address	;	//	地址
@property(nonatomic,assign) int	sex	;	//	性别(1:男,2:女)
@property(nonatomic,strong) NSString *	memo	;	//	备注
@property(nonatomic,strong) NSString *	dataPrivileges	;	//	数据权限，多个用英文逗号分隔{101:用户信息,102:协议信息,103:商户信息}

@end
