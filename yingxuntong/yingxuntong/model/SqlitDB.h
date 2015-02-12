//
//  SqlitDB.h
//  yingxuntong
//
//  Created by ilikeido on 15-2-11.
//  Copyright (c) 2015年 ilikeido. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  同步DB信息
 *
 */
@interface SqlitDB : NSObject

@property(nonatomic,assign) int sqliteDbId;//编号
@property(nonatomic,assign) int enterpriseId;//用户编号
@property(nonatomic,strong) NSString * baseUrl;//http访问前缀
@property(nonatomic,strong) NSString * dbFile;//数据文件
@property(nonatomic,strong) NSString * updateTime;//修改时间 yyyy-MM-dd HH:mm:ss

@end
