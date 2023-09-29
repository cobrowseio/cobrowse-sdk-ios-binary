#import <Foundation/Foundation.h>
#import "CBIORESTResource.h"

@class CBIOSession;
@class CBIOAgent;

/// Describes the state of the remote control feature in a Session
typedef enum : NSUInteger {
    kCBIORemoteControlStateOff = 0,
    kCBIORemoteControlStateRequested,
    kCBIORemoteControlStateRejected,
    kCBIORemoteControlStateOn
} CBIORemoteControlState;

/// Describes the state of the full device feature in a Session
typedef enum : NSUInteger {
    kCBIOFullDeviceStateOff = 0,
    kCBIOFullDeviceStateRequested,
    kCBIOFullDeviceStateRejected,
    kCBIOFullDeviceStateOn
} CBIOFullDeviceState;

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

/// Tests if the session is configured for full device access (e.g. ReplayKit). This can be
/// changed dynamically by the server.
-(CBIOFullDeviceState) fullDeviceState;
-(bool) fullDevice;

/// Set the state of the full device mode. Setting this to false when the session is capturing in full device
/// mode will end any active full device capturing mechanisms (e.g. ReplayKit).
/// @param state Full device mode
/// @param callback Called when the request completes or fails
-(void) setFullDeviceState: (CBIOFullDeviceState) state callback: (nullable CBErrorSessionBlock) callback;
-(void) setFullDevice: (BOOL) value callback: (nullable CBErrorSessionBlock) callback;

/// The state of remote control
-(CBIORemoteControlState) remoteControl;

/// Set the state of remote control
/// @param state Desired remote control state
/// @param callback Called when the request completes or fails
-(void) setRemoteControl: (CBIORemoteControlState) state callback: (nullable CBErrorSessionBlock) callback;

/// Set the enabled capabilities for the session
/// @param capabilities Array of capability keys to enable
/// @param callback Called when the request completes or fails
-(void) setCapabilities: ( NSArray<NSString*>* _Nonnull) capabilities callback: (nullable CBErrorSessionBlock) callback;

@end
