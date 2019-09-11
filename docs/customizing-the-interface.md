# Customizing the interface (optional)

Please see full documentation at [https://cobrowse.io/docs](https://cobrowse.io/docs).

Try our **online demo** at the bottom of our homepage at <https://cobrowse.io/#tryit>.

## Implementation

You can fully customize the interface for a Cobrowse session. The SDK provides hooks via `CobrowseIODelegate` for you to render your own interface:

```objective-c
@implementation CBAppDelegate // should implement CobrowseIODelegate

- (BOOL)application:(UIApplication*) application didFinishLaunchingWithOptions:(NSDictionary*) launchOptions {
    CobrowseIO.instance.delegate = self;
    // ... the rest of your app setup
    return YES;
}

- (void)cobrowseShowSessionControls:(CBIOSession*) session {
    // You can render controls however you like here. One option is to add a floating
    // control visible over all other controls by adding it as a subview of the keyWindow
    [UIApplication.sharedApplication.keyWindow addSubview: self.myCustomCobrowseView];
}

- (void)cobrowseHideSessionControls:(CBIOSession*) session {
    [self.myCustomCobrowseView removeFromSuperview];
}

@end
```

## Questions?
Any questions at all? Please email us directly at [hello@cobrowse.io](mailto:hello@cobrowse.io).
