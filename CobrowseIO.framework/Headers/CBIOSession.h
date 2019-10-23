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

-(void) fetch: (CBErrorSessionBlock _Nullable) callback;
-(void) activate: (CBErrorSessionBlock _Nullable) callback;
-(void) end: (CBErrorSessionBlock _Nullable) callback;

-(NSString* _Nullable) code;
-(NSString* _Nonnull) state;
-(CBIOAgent* _Nullable) agent;

@end
