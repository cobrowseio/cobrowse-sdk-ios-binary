#import <Foundation/Foundation.h>

// expose core lib headers
#import "CBIOSession.h"
#import "CBIODevice.h"
#import "CBIOAgent.h"
#import "CBIORESTResource.h"
#import "CBIOTouchEvent.h"
#import "CBIOTouch.h"
#import "CBIOKeyPress.h"
#import "CBIOResponder.h"

// and headers specific to this framework
#import "CobrowseIODelegate.h"
#import "CobrowseIORedacted.h"
#import "CBIOViewController.h"

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

-(nonnull instancetype) createSession: (nullable CBErrorSessionBlock) callback;
-(nonnull instancetype) getSession: (nonnull NSString*) idOrCode callback: (nullable CBErrorSessionBlock)callback;
-(nullable CBIOSession*) currentSession;

@end


@interface CobrowseIO (Push)
+(BOOL) isCobrowseNotification: (nonnull NSDictionary*) userInfo;
+(void) onPushNotification: (nonnull NSDictionary*) userInfo;
@end
