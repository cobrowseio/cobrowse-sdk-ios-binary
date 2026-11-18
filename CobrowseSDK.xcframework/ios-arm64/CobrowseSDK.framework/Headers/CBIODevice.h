#import <Foundation/Foundation.h>
#import "CBIORESTResource.h"

/// The state of the device's connection to Cobrowse, which agents use to start sessions with it.
///
/// - See: ``CBIODevice/connectionState``
typedef NS_ENUM(NSInteger, CBIODeviceConnectionState) {
    /// The SDK is not trying to connect: it is not started, ``CobrowseIO/stop`` was called, or
    /// ``CobrowseIO/registration`` is turned off.
    CBIODeviceConnectionStateDisconnected = 0,
    /// The SDK has started and is trying to connect for the first time. A device that is reachable
    /// only by push notification, because the account has device sockets switched off, is given no
    /// connection to open and stays here.
    CBIODeviceConnectionStateConnecting,
    /// The device is connected. Agents can start sessions with it.
    CBIODeviceConnectionStateConnected,
    /// The connection was lost after it had been made. The SDK reconnects by itself.
    CBIODeviceConnectionStateReconnecting,
    /// The account's configuration does not let agents start sessions with this device: device
    /// sockets are switched off (and the device is not reachable by push notification), agent-started
    /// sessions are switched off, or the platform is not licensed. The state stays here until a
    /// registration says the device is connectable again.
    CBIODeviceConnectionStateDisabled,
};

/// This device as Cobrowse knows it: see ``CobrowseIO/device``.
@interface CBIODevice : CBIORESTResource

/// The current state of the device's connection to Cobrowse.
///
/// For the instance obtained from ``CobrowseIO/device``, the state is evaluated when accessed, so
/// it always reflects the current state. Device instances representing a previous state, such as
/// the one passed to ``CobrowseIODelegate/cobrowseDeviceConnectionStateDidChange:previousDevice:``,
/// retain the state from when they were created. May be read from any thread.
@property (readonly) CBIODeviceConnectionState connectionState;

/// The APNS push notification token for this device, as set by the deprecated
/// `+[CobrowseIO setDeviceToken:]`. Nil once another push token is registered.
@property (nullable) NSData* token __deprecated_msg("Firebase pushes to APNS tokens stop working on September 29, 2027. Register the Firebase installation ID as the push token instead.");

@end
