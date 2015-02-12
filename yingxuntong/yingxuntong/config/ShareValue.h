//
//  ShareValue.h
//  jiulifang
//
//  Created by hesh on 13-11-6.
//  Copyright (c) 2013年 ilikeido. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TsUser.h"

#define SYSTEM_VERSION 1.0

#define SYSTEM_DEVERLOPER 0

#define VERSION 1

#define TABLEVERION 1.1

@interface ShareValue : NSObject

+(ShareValue *)standardShareValue;

@property(nonatomic,strong) TsUser *user;

@property(nonatomic,assign) BOOL rememberPwd;

@property(nonatomic,readwrite) NSString *save_userName;

@property(nonatomic,readwrite) NSString *save_pwd;

@end
