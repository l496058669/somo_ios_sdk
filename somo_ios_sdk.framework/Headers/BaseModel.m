//
//  BaseModel.m
//  somo_ios_sdk
//
//  Created by iflyC on 2019/11/14.
//  Copyright © 2019 SOMOfuture. All rights reserved.
//

#import "BaseModel.h"

@implementation BaseModel


void kGCDAsyncBlock(void (^block)(void)) {
    dispatch_queue_global_t queue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);
    dispatch_async(queue,block);
}

void kGCDAfterBlock(CGFloat delay, void (^block)(void)) {
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(delay * NSEC_PER_SEC)), dispatch_get_main_queue(), block);
}

void kGCDMainBlock(void (^block)(void)) {
    if ([NSThread isMainThread]) {
        block();
    } else {
        dispatch_async(dispatch_get_main_queue(), block);
    }
}


@end
