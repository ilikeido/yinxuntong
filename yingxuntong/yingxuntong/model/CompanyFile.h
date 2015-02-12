//
//  CompanyFile.h
//  yingxuntong
//
//  Created by ilikeido on 15-2-11.
//  Copyright (c) 2015年 ilikeido. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  协议文件
 *
 */
@interface CompanyFile : NSObject

@property(nonatomic,assign) int	companyFileId	;	//	编号
@property(nonatomic,strong) NSString *	orgCode	;	//	组织机构编码
@property(nonatomic,assign) int	companyId	;	//	协议companyId
@property(nonatomic,strong) NSString *	fileName	;	//	文件名
@property(nonatomic,strong) NSString *	baseUrl	;	//	RUL前缀
@property(nonatomic,strong) NSString *	thumbUrl	;	//	缩略图，访问时：baseUrl+ thumbUrl
@property(nonatomic,strong) NSString *	fileUrl	;	//	原图，访问时：baseUrl+ fileUrl
@property(nonatomic,strong) NSString *	credentialType	;	//	协议父类型编号
@property(nonatomic,strong) NSString *	credentialSubType	;	//	协议子类型编号
@property(nonatomic,strong) NSString *	addTime	;	//	添加时间（yyyy-MM-dd HH:mm:ss）
@property(nonatomic,strong) NSString *	imgBase64	;	//	图片转化为base64的字符串

@end
