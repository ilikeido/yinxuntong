//
//  ShareValue.m
//  jiulifang
//
//  Created by hesh on 13-11-6.
//  Copyright (c) 2013年 ilikeido. All rights reserved.
//

#import "ShareValue.h"

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


@end
