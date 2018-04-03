#import <Foundation/Foundation.h>

#import "CBIOSession.h"
#import "CobrowseIODelegate.h"

static NSString* kCBIOUserIdKey = @"user_id";
static NSString* kCBIOUserEmailKey = @"user_email";

typedef NSString CBLicense;

@interface CobrowseIO : NSObject

@property CBLicense* license;
@property NSString* api;
@property NSDictionary<NSString*, NSValue*>* customData;

@property (nonatomic, copy) void (^onStatusTap)(void);

+(instancetype) instance;
+(BOOL) isCobrowseNotification: (NSDictionary*) userInfo;

-(instancetype) setDelegate: (id<CobrowseIODelegate>) delegate;

-(instancetype) createSession: (CBErrorSessionBlock) callback;
-(instancetype) getSession: (NSString*) idOrCode callback: (CBErrorSessionBlock)callback;

-(CBIOSession*) currentSession;


@end
