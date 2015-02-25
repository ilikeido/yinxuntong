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
#import "MenuCell.h"

#define MENUCELL_IDENTIFER @"MENUCELL_IDENTIFER"

@interface ViewController ()<ImagePlayerViewDelegate,UICollectionViewDelegate,UICollectionViewDataSource>

@property (weak, nonatomic) IBOutlet ImagePlayerView *imagePlayerView;

@property (weak, nonatomic) IBOutlet UICollectionView *collectionView;

@property (nonatomic, strong) NSMutableArray *advDatas;//广告

@property (nonatomic, strong) NSMutableArray *menuDatas;//菜单

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    [self loadDatas];
    [self loadImagePlayView];
    [self.collectionView registerNib:[UINib nibWithNibName:@"MenuCell" bundle:nil]  forCellWithReuseIdentifier:MENUCELL_IDENTIFER];
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(void)loadDatas{
    self.advDatas = [[NSMutableArray alloc]initWithObjects:@{@"imageName":@"",@"title":@""},@{@"imageName":@"",@"title":@""},@{@"imageName":@"",@"title":@""},@{@"imageName":@"",@"title":@""},@{@"imageName":@"",@"title":@""},@{@"imageName":@"",@"title":@""},@{@"imageName":@"",@"title":@""},@{@"imageName":@"",@"title":@""},@{@"imageName":@"",@"title":@""},@{@"imageName":@"",@"title":@""},@{@"imageName":@"",@"title":@""},nil];
    
    self.menuDatas = [[NSMutableArray alloc]initWithObjects:@{@"imageName":@"商户管理_icon",@"title":@"商户管理"},@{@"imageName":@"业务管理_icon_nor",@"title":@"业务办理"},@{@"imageName":@"",@"title":@""},@{@"imageName":@"",@"title":@""},@{@"imageName":@"",@"title":@""},@{@"imageName":@"",@"title":@""},@{@"imageName":@"",@"title":@""},@{@"imageName":@"",@"title":@""},@{@"imageName":@"",@"title":@""},@{@"imageName":@"",@"title":@""},@{@"imageName":@"",@"title":@""},nil];
    
}

-(void)loadImagePlayView{
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
    return self.advDatas.count;
}

- (void)imagePlayerView:(ImagePlayerView *)imagePlayerView loadImageForImageView:(UIImageView *)imageView index:(NSInteger)index
{
    // recommend to use SDWebImage lib to load web image
    //    [imageView setImageWithURL:[self.imageURLs objectAtIndex:index] placeholderImage:nil];
    
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        NSDictionary *advDic = [self.advDatas objectAtIndex:index];
        [imageView setImage:[UIImage imageNamed:[advDic objectForKey:@"imageName"]]];
    });
}

- (void)imagePlayerView:(ImagePlayerView *)imagePlayerView didTapAtIndex:(NSInteger)index
{
    NSLog(@"did tap index = %d", (int)index);
}


#pragma mark - UICollectionViewDataSource
- (NSInteger)numberOfSectionsInCollectionView:(UICollectionView *)collectionView
{
    return 1;
}

- (NSInteger)collectionView:(UICollectionView *)view numberOfItemsInSection:(NSInteger)section;
{
    return self.menuDatas.count; //
}


//每个UICollectionView展示的内容
-(UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath
{
    //重用cell
    MenuCell *cell = [collectionView dequeueReusableCellWithReuseIdentifier:MENUCELL_IDENTIFER forIndexPath:indexPath];
    NSDictionary *dict = [self.menuDatas objectAtIndex:indexPath.row];
    cell.imageName = [dict objectForKey:@"imageName"];
    cell.title = [dict objectForKey:@"title"];
    return cell;
}

#pragma mark --UICollectionViewDelegateFlowLayout
//定义每个UICollectionViewCell 的大小
- (CGSize)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout*)collectionViewLayout sizeForItemAtIndexPath:(NSIndexPath *)indexPath
{
    CGSize size = collectionView.frame.size;
    CGFloat width = (size.width - 40)/4;
    return CGSizeMake(width, width);
}

//定义每个UICollectionView 的 margin
-(UIEdgeInsets)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout insetForSectionAtIndex:(NSInteger)section
{
    return UIEdgeInsetsMake(5, 5, 15, 5);
}

@end
