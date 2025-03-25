#import <Foundation/Foundation.h>

#import "CBIOSession.h"
#import "CBIODevice.h"
#import "CBIOAgent.h"
#import "CBIORESTResource.h"
#import "CBIOTouchEvent.h"
#import "CBIOMouseEvent.h"
#import "CBIOKeyPress.h"

#import "CBIOSelector.h"
#import "CBIOSelectorIndex.h"

#import "CobrowseIODelegate.h"
#import "CobrowseIORedacted.h"
#import "CobrowseIOUnredacted.h"

#if TARGET_OS_IOS
#import "CBIOURLSession.h"
#import "CBIOTouch.h"
#import "CBIOResponder.h"
#import "CobrowseIOReplayKitExtension.h"
#endif

static NSString* _Nonnull const CBIOUserIdKey = @"user_id";
static NSString* _Nonnull const CBIOUserEmailKey = @"user_email";
static NSString* _Nonnull const CBIOUserNameKey = @"user_name";
static NSString* _Nonnull const CBIODeviceIdKey = @"device_id";
static NSString* _Nonnull const CBIODeviceNameKey = @"device_name";


/// CobrowseIO screenshare main obejct.
/// @see `+instance`
@interface CobrowseIO : NSObject

/// The license key available in your Cobrowse.io dashboard. Setting this property is always
/// required for a Cobrowse.io integration.
@property (nonnull) NSString* license;

/// The CobrowseIO API service to register with, default to the hosted version. Enterprise
/// users should set this to thier own API.
@property (nonnull) NSString* api;

/// Sets metadata attached to this device that will be displayed and filterable in the web
/// dashboard. This allows you to find and identify your users devices quickly. We recommend
/// adding information such as your logged in users email addresses or user IDs here.
@property (nonnull) NSDictionary<NSString*, NSString*>* customData;

/// The capabilities available to sessions. It defaults to all the capabilities allowed by the
/// device.
@property (nonnull) NSArray<NSString*>* capabilities;

/// The CSS-like selectors that define view to be redacted
@property (nonnull) NSArray<NSString*>* redactedViews API_AVAILABLE(ios(11));

/// The CSS-like selectors that define view to be unredacted
@property (nonnull) NSArray<NSString*>* unredactedViews API_AVAILABLE(ios(11));

/// The CSS selectors which will be redacted within Webviews
@property (nonnull) NSArray<NSString*>* webviewRedactedViews API_AVAILABLE(ios(11));

/// By default, when the SDK starts it will register the device to your account and share its
/// connectivity state. This provides the dashboard with a list of devices which are online
/// and ready to connect.
/// If you don't need to see a list of devices in your dashboard, e.g. your sessions start only
/// using @c [CobrowseIO.instance @c createSession:] or via @c CBIOViewController ,
/// then you can stop the SDK from registering the device and its status by setting
/// the @c registration option with a value of @c false .
@property BOOL registration;

/// Implement the CobrowseIO delegate protocol to customise advanced behaviours of Cobrowse.
/// It is *not* required to implement the delegate to use Cobrowse.
/// @see CobrowseIODelegate
@property (nullable) id<CobrowseIODelegate> delegate;

/// URLSession used when making network request.
@property (nonnull) NSURLSession* urlSession API_AVAILABLE(ios(15.0), macos(12.0));

/// The unique device ID generated by the Cobrowse SDK. This cannot be changed.
@property (readonly, nonnull) NSString* deviceId;

/// The device object that represents this device. It's unliekly you need to use this.
@property (readonly, nonnull) CBIODevice* device;

/// The global Cobrowse instance. You should always use this instance to interact with the Cobrowse APIs.
+(nonnull instancetype) instance;

/// Do not use this method, use `-instance`
/// @see `-instance`
-(nonnull instancetype) init NS_UNAVAILABLE;

/// Call `-start` when you have configured Cobrowse and would like to start accepting incoming
/// session requests. Calling start will register the device into your Cobrowse dashboard and
/// open a socket to accept incoming connection requests from your support agents.
///
/// You can delay this call until just before you need Cobrowse to run if you wish. For example,
/// when using 6 digit code initiated sessions you may choose to call start only when your UI
/// to show the code is about to be presented. Note: You must call start() before you can
/// generate a 6 digit code.
///
/// @see `-stop`
-(nonnull instancetype) start;

/// Stops Cobrowse, deregistering the device from the server and closing any open connections.
/// After this method has been called you can no longer start sessions either via the dashboard,
/// or via a 6 digit code, until you call `-start` again.
///
/// @see `-start`
/// @see `-stop:`
-(nonnull instancetype) stop;

/// Same as `-stop` but takes a callback so oyu are notified when the stop is completed.
///
/// @see `-stop:`
-(nonnull instancetype) stop: (void (^_Nonnull)(NSError* _Nullable err)) callback;

/// Tests whether Cobrowse has been sarted already
-(bool) isStarted;

/// Creates a new screenshare session. Sessions will start in a 'pending' state. To activate a
/// session an agent must have joined and all required consent given by the user. Pending sessions
/// contain a six digit `CBIOSession -code` that can be displayed for the user to give to a support agent.
/// @param callback A callback containing the created session, or an error.
-(nonnull instancetype) createSession: (nullable CBErrorSessionBlock) callback;

/// Fetches a session by its ID or by a 6 digit code. When loaded the callback will be invoked
/// with the session object, or an error if the session could not be fetched.
/// @param idOrCode A session ID, or a 6 digit code.
/// @param callback A callback containing the created session, or an error.
-(nonnull instancetype) getSession: (nonnull NSString*) idOrCode callback: (nullable CBErrorSessionBlock)callback;

/// Gets the current screenshare session. This may be a session waiting to start, the currently active session,
/// or may be nil if no session has been created.
/// @return The current session
-(nullable CBIOSession*) currentSession;

/// The Cobrowse SDK version
-(nonnull NSString*) version;

@end


@interface CobrowseIO (Push)

/// Associate a APNS token with this device to be seen within the Cobrowse dashboard
+(void) setDeviceToken:(nonnull NSData *)token API_UNAVAILABLE(macos);

/// Tests whether a push notification was generated by Cobrowse.
+(BOOL) isCobrowseNotification: (nonnull NSDictionary*) userInfo;

/// Call this when your push handler recieves a push notification. Non-cobrowse push
/// notifications will be ignored.
+(void) onPushNotification: (nonnull NSDictionary*) userInfo;

@end
