//
//  Version.h
//  yingxuntong
//
//  Created by ilikeido on 15-2-11.
//  Copyright (c) 2015年 ilikeido. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  编号
 */
@interface Version : NSObject

@property(nonatomic,strong) NSString *	versionId	;	//	编号
@property(nonatomic,assign) int	enterpriseId	;	//	企业编号
@property(nonatomic,strong) NSString *	versionName	;	//	版本名称
@property(nonatomic,strong) NSString *	version	;	//	版本号
@property(nonatomic,strong) NSString *	keyName	;	//	获取版本识别码
@property(nonatomic,strong) NSString *	memo	;	//	备注
@property(nonatomic,strong) NSString *	filePath	;	//	升级地址

@end
