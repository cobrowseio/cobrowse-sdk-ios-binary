#import <Foundation/Foundation.h>
#import "CBIORESTResource.h"

@class CBIOSession;
@class CBIOAgent;

typedef void const (^CBErrorSessionBlock)(NSError* _Nullable err, CBIOSession* _Nullable session);

@interface CBIOSession : CBIORESTResource

-(bool) isPending;
-(bool) isAuthorizing;
-(bool) hasAgent;
-(bool) isActive;
-(bool) isEnded;

-(void) fetch: (nullable CBErrorSessionBlock) callback;
-(void) activate: (nullable CBErrorSessionBlock) callback;
-(void) end: (nullable CBErrorSessionBlock) callback;

-(nullable NSString*) code;
-(nonnull NSString*) state;
-(nullable CBIOAgent*) agent;

@end
