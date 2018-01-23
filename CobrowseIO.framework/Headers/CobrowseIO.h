#import <Foundation/Foundation.h>

#import "CBIOSession.h"
#import "CobrowseIODelegate.h"

typedef NSString CBLicense;

@interface CobrowseIO : NSObject

@property CBLicense* license;
@property NSString* api;
@property (nonatomic, copy) void (^onStatusTap)();

+(instancetype) instance;

-(instancetype) setDelegate: (id<CobrowseIODelegate>) delegate;

-(instancetype) createSession: (CBErrorSessionBlock) callback;
-(instancetype) getSession: (NSString*) idOrCode callback: (CBErrorSessionBlock)callback;

-(CBIOSession*) currentSession;

@end
