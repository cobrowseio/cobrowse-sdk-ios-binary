#import <Foundation/Foundation.h>
#import "CBIORESTResource.h"
#import "CBIOSessionMetrics.h"

@class CBIOSession;
@class CBIOAgent;

/// Describes the state of the remote control feature in a Session
typedef NS_ENUM(NSInteger, CBIORemoteControlState) {
    CBIORemoteControlStateOff = 0,
    CBIORemoteControlStateRequested,
    CBIORemoteControlStateRejected,
    CBIORemoteControlStateOn
};

/// Describes the state of the full device feature in a Session
typedef NS_ENUM(NSInteger, CBIOFullDeviceState) {
    CBIOFullDeviceStateOff = 0,
    CBIOFullDeviceStateRequested,
    CBIOFullDeviceStateRejected,
    CBIOFullDeviceStateOn
};

/// Describes the reason a Session ended
typedef NS_ENUM(NSInteger, CBIOSessionEndedReason) {
    CBIOSessionEndedReasonUnknown = 0,
    CBIOSessionEndedReasonDeviceEnded,
    CBIOSessionEndedReasonAgentEnded,
    CBIOSessionEndedReasonPendingTimeout,
    CBIOSessionEndedReasonAuthorizingTimeout,
    CBIOSessionEndedReasonActiveTimeout,
    CBIOSessionEndedReasonLimitEnforcement
};

typedef void const (^CBErrorSessionBlock)(NSError* _Nullable err, CBIOSession* _Nullable session);

/// A CBIOSession tracks the state of a single screen share session through the
/// initial request, authorization, activity and ending.
@interface CBIOSession : CBIORESTResource

/// Session has been created, but an agent or device has not yet joined
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

/// Transitions a session from `pending` or `authorizing` to `active`, allowing frames to start
/// streaming. In order to activate a session, some conditions must be met:
///
/// 1. it must be in `pending` or `authorizing` state
/// 2. an agent must have joined
///
/// - Parameter callback Called when the session is activated, or an error occurs
-(void) activate: (nullable CBErrorSessionBlock) callback;

/// Ends a session. Once ended, frames will stop streaming and the session can no longer be used.
///
/// - Parameter callback Called when the end request completes, or there is an error.
-(void) end: (nullable CBErrorSessionBlock) callback;

/// The six digit code that can be shared with an agent to allow them to join the screen share.
///
/// - Note: this is only available for sessions in the `pending` state. Once an agent has joined
/// the code will be null as it is no longer valid.
///
/// - Returns: The six digit code
-(nullable NSString*) code;

/// The state of the session. Session states transition as follows:
/// `pending` ( -> `authorizing` ) -> `active` -> `ended`
///
/// - Note: The `authorizing` step is optional as user consent may not always be required (configurable via
/// the dashboard).
///
/// - See: ``CBIOSession/isPending``
/// - See: ``CBIOSession/isAuthorizing``
/// - See: ``CBIOSession/isActive``
/// - See: ``CBIOSession/isEnded``
-(nonnull NSString*) state;

/// Gets the basic information about the support agent in the session, or null if no agent has
/// joined.
///
/// - Returns: The agent information or null
-(nullable CBIOAgent*) agent;

/// Returns the network metrics for the session.
///
/// - Returns: Collected session metrics.
-(nonnull CBIOSessionMetrics*) metrics;

/// Tests if the session is configured for full device access (e.g. ReplayKit). This can be
/// changed dynamically by the server.
-(CBIOFullDeviceState) fullDevice;

/// Set the state of the full device mode. Setting this to ``CBIOFullDeviceState/off`` when the session is capturing in full device
/// mode will end any active full device capturing mechanisms (e.g. ReplayKit).
///
/// - Parameter state Full device mode
/// - Parameter callback Called when the request completes or fails
-(void) setFullDevice: (CBIOFullDeviceState) state callback: (nullable CBErrorSessionBlock) callback;

/// The state of remote control
-(CBIORemoteControlState) remoteControl;

/// Set the state of remote control
///
/// - Parameter state Desired remote control state
/// - Parameter callback Called when the request completes or fails
-(void) setRemoteControl: (CBIORemoteControlState) state callback: (nullable CBErrorSessionBlock) callback;

/// Set the enabled capabilities for the session
///
/// - Parameter capabilities Array of capability keys to enable
/// - Parameter callback Called when the request completes or fails
-(void) setCapabilities: ( NSArray<NSString*>* _Nonnull) capabilities callback: (nullable CBErrorSessionBlock) callback;

// Returns an immutable NSDictionary representing the custom data of the session instance.
- (nonnull NSDictionary<NSString *, NSString *> *)customData;

// Sets custom data on the session instance.
- (void)setCustomData:(nonnull NSDictionary<NSString*, NSString*>*)customData
             callback:(nullable CBErrorSessionBlock) callback;

/// The reason the session ended
-(CBIOSessionEndedReason) endedReason;

/// When the session was created
-(nonnull NSDate*) created;

/// When the session will expire
-(nullable NSDate*) expires;

/// When the session was activated
-(nullable NSDate*) activated;

/// When the session was last updated
-(nullable NSDate*) updated;

/// When the session was ended
-(nullable NSDate*) ended;

@end
