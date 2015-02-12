//
//  ViewController.m
//  yingxuntong
//
//  Created by ilikeido on 15-2-11.
//  Copyright (c) 2015年 ilikeido. All rights reserved.
//

#import "ViewController.h"
#import "ImagePlayerView.h"
#import "UIImageView+WebCache.h"

@interface ViewController ()<ImagePlayerViewDelegate>

@property (weak, nonatomic) IBOutlet ImagePlayerView *imagePlayerView;

@property (nonatomic, strong) NSArray *imageURLs;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    [self loadImagePlayView];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(void)loadImagePlayView{
    self.imageURLs = @[[NSURL URLWithString:@"http://sudasuta.com/wp-content/uploads/2013/10/10143181686_375e063f2c_z.jpg"],
                       [NSURL URLWithString:@"http://www.yancheng.gov.cn/ztzl/zgycddhsdgy/xwdt/201109/W020110902584601289616.jpg"],
                       [NSURL URLWithString:@"http://fzone.oushinet.com/bbs/data/attachment/forum/201208/15/074140zsb6ko6hfhzrb40q.jpg"]];
    
    self.imagePlayerView.imagePlayerViewDelegate = self;
    
    // set auto scroll interval to x seconds
//    self.imagePlayerView.scrollInterval = 5.0f;
    
    // adjust pageControl position
    self.imagePlayerView.pageControlPosition = ICPageControlPosition_BottomRight;
    
    // hide pageControl or not
    self.imagePlayerView.hidePageControl = NO;
    
    [self.imagePlayerView reloadData];
    
}


#pragma mark - ImagePlayerViewDelegate
- (NSInteger)numberOfItems
{
    return self.imageURLs.count;
}

- (void)imagePlayerView:(ImagePlayerView *)imagePlayerView loadImageForImageView:(UIImageView *)imageView index:(NSInteger)index
{
    // recommend to use SDWebImage lib to load web image
    //    [imageView setImageWithURL:[self.imageURLs objectAtIndex:index] placeholderImage:nil];
    
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        [imageView setImageWithURL:[self.imageURLs objectAtIndex:index] placeholderImage:nil];
    });
}

- (void)imagePlayerView:(ImagePlayerView *)imagePlayerView didTapAtIndex:(NSInteger)index
{
    NSLog(@"did tap index = %d", (int)index);
}


@end
