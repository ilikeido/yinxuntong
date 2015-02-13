//
//  MenuCell.h
//  yingxuntong
//
//  Created by ilikeido on 15-2-12.
//  Copyright (c) 2015年 ilikeido. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface MenuCell : UICollectionViewCell

@property(nonatomic,strong) NSString *imageName;

@property(nonatomic,strong) NSString *title;

@property (weak, nonatomic) IBOutlet UIImageView *imageView;

@property (weak, nonatomic) IBOutlet UILabel *lable;

@end
