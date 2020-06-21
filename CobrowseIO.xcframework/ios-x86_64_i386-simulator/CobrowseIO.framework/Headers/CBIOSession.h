#import <Foundation/Foundation.h>
#import "CBIORESTResource.h"

@class CBIOSession;
@class CBIOAgent;

typedef void const (^CBErrorSessionBlock)(NSError* _Nullable err, CBIOSession* _Nullable session);

/// A CBIOSession tracks the state of a single screen share session through the
/// initial request, authorization, activty and ending.
@interface CBIOSession : CBIORESTResource

/// Session has beenn created, but an agent or device has not yet joined
-(bool) isPending;

/// Confirmation prompt shown, waiting for the user to accept the session
-(bool) isAuthorizing;

/// A agent has joined
-(bool) hasAgent;

/// The screen share session is in progress, frames are streaming
-(bool) isActive;

/// The session is finished and can no longer be used or updated
-(bool) isEnded;

-(void) fetch: (nullable CBErrorSessionBlock) callback;

/// Transitions a session from pending or authorizing to active, allowing frames to start
/// streaming. In order to activate a session, some conditions must be met:
///
/// 1. it must be in pending or authorizing state
/// 2. an agent must have joined
///
/// @param callback Called when the session is activated, or an error occurs
-(void) activate: (nullable CBErrorSessionBlock) callback;

/// Ends a session. Once ended frames will stop streaming and it can no longer be used.
/// @param callback Called when the end request completes, or there is an error.
-(void) end: (nullable CBErrorSessionBlock) callback;

/// The six digit code that can be shared with an agent to allow them to join the screen share.
/// Note: this is only available for sessions in the "pending" state. Once an agent has joined
/// the code will be null as it is no longer valid.
/// @return The six digit code
-(nullable NSString*) code;

/// The state of the session. The session states transition as follows:
/// pending ( -> authorizing ) -> active -> ended
/// The authorizing step is optional as user consent may not always be required (configrable via
/// the dashboard).
///
/// @see `-isPending`
/// @see `-isAuthorizing`
/// @see `-isActive`
/// @see `-isEnded`
-(nonnull NSString*) state;

/// Gets the basic information about the support agent in the session, or null if no agent has
/// joined yet
/// @return The agent information or null
-(nullable CBIOAgent*) agent;

@end
