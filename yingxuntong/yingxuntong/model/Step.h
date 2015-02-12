//
//  Step.h
//  yingxuntong
//
//  Created by ilikeido on 15-2-11.
//  Copyright (c) 2015年 ilikeido. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  操作步骤
 *
 */
@interface Step : NSObject

@property(nonatomic,assign) int stepId;//编号
@property(nonatomic,strong) NSString *stepName;//步骤名称
@property(nonatomic,strong) NSString *stepCode;//步骤代码
@property(nonatomic,strong) NSString *editFlag;//编辑标志

@end
