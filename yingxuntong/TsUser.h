//
//  TsUser.h
//  yingxuntong
//
//  Created by ilikeido on 15-2-11.
//  Copyright (c) 2015年 ilikeido. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  机构用户TsUser
 *
 */
@interface TsUser : NSObject

@property(nonatomic,assign) int userId	;	//	编号
@property(nonatomic,strong) NSString *	userName	;	//	用户名
@property(nonatomic,strong) NSString *	realName	;	//	真实姓名
@property(nonatomic,strong) NSString *	email	;	//	EMAIL
@property(nonatomic,strong) NSString *	address	;	//	地址
@property(nonatomic,strong) NSString *	phoneNum	;	//	联系电话
@property(nonatomic,assign) NSString *	sex	;	//	性别{1：男，0：女}
@property(nonatomic,strong) NSString *	memo	;	//	备注
@property(nonatomic,strong) NSString *	orgCode	;	//	组织机构编码
@property(nonatomic,strong) NSString *	provinceCode	;	//	省份
@property(nonatomic,strong) NSString *	cityCode	;	//	城市
@property(nonatomic,strong) NSString *	countyCode	;	//	区县

@end
