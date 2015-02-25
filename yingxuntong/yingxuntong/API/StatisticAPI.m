//
//  StatisticAPI.m
//  yingxuntong
//
//  Created by ilikeido on 15-2-25.
//  Copyright (c) 2015年 ilikeido. All rights reserved.
//

#import "StatisticAPI.h"

@implementation InstallStateCount

@end

@implementation InstallStateCountRequest

-(NSString *)method{
    return @"/statistic/company/install/area";
}

@end


@implementation InstallStateCountResponse

+(Class)__statisticsClass{
    return [InstallStateCount class];
}

@end


@implementation CompanyState

@end

@implementation CompanyStateRequest

-(NSString *)method{
    return @"/statistic/company/num";
}

@end


@implementation CompanyStateResponse

+(Class)__statisticsClass{
    return [CompanyState class];
}

@end

@implementation CompanyMchtNumber

@end

@implementation CompanyMchtNumberRequest

-(NSString *)method{
    return @"/statistic/mcht/num";
}

@end


@implementation CompanyMchtNumberResponse

+(Class)__statisticsClass{
    return [CompanyMchtNumber class];
}

@end


@implementation CompanyMchtGrade

@end

@implementation CompanyMchtGradeRequest

-(NSString *)method{
    return @"/statistic/mcht/grade";
}

@end


@implementation CompanyMchtGradeResponse

+(Class)__statisticsClass{
    return [CompanyMchtGrade class];
}

@end


@implementation CompanyMchtActive

@end

@implementation CompanyMchtActiveRequest

-(NSString *)method{
    return @"/statistic/mcht/active";
}

@end


@implementation CompanyMchtActiveResponse

+(Class)__statisticsClass{
    return [CompanyMchtActive class];
}

@end

