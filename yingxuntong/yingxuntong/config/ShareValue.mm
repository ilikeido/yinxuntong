//
//  ShareValue.m
//  jiulifang
//
//  Created by hesh on 13-11-6.
//  Copyright (c) 2013年 ilikeido. All rights reserved.
//

#import "ShareValue.h"

#define KEY_REMEMBERPWD @"KEY_REMEMBERPWD"
#define KEY_SAVEUSERNAME @"KEY_SAVEUSERNAME"
#define KEY_SAVEPWD @"KEY_SAVEPWD"

static ShareValue *_shareValue;


@interface ShareValue ()


@end

@implementation ShareValue

+(ShareValue *)standardShareValue;{
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _shareValue = [[ShareValue alloc]init];
    });
    return _shareValue;
}

-(void)setRememberPwd:(BOOL)rememberPwd{
    [[NSUserDefaults standardUserDefaults]setBool:rememberPwd forKey:KEY_REMEMBERPWD];
}

-(BOOL)rememberPwd{
    return [[NSUserDefaults standardUserDefaults]boolForKey:KEY_REMEMBERPWD];
}

-(void)setSave_pwd:(NSString *)save_pwd{
    [[NSUserDefaults standardUserDefaults]setObject:save_pwd forKey:KEY_SAVEPWD];
}

-(NSString *)save_pwd{
    return [[NSUserDefaults standardUserDefaults]stringForKey:KEY_SAVEPWD];
}

-(void)setSave_userName:(NSString *)save_userName{
    [[NSUserDefaults standardUserDefaults]setObject:save_userName forKey:KEY_SAVEUSERNAME];
}

-(NSString *)save_userName{
    return [[NSUserDefaults standardUserDefaults]stringForKey:KEY_SAVEUSERNAME];
}



@end
