//
//  UserAPI.m
//  yingxuntong
//
//  Created by ilikeido on 15-2-11.
//  Copyright (c) 2015年 ilikeido. All rights reserved.
//
#import "UserAPI.h"

@implementation LoginRequest

-(NSString *)method{
    return @"/login";
}

@end

@implementation LoginResponse

@end

@implementation PosLoginRequest

-(NSString *)method{
    return @"/poslogin";
}

@end

@implementation PosLogin2Request

-(NSString *)method{
    return @"/poslogin2";
}

@end

@implementation PosLogin2Response

@end

@implementation RestPwdRequest

-(NSString *)method{
    return @"/tsuser/restpwd/update";
}

@end

@implementation RestPwdResponse

@end

@implementation MemberListRequest

-(NSString *)method{
    return @"/member/list";
}

@end

@implementation MemberListResponse

+(Class)__membersClass{
    return [Member class];
}

@end



@implementation UserAPI

@end
