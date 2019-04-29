# Requiring user consent (optional)

Please see full documentation at [https://cobrowse.io/docs](https://cobrowse.io/docs).

Try our **online demo** at the bottom of our homepage at <https://cobrowse.io/#tryit>.

## Implementation

You may want to ask the user for permission to view their screen before starting a session. The SDK provides hooks via `CobrowseIODelegate` for you to handle remote session requests:

```objective-c
@implementation CBAppDelegate // should implement CobrowseIODelegate

- (BOOL)application:(UIApplication*) application didFinishLaunchingWithOptions:(NSDictionary*) launchOptions {
    CobrowseIO.instance.delegate = self;
    // ... the rest of your app setup
    return YES;
}

-(void) cobrowseHandleSessionRequest:(CBIOSession*) session {
    // show your own UI here
    // call [session activate: <callback>] to accept and start the session
    // provide a callback to handle any errors during session initiation
    [session activate: nil];
}

@end
```

## Questions?
Any questions at all? Please email us directly at [hello@cobrowse.io](mailto:hello@cobrowse.io).
