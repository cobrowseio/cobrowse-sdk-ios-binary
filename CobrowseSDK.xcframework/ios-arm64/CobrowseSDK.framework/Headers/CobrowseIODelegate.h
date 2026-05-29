#import <Foundation/Foundation.h>

@class UIWindow;
@class UIViewController;
@class UIView;
@class CBIOSession;
@class CBIOHighlight;

/// Implement this delegate protocol to customise Cobrowse's default behaviour.
@protocol CobrowseIODelegate <NSObject>

/// Called when a new session is started, or an existing session changes state.
/// 
/// - Parameter session The session that is changing
-(void) cobrowseSessionDidUpdate: (nonnull CBIOSession*) session;

/// Called when a session will end.
///
/// - Parameter session The session that ended
-(void) cobrowseSessionDidEnd: (nonnull CBIOSession*) session;

@optional

/// Called when one or multiple metrics properties change.
///
/// - Parameter session The session which metrics changed
-(void) cobrowseSessionMetricsDidUpdate: (nonnull CBIOSession*) session;

/// Called when a session is first loaded from the server, either via 6 digit code or connection
/// from an agent.
///
/// - Parameter session The session that ended
-(void) cobrowseSessionDidLoad: (nonnull CBIOSession*) session;

/// Implement this method to handle cases where screen capture fails. On MacOS this is likely due
/// to missing system permissions required for capturing the screen.
/// - Parameters:
///    - session The session the failure occurred in
///    - err The reason for the failure
-(void) cobrowseScreenCaptureDidFailForSession: (nonnull CBIOSession*) session withError: (nonnull NSError*) err API_AVAILABLE(macos(10.10));

/// Implement this method to override the default session acceptance prompt. The session
/// passed to this method will be in the `authorizing` state, when you have gained
/// confirmation from the user, you should call either ``CBIOSession/activate:``  or
/// ``CBIOSession/end:`` to approve or reject the session.
///
/// - Parameter session The incoming session to approve or reject
-(void) cobrowseHandleSessionRequest: (nonnull CBIOSession*) session;

/// Implement this method to override the default remote control acceptance prompt.
/// When you have gained confirmation from the user, you should call ``CBIOSession/setRemoteControl:callback:``
/// and pass either ``CBIORemoteControlState/on`` or ``CBIORemoteControlState/rejected``
/// to approve or reject the remote control request.
///
/// - Parameter session The session that has been requested to activate remote control
-(void) cobrowseHandleRemoteControlRequest: (nonnull CBIOSession*) session;

/// - **WARNING**: This API is experimental and not covered by semantic versioning yet!
/// Implement this method to override the default full device request prompt.
/// On iOS you are responsible for displaying an `RPSystemBroadcastPickerView` to the user.
/// On macOS you are responsible to set the session full device state to either
/// ``CBIOFullDeviceState/on`` or ``CBIOFullDeviceState/rejected``.
///
/// - Parameter session The session that has requested full device mode
-(void) cobrowseHandleFullDeviceRequest: (nonnull CBIOSession*) session;

/// Implement this method to override the default session indicator. This method may be
/// called several times as the session progresses through its lifecycle, so you may need
/// to adjust your UI accordingly. See the available session methods to inspect session state.
///
/// - Note: you should also implement ``CobrowseIODelegate/cobrowseHideSessionControls:`` if you are implementing this method.
/// - See: CBIOSession
-(void) cobrowseShowSessionControls: (nonnull CBIOSession*) session;

/// Implement this method to remove the controls you showed in ``CobrowseIODelegate/cobrowseShowSessionControls:``
-(void) cobrowseHideSessionControls: (nonnull CBIOSession*) session;

#if TARGET_OS_IPHONE

/// Implement this method to override the default highlight UI for UIKit views.
/// - Note: Both ``CobrowseIODelegate/cobrowseShowHighlight:onDismiss:`` and ``CobrowseIODelegate/cobrowseHideHighlight`` need to be implemented
/// - See: ``CobrowseIO/highlightStyle`` to override highlights for SwiftUI view trees
/// - Parameters:
///    - highlight: An object containing information about the highlight
///    - onDismiss: A callback to call when the highlight is dismissed.
-(void)cobrowseShowHighlight:(nonnull CBIOHighlight *)highlight onDismiss:(void (^ _Nonnull)(void))onDismiss NS_SWIFT_NAME(cobrowseShowHighlight(_:onDismiss:));;

/// Hide any highlight UI from previous calls to `cobrowseShowHighlight:onDismiss:`
/// - See: Both ``CobrowseIODelegate/cobrowseShowHighlight:onDismiss:`` and ``CobrowseIODelegate/cobrowseHideHighlight`` need to be implemented
-(void)cobrowseHideHighlight;

#endif

/// Implement this method to filter the set of windows that Cobrowse will capture in its
/// output for the support agent.
///
/// - Note: this is separate from the redaction system that allows you to block out specific views from the support agent.
/// - Parameter window The window in question
-(bool) cobrowseShouldCaptureWindow: (nonnull UIWindow*) window API_AVAILABLE(ios(9));

/// Implement this method to provide a list of views for the given view controller
/// that should not be visible in the agent view.
///
/// - Note: you can also implement the ``CobrowseIORedacted`` protocol on your view controller to provide the views to redact there instead.
/// - Parameter vc The UIViewController subclass to redact
/// - See: ``CobrowseIORedacted``
-(nonnull NSArray<UIView*>*) cobrowseRedactedViewsForViewController: (nonnull UIViewController*) vc API_AVAILABLE(ios(9));

/// Implement this method to provide a list of views for the given view controller that should
/// always be visible in the agent view.
///
/// - Note: you can also implement the ``CobrowseIOUnredacted`` protocol on your view controller to provide the views to unredact there instead.
/// - Parameter vc The UIViewController subclass to unredact
/// - See: ``CobrowseIOUnredacted``
-(nonnull NSArray<UIView*>*) cobrowseUnredactedViewsForViewController: (nonnull UIViewController*) vc API_AVAILABLE(ios(9));

@end
