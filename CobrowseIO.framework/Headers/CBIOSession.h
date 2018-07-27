#import <Foundation/Foundation.h>

#import "CBIORESTResource.h"

@class CBIOSession;
@class CBIOAgent;

typedef void const (^CBErrorSessionBlock)(NSError* err, CBIOSession* session);

@interface CBIOSession : CBIORESTResource

-(bool) isPending;
-(bool) hasAgent;
-(bool) isActive;
-(bool) isEnded;

-(void) fetch: (CBErrorSessionBlock) callback;
-(void) activate: (CBErrorSessionBlock) callback;
-(void) end: (CBErrorSessionBlock) callback;

-(NSString*) code;
-(NSString*) state;
-(CBIOAgent*) agent;

@end
