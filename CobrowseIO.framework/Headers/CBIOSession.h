#import <Foundation/Foundation.h>

@class CBIOSession;

typedef void const (^CBErrorSessionBlock)(NSError* err, CBIOSession* session);

@interface CBIOSession : NSObject

-(bool) isPending;
-(bool) isApproved;
-(bool) hasAgent;
-(bool) isActive;
-(bool) isEnded;

-(void) fetch: (CBErrorSessionBlock) callback;
-(void) activate: (CBErrorSessionBlock) callback;
-(void) end: (CBErrorSessionBlock) callback;

-(NSString*) code;
-(NSString*) id;
-(NSString*) state;

@end
