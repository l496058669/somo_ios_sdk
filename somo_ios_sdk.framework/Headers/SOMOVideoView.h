
#import <UIKit/UIKit.h>
#define IOS_INCLUDE

NS_ASSUME_NONNULL_BEGIN

@class SOMOVideoView;
@class RCUserKey;

@protocol SOMOVideoViewDelegate <NSObject>

- (void)videoViewDidStartRender:(SOMOVideoView *)videoView;
- (void)updateResolutionWithWidth:(int)width height:(int)height;

@end


@interface SOMOVideoView : UIView

@property (nonatomic, assign) uint64_t uid;
//@property (nonatomic, weak) id<SOMOVideoViewDelegate> delegate;
//@property (nonatomic, assign) BOOL isShare;
//
//- (void *)getCPlusPlusView;
//
//- (void)displayWithData:(void *)data width:(int)pWidth height:(int)pHeight len:(int)len;
//- (void)startPlay:(RCUserKey*)user;
//- (void)stopPlay;
//- (BOOL)isPlay;
//- (void)updateSelfSizeWith:(CGRect)frame;
//
//-(void)releaseSOMOVideoView;

@end

NS_ASSUME_NONNULL_END
