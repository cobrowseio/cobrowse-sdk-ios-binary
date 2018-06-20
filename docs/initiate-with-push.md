# Initiate with push (optional)

Please see full documentation at [https://cobrowse.io/docs](https://cobrowse.io/docs).

Try our **online demo** at the bottom of our homepage at <https://cobrowse.io/#tryit>.

## Implementation

These are the native-side requirements on iOS to initiate sessions with push. More info at <https://cobrowse.io/docs#initiate-with-push>

If you are already using push notifications in your app, there is nothing further required on the native side.

If you are not already using push notifications in your app, please enable them under Capabilities in Xcode and request push permission from the user whenever is appropriate:

```objective-c
- (void)applicationDidBecomeActive:(UIApplication*) application {
    [application registerUserNotificationSettings: [UIUserNotificationSettings settingsForTypes:(UIUserNotificationTypeBadge | UIUserNotificationTypeSound | UIUserNotificationTypeAlert) categories:nil]];
    [application registerForRemoteNotifications];
}
```

## Questions?
Any questions at all? Please email us directly at [hello@cobrowse.io](mailto:hello@cobrowse.io).