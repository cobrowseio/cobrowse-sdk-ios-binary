# Cobrowse.io SDK for iOS

Cobrowse.io for iOS supports iOS 9.0+. Learn more at [https://cobrowse.io](https://cobrowse.io).

Clients may access and integrate full source code for our SDKs directly upon request. 

## Try it out

Please try our **online demo** at the bottom of our homepage at <https://cobrowse.io/#tryit>.

Cobrowse.io is 100% free and easy to try out in your apps. Please follow the installation instructions below, then head to <https://cobrowse.io/trial> to access the trial dashboard.

These instructions will install a binary distribution of the Cobrowse.io SDK. Clients may also access and integrate full source code for our SDKs directly by emailing us [hello@cobrowse.io](mailto:hello@cobrowse.io).

## Installation

We recommend installing the Cobrowse.io SDK using Cocoapods, add this to your Podfile:

```
pod 'CobrowseIO'
```

*Don't forget to run `pod install` after you've edited your Podfile.*

**Don't like Cocoapods?**

You can use the SDK by copying the framework from this repository directly to your project, and adding it to the binaries to be linked into your app in the "Build Phases" build step.

## Configuration

By default, your app will use our trial license key and trial dashboard at <https://cobrowse.io/trial>.

This will work fine for user-initiated sessions (see below), but agent-initiated sessions (see below) will require you to first register a free account and generate a unique license key. This will associate sessions from your mobile app with your Cobrowse.io account.

### Add your license key
Once you've signed up for a free account at <https://cobrowse.io/register>, you'll be able to find your license key at <https://cobrowse.io/dashboard/settings>. Add this to your SDK setup:

#### Swift
```swift
import CobrowseIO

func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool 
{
    CobrowseIO.instance().license = "<your license key here>"
    return true
}
```

#### Objective C
```objective-c
@import CobrowseIO;

- (BOOL)application:(UIApplication*) application didFinishLaunchingWithOptions:(NSDictionary*) launchOptions
{
    CobrowseIO.instance.license = @"<your license key here>";
    return YES;
}
```
**Important:** Do this in your `application:didFinishLaunchingWithOptions:` implementation to make sure your device shows up in your dashboard right away.


## Agent-initiated Sessions

Without any additional UI or logic in your app, authenticated support agents are able to initiate sessions remotely via our online dashboard. To do this in an efficient way, we send an invisible push notification to the target device with a custom payload.

To setup agent-initiated sessions:

1. Set up Firebase Cloud Messaging for your app. See the latest Firebase documentation for instructions at <https://firebase.google.com/docs/cloud-messaging/>.
2. Enter your FCM Server Key from the FCM admin settings into your Cobrowse.io account at https://cobrowse.io/dashboard/settings.
3. If you are not already using push notifications in your app, request push permission from the user whenever is appropriate:

```objective-c
- (void)applicationDidBecomeActive:(UIApplication*) application {
    [application registerUserNotificationSettings: [UIUserNotificationSettings settingsForTypes:(UIUserNotificationTypeBadge | UIUserNotificationTypeSound | UIUserNotificationTypeAlert) categories:nil]];
    [application registerForRemoteNotifications];
}
```

** Free License Key is required to see active devices listed in your account's online dashboard. Sign up at <https://cobrowse.io/register> and see Configuration above.

## User-initiated Sessions

You may also expose small UI in your app for users to generate a 6-digit code that they pass to an agent over the phone or chat to initiate a session. 

To setup user-initiated sessions:

1. Add the appropriate code below into a view controller in your app.
2. Hook up a button to trigger the action (or call it programatically if you prefer).

#### Swift
```swift
import CobrowseIO

class ExampleViewController: UIViewController {
    var sessionController: CBIOViewController!

    @IBAction func startCobrowse(sender: UIBarButtonItem) {
        self.sessionController = CBIOViewController()
        self.navigationController?.pushViewController(self.sessionController, animated: true)
    }

    // ... the rest of your view controller
}
```

For a full example written in Swift, see our Listr sample app at: https://github.com/cobrowseio/Listr

#### Objective C
```objective-c
@import CobrowseIO;

@implementation ExampleViewController {
    CBIOViewController* sessionController;
}

-(IBAction) startCobrowse:(id)sender {
    sessionController = [[CBIOViewController alloc] init];
    [self.navigationController pushViewController:sessionController animated:YES];
}

// ... the rest of your view controller

@end
```

Make sure you've hooked up a trigger for the `startCobrowse` IBAction that we've just added, then head to <https://cobrowse.io/trial> and enter the 6 digit code that will be generated by your app when you trigger the action!

## Questions?
We want to hear from you! Please email us directly at [hello@cobrowse.io](mailto:hello@cobrowse.io).

## Requirements

* iOS 9.0 or later
