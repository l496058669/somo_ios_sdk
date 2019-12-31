//#import <somo_ios_sdk/somo_ios_sdk.h>
#import "BaseModel.h"
#import "SOMOVideoView.h"

NS_ASSUME_NONNULL_BEGIN

@protocol SOMOSDKMeetingDelegate<NSObject>

@optional

//所有会议事件的回调
-(void)receivedMeetingEvent:(uint32_t)eventType meetingID:(uint64_t)meetingID detail:(NSString *)detail;
@required
-(void)onCreateMeetingRes:(NSDictionary *)res;
-(void)onJoinMeetingRes:(NSDictionary *)res;
-(void)onUserJoinEvent:(NSDictionary *)res;
-(void)onUserLeaveEvent:(NSDictionary *)res;
-(void)onUserCameraChangeEvent:(NSDictionary *)res;
-(void)onUserMicChangeEvent:(NSDictionary *)res;

@end

//录音质量类型
typedef NS_ENUM(NSInteger, SOMOAudioRecordQuality) {
    AudioRecordQualityDefault   = 16000,
    AudioRecordQualityMedium    = 32000,
    AudioRecordQualityHigh      = 48000
};

@interface SOMOSDK : BaseModel


/*———————                ———————*/
//@property (nonatomic, assign) BOOL isDebug; //debug模式(默认为 NO)
//@property (nonatomic, assign) BOOL isLog;   //是否打印日志(默认为 NO)







@property (nonatomic, weak) id<SOMOSDKMeetingDelegate> delegate;



/*———————        推送及设备间呼叫        ———————*/

/// 发起会议呼叫
/// @param UID  目标UID
/// @param targetOS  目标用户当前设备   1:安卓     2:iOS
/// @param appID  somo的APPid
/// @param mid  当前会议的ID
/// @param data  应用层json数据
/// @param title  呼叫标题
/// @param isProduction  是否是生产环境
/// @param handler  回调
-(void)callToUid:(NSString *)UID
             mid:(NSString *)mid
            code:(NSString *)code
           title:(NSString *)title
        targetOS:(int)targetOS
    isProduction:(BOOL)isProduction
         handler:(void (^)(NSDictionary *))handler;



/*———————        会议开始前的操作        ———————*/
/// 加入会议
/// @param meetingCode 会议号
-(NSDictionary *)joinMeeting:(NSString *)meetingCode;

//发起会议
-(int)creatMeeting;

//离开会议
-(int)leaveMeeting;




/*———————        视频操作        ———————*/
/// 开启摄像头
-(int)startVideoCapture:(SOMOVideoView *)view;

//关闭摄像头
-(int)stopVideoCapture;

//切换前后摄像头
-(int)switchCamera;
    
/// 开始播放视频
/// @param uid 要播放的目标用户的UID
/// @param view 显示视频的View (由APP传入)
-(int)startVideoPlayWithUID:(NSString *)uid view:(SOMOVideoView *)view;

/// 停止播放视频
/// @param UID 停止的目标UID
-(int)stopVideoPlay:(NSString *)UID;




/*———————        音频操作        ———————*/
/// 开始录制音频
-(int)startAudioCapture;

//停止音频录制
-(int)stopAudioCapture;

/// 开始录制音频
/// @param path 路径
/// @param fileName 文件名，目前仅支持wav格式即以  @“.wav” 结尾
/// @param quality 录音质量
-(int)startAudioRecordingWithPath:(NSString *)path fileName:(NSString *)fileName quality:(SOMOAudioRecordQuality)quality;

//停止录制音频
-(int)stopAudioRecording;

// 播放音频流
-(int)startAudioPlay;

/// 停止播放用户音频
-(int)stopAudioPlay;




/*————————————————      创建、销毁、单例        ————————————————*/
/// 初始化SOMOSDK
/// @param appID appID description
/// @param appSecret appSecret description
/// @param userId userId description
-(void)createWithAppID:(NSString *)appID
             appSecret:(NSString *)appSecret
                userID:(NSString *)userId
               handler:(void (^)(NSDictionary *))handler;

//释放SOMOSDK
-(void)destory;

//设置代理
-(void)setMeetingDelegate:(id)delegate;

/// 单例
+(instancetype)shareManager;

@end

NS_ASSUME_NONNULL_END
