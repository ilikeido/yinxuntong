//
//  test.m
//  test
//
//  Created by ilikeido on 15-2-11.
//  Copyright (c) 2015年 ilikeido. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <XCTest/XCTest.h>
#import "SystemAPI.h"

@interface test : XCTestCase{
    NSRunLoop* runLoop;
}

@end

@implementation test

- (void)setUp {
    [super setUp];
    
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
   
}

- (void)testGetCurrentDateTime {
    // This is an example of a functional test case.
//    XCTAssert(YES, @"Pass");
    runLoop = [NSRunLoop currentRunLoop];
    GetCurrentDateTimeRequest *request = [[GetCurrentDateTimeRequest alloc]init];
    [SystemAPI request:request responseClass:[GetCurrentDateTimeResponse class] completionBlockWithSuccess:^(NDBaseAPIResponse *response) {
        GetCurrentDateTimeResponse *response1 = (GetCurrentDateTimeResponse *)response;
        NSLog(@"%@",response1.currentDateTime);
    } Fail:^(NSString *returnCode, NSString *failDescript) {
        NSLog(@"%@",failDescript);
    }];
     [runLoop runUntilDate:[NSDate dateWithTimeIntervalSinceNow:20]];
}

//- (void)testPerformanceExample {
//    // This is an example of a performance test case.
//    [self measureBlock:^{
//       
//    }];
//}



@end
