# CobrowseIO SDK - Remote Screenshare Service

With [Cobrowse.io](https://cobrowse.io)'s screen sharing technology for mobile apps you can see *exactly* what your customer sees on their mobile device, and provide realtime annotations to help solve customer support queries quickly.

## Try it out

You can try the Cobrowse.io service for **free** and **without signing up for an account**. Just follow the installation instructions below, then head to <https://cobrowse.io/trial> to use the trial dashboard.

These instructions will install a binary distribution of the Cobrowse.io SDK. Customers with a paid subscription can request source code access by [emailing us](mailto:hello@cobrowse.io).

## Installation

We recommend installing the CobrowseIO SDK using Cocoapods, add this to your Podfile:

```
pod 'CobrowseIO'
```

*Don't forget to run `pod install` after you've edited your Podfile.*

**Don't like Cocoapods?**

You can use the SDK by copying the framework from this repository directly to your project, and adding it to the binaries to be linked into your app in the "Build Phases" build step.

## Basic Setup

The CobrowseIO SDK can be used in your Objective C or Swift projects by:
1. Adding the appropriate code below into a view controller in your app.
2. Hook up a button to trigger the action (or call it programatically if you prefer).

### Swift
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

### Objective C
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

## Configuration

Once you've tested out your app using the trial dashboard you're ready to create an account and add in the free license key to your app. This will associate sessions from your mobile app with your Cobrowse account.

### Add your license key
Once you've signed up for a free account at [cobrowse.io](https://cobrowse.io), you'll be able to find your license key at <https://cobrowse.io/dashboard/settings>. Add this to your SDK setup:
```objective-c
- (BOOL)application:(UIApplication*) application didFinishLaunchingWithOptions:(NSDictionary*) launchOptions
{
    CobrowseIO.instance.license = @"<your license key here>";
    return YES;
}
```
**Important:** Do this in your `application:didFinishLaunchingWithOptions:` implementation to make sure your device shows up in your dashboard right away.

## Agent Initiated Sessions

Cobrowse.io also support sessions that initiated by support agents, via their dashboard. To do this we use a push notification to the device. To set up agent initiated sessions:

1. Set up Firebase Cloud Messaging for your app. See the latest Firebase documentation for instructions.
2. Enter your Server Key from the FCM admin settings into the Cobrowse account settings at: https://cobrowse.io/dashboard/settings
3. Request push permission from the user whenever is appropriate for your app:

```objective-c
- (void)applicationDidBecomeActive:(UIApplication*) application {
    [application registerUserNotificationSettings: [UIUserNotificationSettings settingsForTypes:(UIUserNotificationTypeBadge | UIUserNotificationTypeSound | UIUserNotificationTypeAlert) categories:nil]];
    [application registerForRemoteNotifications];
}
```

## Requirements

* iOS 9.0 or later
