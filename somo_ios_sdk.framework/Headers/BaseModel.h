#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface BaseModel : NSObject
#pragma mark -    多线程
void kGCDAsyncBlock(void (^block)(void));
void kGCDAfterBlock(CGFloat delay, void (^block)(void));
void kGCDMainBlock(void (^block)(void));
@end

NS_ASSUME_NONNULL_END
