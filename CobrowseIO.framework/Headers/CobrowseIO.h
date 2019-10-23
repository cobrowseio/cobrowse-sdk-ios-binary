#import <Foundation/Foundation.h>

#import "CBIODevice.h"
#import "CBIOSession.h"
#import "CobrowseIODelegate.h"
#import "CBIOResponderExtension.h"
#import "CobrowseIORedacted.h"
#import "CBIOAgent.h"
#import "CBIORESTResource.h"
#import "CBIOViewController.h"
#import "CBIOTouch.h"
#import "CBIOTouchEvent.h"
#import "CBIOKeyPress.h"
#import "CBIOResponder.h"
#import "CBIOResponderExtension.h"

static NSString* _Nonnull const kCBIOUserIdKey = @"user_id";
static NSString* _Nonnull const kCBIOUserEmailKey = @"user_email";
static NSString* _Nonnull const kCBIOUserNameKey = @"user_name";
static NSString* _Nonnull const kCBIODeviceIdKey = @"device_id";
static NSString* _Nonnull const kCBIODeviceNameKey = @"device_name";

typedef NSString CBLicense;

@interface CobrowseIO : NSObject

@property (nonnull) CBLicense* license;
@property (nonnull) NSString* api;
@property (nonnull) NSDictionary<NSString*, NSObject*>* customData;
@property (nullable) id<CobrowseIODelegate> delegate;
@property (readonly, nonnull) NSString* deviceId;
@property (readonly, nonnull) CBIODevice* device;

+(instancetype _Nonnull) instance;

-(instancetype _Nonnull) start;
-(instancetype _Nonnull) stop;
-(instancetype _Nonnull) stop: (void (^_Nonnull)(NSError* _Nullable err)) callback;

-(instancetype _Nonnull) createSession: (nullable CBErrorSessionBlock) callback;
-(instancetype _Nonnull) getSession: (nonnull NSString*) idOrCode callback: (nullable CBErrorSessionBlock)callback;

-(CBIOSession* _Nullable) currentSession;

+(void) experimental_v2_registerResponderExtension: (nonnull Class) klass withTarget: (nonnull id<CBIOResponderExtension>) target;

@end


@interface CobrowseIO (Push)
+(BOOL) isCobrowseNotification: (nonnull NSDictionary*) userInfo;
+(void) onPushNotification: (nonnull NSDictionary*) userInfo;
@end
