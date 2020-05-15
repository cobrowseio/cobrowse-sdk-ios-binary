#import <Foundation/Foundation.h>

#import "CBIOSession.h"
#import "CBIODevice.h"
#import "CBIOAgent.h"
#import "CBIORESTResource.h"
#import "CBIOTouchEvent.h"
#import "CBIOKeyPress.h"

#import "CobrowseIODelegate.h"
#import "CobrowseIORedacted.h"

#if TARGET_OS_IOS
#import "CBIOTouch.h"
#import "CBIOResponder.h"
#import "CBIOViewController.h"
#endif

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

+(nonnull instancetype) instance;

-(nonnull instancetype) start;
-(nonnull instancetype) stop;
-(nonnull instancetype) stop: (void (^_Nonnull)(NSError* _Nullable err)) callback;
-(bool) isStarted;

-(nonnull instancetype) createSession: (nullable CBErrorSessionBlock) callback;
-(nonnull instancetype) getSession: (nonnull NSString*) idOrCode callback: (nullable CBErrorSessionBlock)callback;
-(nullable CBIOSession*) currentSession;

-(nonnull NSString*) version;

@end


@interface CobrowseIO (Push)
+(BOOL) isCobrowseNotification: (nonnull NSDictionary*) userInfo;
+(void) onPushNotification: (nonnull NSDictionary*) userInfo;
@end
