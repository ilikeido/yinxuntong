//
//  SystemAPI.h
//  yingxuntong
//
//  Created by ilikeido on 15-2-11.
//  Copyright (c) 2015年 ilikeido. All rights reserved.
//

#import "NDBaseAPI.h"

@interface GetCurrentDateTimeRequest : NDBaseAPIRequest

@end

@interface GetCurrentDateTimeResponse : NDBaseAPIResponse

@property(nonatomic,strong) NSString *currentDateTime;

@end

@interface SystemAPI : NDBaseAPI

@end
