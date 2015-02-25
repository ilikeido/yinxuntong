//
//  LoginVC.m
//  yingxuntong
//
//  Created by ilikeido on 15-2-16.
//  Copyright (c) 2015年 ilikeido. All rights reserved.
//

#import "LoginVC.h"
#import "ShareValue.h"
#import "UserAPI.h"
#import "ViewController.h"
#import "MBProgressHUD.h"

@interface LoginVC ()

@property (weak, nonatomic) IBOutlet UITextField *tf_account;

@property (weak, nonatomic) IBOutlet UITextField *tf_pwd;

@property (weak, nonatomic) IBOutlet UIButton *btn_rember;

@property (weak, nonatomic) IBOutlet UIButton *btn_login;

@property(nonatomic,assign) BOOL remberFlag;

@end

@implementation LoginVC

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    [self initViews];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/**
 *  初始化输入框和记住密码
 */
-(void)initViews{
    if([ShareValue standardShareValue].rememberPwd){
        _tf_account.text = [ShareValue standardShareValue].save_userName;
        _tf_pwd.text = [ShareValue standardShareValue].save_pwd;
        _btn_rember.selected = YES;
        _btn_login.layer.cornerRadius = 8;
        _btn_login.layer.masksToBounds = YES;
    }
    self.remberFlag = [ShareValue standardShareValue].rememberPwd;
}

- (IBAction)remberAction:(id)sender {
   self.remberFlag = !self.remberFlag;
    _btn_rember.selected = self.remberFlag;
}

- (IBAction)loginAction:(id)sender {
    if (_tf_account.text.length == 0) {
        UIAlertView *alert = [[UIAlertView alloc]initWithTitle:@"提示" message:@"请输入您的帐号" delegate:nil cancelButtonTitle:@"确定" otherButtonTitles: nil];
        [alert show];
        return;
    }
    if (_tf_pwd.text.length == 0) {
        UIAlertView *alert = [[UIAlertView alloc]initWithTitle:@"提示" message:@"请输入您的密码" delegate:nil cancelButtonTitle:@"确定" otherButtonTitles: nil];
        [alert show];
        return;
    }
    
    PosLoginRequest *request = [[PosLoginRequest alloc]init];
    request.phoneNum = _tf_pwd.text;
    request.password = _tf_account.text;
    [ShareValue standardShareValue].rememberPwd = self.remberFlag;
    MBProgressHUD *hud = [MBProgressHUD showHUDAddedTo:self.view animated:YES];
    hud.labelText = @"正在登录，请稍候...";
    [UserAPI posLoginByRequest:request completionBlockWithSuccess:^(PosLoginResponse *response) {
        [hud hide:YES];
        ViewController *vc = [[ViewController alloc]init];
        [self.navigationController pushViewController:vc animated:YES];
    } Fail:^(NSString *returnCode, NSString *failDescript) {
        hud.labelText = failDescript;
        [hud hide:YES afterDelay:1.5];
    }];
    
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
