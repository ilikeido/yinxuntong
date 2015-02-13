//
//  MenuCell.m
//  yingxuntong
//
//  Created by ilikeido on 15-2-12.
//  Copyright (c) 2015年 ilikeido. All rights reserved.
//

#import "MenuCell.h"

@implementation MenuCell

- (void)awakeFromNib {
    // Initialization code
}

-(void)setImageName:(NSString *)imageName{
    _imageName = imageName;
    [self.imageView setImage:[UIImage imageNamed:imageName]];
}

-(void)setTitle:(NSString *)title{
    _title = title;
    [self.lable setText:title];
}

@end
