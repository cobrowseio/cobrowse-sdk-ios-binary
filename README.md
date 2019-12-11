# Cobrowse.io - iOS Native SDK

Cobrowse.io for iOS supports iOS 9.0+.

Cobrowse.io is 100% free and easy to try out in your own apps. Please see full documentation at [https://cobrowse.io/docs](https://cobrowse.io/docs).

Try our **online demo** at the bottom of our homepage at <https://cobrowse.io/#tryit>.

## Installation

We recommend installing the Cobrowse.io SDK using Cocoapods. Add this to your Podfile:

```ruby
pod 'CobrowseIO'
```

*Don't forget to run `pod install` after you've edited your Podfile.*

#### Swift
```swift
import CobrowseIO

func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool
{
    CobrowseIO.instance().license = "<your license key here>"
    CobrowseIO.instance().start()
    return true
}
```

#### Objective C
```objective-c
@import CobrowseIO;

- (BOOL)application:(UIApplication*) application didFinishLaunchingWithOptions:(NSDictionary*) launchOptions
{
    CobrowseIO.instance.license = @"<your license key here>";
    [CobrowseIO.instance start];
    return YES;
}
```
*Important: Do this in your `application:didFinishLaunchingWithOptions:` implementation to make sure your device shows up in your dashboard right away.*

### Add your License Key

Please register an account and generate your free License Key at <https://cobrowse.io/dashboard/settings>.

This will associate sessions from your mobile app with your Cobrowse account.

### Add device metadata

To help you identify, search, and filter devices in your Cobrowse dashboard, it's helpful to specify any meaningful metadata. We recommend specifying the end-user's email if available.

You may add any custom key/value pairs you'd like, and they will all be searchable and filterable in your online dashboard. We've added a few placeholders for convenience only - all fields are optional.

#### Swift
```swift
import CobrowseIO

func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool
{
    CobrowseIO.instance().license = "<your license key here>"

    print("Cobrowse device id:  \(CobrowseIO.instance().deviceId)")

    CobrowseIO.instance().customData = [
        kCBIOUserIdKey: "<your_user_id>" as NSObject,
        kCBIOUserNameKey: "<your_user_name>" as NSObject,
        kCBIOUserEmailKey: "<your_user_email>" as NSObject,
        kCBIODeviceIdKey: "<your_device_id>" as NSObject,
        kCBIODeviceNameKey: "<your_device_name>" as NSObject
    ]

    return true
}
```

#### Objective C
```objective-c
@import CobrowseIO;

- (BOOL)application:(UIApplication*) application didFinishLaunchingWithOptions:(NSDictionary*) launchOptions
{
    CobrowseIO.instance.license = @"<your license key here>";

    NSLog(@"Cobrowse device id: %@", CobrowseIO.instance.deviceId);

    CobrowseIO.instance.customData = @{
        kCBIOUserIdKey: @"<your_user_id>",
        kCBIOUserNameKey: @"<your_user_name>",
        kCBIOUserEmailKey: @"<your_user_email>",
        kCBIODeviceIdKey: @"<your_device_id>",
        kCBIODeviceNameKey: @"<your_device_name>"
    };

    return YES;
}
```

## Try it out

Once you have your app running in the iOS Simulator or on a physical device, navigate to <https://cobrowse.io/dashboard> to see your device listed. You can click the "Connect" button to initiate a Cobrowse session!

## Optional features

[Initiate sessions with push](./docs/initiate-with-push.md)

[Use 6-digit codes](./docs/user-generated-codes.md)

[Redact sensitive data](./docs/redact-sensitive-data.md)

[Requiring acceptance from the user](./docs/require-user-consent.md)

[Customizing the interface](./docs/customizing-the-interface.md)

[Full device screenshare](./docs/full-device-screenshare.md)

## Questions?
Any questions at all? Please email us directly at [hello@cobrowse.io](mailto:hello@cobrowse.io).

## Requirements

* iOS 9.0 or later
