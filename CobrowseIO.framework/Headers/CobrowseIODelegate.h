#import <Foundation/Foundation.h>

@class UIWindow;
@class UIViewController;
@class UIView;

@class CBIOSession;
@class CBIOTouchEvent;
@class CBIOKeyPress;

/// Implement this deletgate protocol to customise the behaviour of Cobrowse.
@protocol CobrowseIODelegate <NSObject>

/// Called when a new session is started, or an existing session changes state.
/// @param session The session that is changing
-(void) cobrowseSessionDidUpdate: (nonnull CBIOSession*) session;
/// Called when a session will end.
/// @param session The session that ended
-(void) cobrowseSessionDidEnd: (nonnull CBIOSession*) session;

@optional

/// Implement this method to handle cases where screen capture fails. On MacOS this is likely due
/// to missing system permissions required for capturing the screen.
/// @param session The session the failure occurred in
/// @param err The reason for the failure
-(void) cobrowseScreenCaptureDidFailForSession: (nonnull CBIOSession*) session withError: (nonnull NSError*) err API_AVAILABLE(macos(10.10));

/// Implement this method to filter the touch events that come from the agent. This allows
/// you to conditionally apply touch events to certain views. For instance if you had a view
/// that support agents should never be able to remotely control, you can filter event related
/// to that view.
/// @param touchEvent The touch event
/// @param session The session the touch event originated from
-(bool) cobrowseShouldAllowTouchEvent: (nonnull CBIOTouchEvent*) touchEvent forSession: (nonnull CBIOSession*) session API_AVAILABLE(ios(9));

/// Implement this method to filter key events that come from the agent. This allows
/// you to conditionally apply key events to certain inputs. For instance if you had a view
/// that support agents should never be able to remotely control, you can filter event related
/// to that view.
/// @param keyEvent The key event
/// @param session The session the touch event originated from
-(bool) cobrowseShouldAllowKeyEvent: (nonnull CBIOKeyPress*) keyEvent forSession: (nonnull CBIOSession*) session API_AVAILABLE(ios(9));

/// Implement this method to override the default session acceptance prompt. The session
/// passed to this method will be in the `authorizing` state, when you have gained
/// confirmation from the user, you should call either `CBIOSession -activate` or
/// `CBIOSession -end` to approve or reject the session.
/// @param session The incoming session to approve or reject
-(void) cobrowseHandleSessionRequest: (nonnull CBIOSession*) session;

/// Implement this method to override the default remote control acceptance prompt.
/// When you have gained confirmation from the user, you should call  `CBIOSession -setRemoteControl`
/// and pass either `kCBIORemoteControlStateOn` or `kCBIORemoteControlStateRejected`
/// to approve or reject the remote control request.
/// @param session The incoming session that has been requested to activate remote control
-(void) cobrowseHandleRemoteControlRequest: (nonnull CBIOSession*) session;

/// WARNING: This API is experimental and not covered by semantic versioning yet!
/// Implement this method to override the default full device request prompt.
/// Your are responsible for displaying a `RPSystemBroadcastPickerView` to the user.
/// @param session The incoming session that has requested full device mode
-(void) cobrowseShowFullDevicePrompt: (nonnull CBIOSession*) session API_AVAILABLE(ios(9));

/// WARNING: This API is experimental and not covered by semantic versioning yet!
/// Implement this method to hide the default full device request prompt.
-(void) cobrowseHideFullDevicePrompt: (nonnull CBIOSession*) session API_AVAILABLE(ios(9));

/// Implement this method to override the default session indicator. This method may be
/// called several times as the session progresses through its lifecycle, so you may need
/// to adjust your UI accordingly. See the available sesssion methods to inspect session state.
/// Note you should also implement `-cobrowseHideSessionControls:` if you are implementing this
/// method.
/// @see CBIOSession
-(void) cobrowseShowSessionControls: (nonnull CBIOSession*) session;

/// Implement this method to remove the controls you showed in `-cobrowseShowSessionControls:`
-(void) cobrowseHideSessionControls: (nonnull CBIOSession*) session;

/// Implement this method to filter the set of windows that cobrowse will capture in its
/// output for the support agent. Note this is separate from the redaction system that allows
/// you to block out specific views from the support agent.
/// @param window The window is question
-(bool) cobrowseShouldCaptureWindow: (nonnull UIWindow*) window API_AVAILABLE(ios(9));

/// Implement this method to provide a list of views for the given view controller
/// that should not be visible in the agent view.
/// Note: you can also impelement the `CobrowseIORedacted` protocol on your view controller
/// to provide the views to redact there instead.
/// @param vc The UIViewController subclass to redact
/// @see CobrowseIORedacted
-(nonnull NSArray<UIView*>*) cobrowseRedactedViewsForViewController: (nonnull UIViewController*) vc API_AVAILABLE(ios(9));

@end
