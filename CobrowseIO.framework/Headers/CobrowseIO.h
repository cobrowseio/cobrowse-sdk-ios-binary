#import <Foundation/Foundation.h>

#import "CBIOSession.h"
#import "CobrowseIODelegate.h"
#import "CBIOResponderExtension.h"

static NSString* kCBIOUserIdKey = @"user_id";
static NSString* kCBIOUserEmailKey = @"user_email";
static NSString* kCBIOUserNameKey = @"user_name";
static NSString* kCBIODeviceIdKey = @"device_id";
static NSString* kCBIODeviceNameKey = @"device_name";

typedef NSString CBLicense;

@interface CobrowseIO : NSObject

@property CBLicense* license;
@property NSString* api;
@property NSDictionary<NSString*, NSObject*>* customData;
@property id<CobrowseIODelegate> delegate;
@property (readonly) NSString* deviceId;

@property (nonatomic, copy) void (^onStatusTap)(void);

+(instancetype) instance;
+(BOOL) isCobrowseNotification: (NSDictionary*) userInfo;
+(void) onPushNotification: (NSDictionary*) userInfo;

-(instancetype) start;
-(instancetype) stop;

-(instancetype) createSession: (CBErrorSessionBlock) callback;
-(instancetype) getSession: (NSString*) idOrCode callback: (CBErrorSessionBlock)callback;

-(CBIOSession*) currentSession;

+(void) experimental_registerResponderExtension: (Class) klass withTarget: (id<CBIOResponderExtension>) target;

@end
