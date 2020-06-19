# Cobrowse.io - iOS Native SDK

Cobrowse.io is 100% free and easy to try out in your own apps. Please see full documentation at [https://docs.cobrowse.io](https://docs.cobrowse.io).

Try our **online demo** at the bottom of our homepage at <https://cobrowse.io/#tryit>.

## Installation

The Cobrowse SDK for iOS is available for installation via several dependency managers, or as frameworks to integrate directly into your project:

#### Pods
```ruby
pod 'CobrowseIO', '~>2'
```

_Don't forget to run `pod repo update` then `pod install` after you've edited your Podfile._

#### Carthage
```
github "cobrowseio/cobrowse-sdk-ios-binary" ~> 2.0
```

_Don't forget to run `carthage update`  after you've edited your Cartfile._

#### Manual
Frameworks are available for manual integration into your Xcode projects from:

```
https://github.com/cobrowseio/cobrowse-sdk-ios-binary/releases
```

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

#### Objective-C
```objectivec
@import CobrowseIO;

- (BOOL)application:(UIApplication*) application didFinishLaunchingWithOptions:(NSDictionary*) launchOptions
{
    CobrowseIO.instance.license = @"<your license key here>";
    [CobrowseIO.instance start];
    return YES;
}
```

_Important: Do this in your `application:didFinishLaunchingWithOptions:` implementation to make sure your device shows up in your dashboard right away._

### Add your License Key

Please register an account and generate your free License Key at [https://cobrowse.io/dashboard/settings](https://cobrowse.io/dashboard/settings).

This will associate sessions from your mobile app with your Cobrowse account.

## Try it out

Once you have your app running in the iOS Simulator or on a physical device, navigate to [https://cobrowse.io/dashboard](https://cobrowse.io/dashboard) to see your device listed. You can click the "Connect" button to initiate a Cobrowse session!

## Full device capabilities

Cobrowse.io optionally supports full device screen sharing on iOS. 

[Full device capabilities](https://docs.cobrowse.io/sdk-features/advanced-features/ios/full-device-screenshare)

## Requirements

* iOS 9.0 or later

## SDK features

[Identify your devices](https://docs.cobrowse.io/sdk-features/identify-your-devices)

[Use 6-digit codes](https://docs.cobrowse.io/sdk-features/6-digit-codes)

[Redact sensitive data](https://docs.cobrowse.io/sdk-features/redact-sensitive-data)

[Customize the interface](https://docs.cobrowse.io/sdk-features/customize-the-interface)

[Advanced features](https://docs.cobrowse.io/sdk-features/advanced-features)

## Questions?
Any questions at all? Please email us directly at [hello@cobrowse.io](mailto:hello@cobrowse.io).
