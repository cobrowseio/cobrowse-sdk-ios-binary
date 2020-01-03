# Customizing the interface (optional)

Please see full documentation at [https://cobrowse.io/docs](https://cobrowse.io/docs).

Try our **online demo** at the bottom of our homepage at <https://cobrowse.io/#tryit>.

## Implementation

You can fully customize the interface for a Cobrowse session. The SDK provides hooks via `CobrowseIODelegate` for you to render your own interface:

#### Swift
```swift
import CobrowseIO

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate, CobrowseIODelegate {

    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
        CobrowseIO.instance().delegate = self
        // ... the rest of your app setup
        return true
    }

    func cobrowseShowSessionControls(_ session: CBIOSession) {
        // You can render controls however you like here.
        // One option is to add our sample end session UI defined below.
        if (indicatorInstance == nil) {
            indicatorInstance = self.defaultSessionIndicator(container: UIApplication.shared.keyWindow!)
        }
        indicatorInstance?.isHidden = false
    }

    func cobrowseHideSessionControls(_ session: CBIOSession) {
        indicatorInstance?.isHidden = true
    }

    // sample end session UIView, constructor, and tap gesture recognizer implementation
    var indicatorInstance : UIView? = nil
    func defaultSessionIndicator(container: UIView) -> UIView {
        let indicator : UILabel = UILabel()
        indicator.backgroundColor = UIColor(red: 1.0, green: 0.0, blue: 0.0, alpha: 0.7)
        indicator.text = "End Session"
        indicator.isUserInteractionEnabled = true
        indicator.textAlignment = .center
        indicator.font.withSize(UIFont.smallSystemFontSize)
        indicator.textColor = .white
        indicator.layer.cornerRadius = 10
        indicator.clipsToBounds = true
        indicator.translatesAutoresizingMaskIntoConstraints = false
        container.addSubview(indicator)

        indicator.widthAnchor.constraint(equalToConstant: 200).isActive = true
        indicator.heightAnchor.constraint(equalToConstant: 40).isActive = true
        indicator.centerXAnchor.constraint(equalTo: container.centerXAnchor).isActive = true
        indicator.bottomAnchor.constraint(equalTo: container.bottomAnchor, constant: -20).isActive = true

        let tapRecognizer : UITapGestureRecognizer = UITapGestureRecognizer(target: self, action: #selector(indicatorTapped(_:)))
        tapRecognizer.numberOfTapsRequired = 1
        indicator.addGestureRecognizer(tapRecognizer)
        return indicator
    }
    @objc
    func indicatorTapped(_ sender: UITapGestureRecognizer) {
        CobrowseIO.instance().currentSession()?.end(nil)
    }

}
```

#### Objective C
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
