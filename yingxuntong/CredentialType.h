//
//  CredentialType.h
//  yingxuntong
//
//  Created by ilikeido on 15-2-11.
//  Copyright (c) 2015年 ilikeido. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CompanyFile.h"

/**
 *  协议类型
 *
 */
@interface CredentialType : NSObject

@property(nonatomic,assign) int	typeCode	;	//	类型编码
@property(nonatomic,strong) NSString *	typeName	;	//	类型名称
@property(nonatomic,strong) NSString *	parentCode	;	//	父级编码
@property(nonatomic,strong) NSString *	orderNum	;	//	排序号
@property(nonatomic,strong) NSString *	isNecessary	;	//	是否必须{1:是，0:否}
@property(nonatomic,strong) NSArray *	credentialSubTypes	;	//	子类型列表
@property(nonatomic,strong) CompanyFile *	companyFile	;	//	类型对应文件

@end
