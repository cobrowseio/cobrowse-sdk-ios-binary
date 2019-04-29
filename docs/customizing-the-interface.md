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

- (UIView*) cobrowseControlsForSession:(CBIOSession*) session {
    UILabel* label = [[UILabel alloc] initWithFrame:CGRectMake(50, 50, 100, 50)];
    label.backgroundColor = UIColor.redColor;
    label.textColor = UIColor.whiteColor;
    label.text = @"STOP";
    // also attach gesture recognizers etc...
    return label;
}

@end
```

## Questions?
Any questions at all? Please email us directly at [hello@cobrowse.io](mailto:hello@cobrowse.io).
