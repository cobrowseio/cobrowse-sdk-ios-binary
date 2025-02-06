# Changelog

All notable changes to this project will be documented in this file. See [standard-version](https://github.com/conventional-changelog/standard-version) for commit guidelines.

## [3.1.0](#) (2025-02-06)


### Features

* Add support for custom URLSession ([#143](#)) ([70df37a](#))


### Bug Fixes

* use shared URLSession to allow request filtering via NSURLProtocol ([#142](#)) ([b889fea](#))

## [3.0.0](#) (2025-01-27)


### ⚠ BREAKING CHANGES

* We have merged the Broadcast Extension framework into the main CobrowseSDK framework. You may need to update your project if you are using the Cobrowse full device mode for iOS.
* remove touch filtering delegate methods
* Removes the default 6 digit code UI and view controller from the SDK
* Removes the boolean versions of the fullDevice setter / getters. You should now use the more descriptive enum versions instead.
* The built Frameworks have been renamed to `CobrowseSDK` from `CobrowseIO` so that the main SDK class and the Framework names are different. This previously caused issues with Swift usage (which doesn't really allow for target naming that share exported symbol names). This will require updating your imports or build steps that use the CobrowseIO naming.
* Updated the minimum support Cobrowse API version to 1.21.0
* The built-in intercom integration support has been removed. To continue to support cobrowse Intercom integrations in your apps please set an Intercom user property called `CobrowseID` to the `CobrowseIO.instance.deviceId` value.
* `customData` is now restricted to string values only

- No need to annotate dictionary as `[String : Object]
- removed `k` prefix as it is an older Obj-C convention

**Before**
```swift
cobrowse.customData = [
    kCBIOUserEmailKey: "ios@example.com",
    kCBIODeviceNameKey: "iOS Demo"
] as [String : NSObject]
```

**After**
```swift
cobrowse.customData = [
    CBIOUserEmailKey: "ios@example.com",
    CBIODeviceNameKey: "iOS Demo"
]
```
* SwiftUI support: the `redacted()` view modifier for SwiftUI was renamed to `cobrowseRedacted()` to prevent namespace clashes with other libraries 

### Features

* invoke SDK callbacks on the main thread ([#139](#)) ([4af7ce0](#))
* Make cobrowseShouldAllow methods private ([8525fd0](#))
* Merge extension framework into one CobrowseSDK framework ([dd138cd](#))
* only allow strings as customData ([a71c9ec](#))
* Remove automatic intercom integration ([#123](#)) ([fddceb6](#))
* Remove bool versions of full device ([5a122f3](#))
* Remove default code and session UI ([1376d36](#))
* Rename Frameworks to CobrowseSDK ([cc7401d](#))
* Rename redacted view modifier to cobrowseRedacted ([e3aded1](#))
* Update minimum API version to 1.21.0 ([#128](#)) ([ef27eb0](#))
* Use URLSession for iOS 13 & macOS 10.15 or above ([#135](#)) ([9af99fa](#))

### [2.33.2](#) (2024-11-13)


### Bug Fixes

* don't specify default port numbers (443 or 80) in the `Host` header ([#133](#)) ([a5b32c3](#))

### [2.33.1](#) (2024-10-09)

## [2.33.0](#) (2024-10-04)


### Features

* add redactedViews and unredactedViews APIs for setting selectors ([#121](#)) ([3e030f5](#))
* use os_log based logging ([#120](#)) ([159edf2](#))

### [2.32.3](#) (2024-09-25)


### Bug Fixes

* catch invalid selectors ([284681d](#))

### [2.32.2](#) (2024-09-20)


### Bug Fixes

* fix binary compatibility with newer Swift versions ([715d41f](#))

### [2.32.1](#) (2024-09-14)


### Bug Fixes

* optimisations for dashboard selectors ([19477cf](#))

## [2.32.0](#) (2024-09-11)


### Features

* SwiftUI dashboard redaction support ([#115](#)) ([313ab0a](#))


### Bug Fixes

* remote scrolling in WKWebView on iOS 17.4+ ([#113](#)) ([2af1a0b](#))
* remove kvo for webview progressing in favor of navigationDelegate for compliance with iOS 18 ([#116](#)) ([390cb7e](#))

### [2.31.2](#) (2024-08-26)


### Bug Fixes

* prevent zombie webviews from dropping frames ([#112](#)) ([dd1b728](#))

### [2.31.1](#) (2024-07-29)


### Bug Fixes

* improve support for rendering Alert views ([#111](#)) ([9ec5c1b](#))

## [2.31.0](#) (2024-07-25)


### Features

* Improvements for webview redaction ([#107](#)) ([e8f3c3a](#))


### Bug Fixes

* ensure we only skip frames when the zoom has been user initiated ([#110](#)) ([38877cf](#))

### [2.30.3](#) (2024-06-06)

### [2.30.2](#) (2024-06-05)


### Bug Fixes

* always use the alternate rendering method with Flutter ([#104](#)) ([a512aa3](#))

### [2.30.1](#) (2024-05-01)


### Bug Fixes

* Remove empty item in PrivacyInfo.xcprivacy ([#103](#)) ([50ff57f](#))

## [2.30.0](#) (2024-04-18)


### Features

* Add support for SwiftUI redaction ([#100](#)) ([7f6c2ff](#))

### [2.29.7](#) (2024-04-15)


### Bug Fixes

* Add privacy manifest to iOS, macOS and Extension frameworks ([#102](#)) ([b19d53e](#))
* fix unwanted green line in the screencasting stream ([#98](#)) ([b870b7b](#))

### [2.29.6](#) (2024-01-17)


### Bug Fixes

* make sure the SDK renders a new frame when the content of `UIImageView` changes ([#97](#)) ([560f739](#))

### [2.29.5](#) (2023-12-20)


### Bug Fixes

* ensure we don't query the dom when webview redaction isn't configured ([#95](#)) ([c954914](#))

### [2.29.4](#) (2023-12-19)


### Bug Fixes

* remove dependency on WKNavigationDelegate to prevent conflicts with error reporting sdks ([#94](#)) ([68009fd](#))

### [2.29.3](#) (2023-12-08)


### Bug Fixes

* fix unredaction edge case when using multiple nested view controllers ([ab71819](#))

### [2.29.2](#) (2023-11-10)

### [2.29.1](#) (2023-11-10)


### Bug Fixes

* remove the usage of [@import](#) within the sdk code ([#89](#)) ([ace2866](#))

## [2.29.0](#) (2023-09-29)


### Features

* Allow capabilities to be set on a session object ([#86](#)) ([a98823a](#))


### Bug Fixes

* Clear currentSession if error is retuned ([#85](#)) ([ee43e58](#))

### [2.28.6](#) (2023-09-11)


### Bug Fixes

* return the device capabilities when the server doesn't support capabilities ([#84](#)) ([8006299](#))

### [2.28.5](#) (2023-09-08)


### Bug Fixes

* ensure data from previous stream is discarded after switching ([#83](#)) ([63109c3](#))

### [2.28.4](#) (2023-08-22)


### Bug Fixes

* ensure full redaction is removed when the keyboard animation is complete ([#81](#)) ([26db78b](#))

### [2.28.3](#) (2023-08-18)


### Bug Fixes

* avoid webview dealloc crash ([#80](#)) ([33232ac](#))
* improve redaction support inside WKWebViews ([#78](#)) ([0517fc8](#))

### [2.28.2](#) (2023-08-07)


### Bug Fixes

* apply workaround for iOS 15 remote touch issues. ([#14](#)) ([e5eedde](#))

### [2.28.1](#) (2023-07-31)


### Features

* allow setting capabilities on launch ([#77](#)) ([cabef31](#))


### Bug Fixes

* improve socket liveness checking ([#76](#)) ([b8cc376](#))

## [2.28.0](#) (2023-07-19)


### Features

* Add redaction support to WKWebViews ([#70](#)) ([24806bb](#))


### Bug Fixes

* rendering issue on iOS 17 beta ([#72](#)) ([ed9c044](#))

### [2.27.4](#) (2023-06-30)


### Bug Fixes

* **push:** Wait for shared application to be available to swizzle token and notification delegate methods ([#69](#)) ([3423fc2](#))
* trigger remote touches on WKWebViews via JavaScript code ([#71](#)) ([6ef985a](#))

### [2.27.3](#) (2023-06-05)


### Bug Fixes

* integration with the Intercom SDK v13 ([#68](#)) ([d26ab7c](#))

### [2.27.2](#) (2023-05-24)


### Bug Fixes

* remove exessive logging ([#67](#)) ([f39bd60](#))

### [2.27.1](#) (2023-05-22)


### Bug Fixes

* redaction does not apply on modal ViewControllers in the full-device mode ([#65](#)) ([4cfcb07](#))
* redaction does not apply when ViewController's layout changes in the full-device mode ([#66](#)) ([df3b237](#))

## [2.27.0](#) (2023-05-01)

### [2.26.4](#) (2023-04-27)

### [2.26.3](#) (2023-04-27)

### [2.26.2](#) (2023-04-27)


### Bug Fixes

* Allow broadcast upload extension to initialise with capabilities ([#64](#)) ([03ba49a](#))

### [2.26.1](#) (2023-04-13)


### Bug Fixes

* annotation and remote control capabilities are off in full-device mode on macOS ([#62](#)) ([6d78502](#))

## [2.26.0](#) (2023-03-28)


### Features

* use Xcode 14.1 ([#53](#)) ([d140090](#))

## [2.25.0](#) (2023-03-09)


### Features

* Support unredaction as a first class SDK feature ([68e7339](#))


### Bug Fixes

* Fix macOS SDK crash: `-[__NSPlaceholderDictionary initWithObjects:forKeys:count:]: attempt to insert nil object from objects[4]`` ([#60](#)) ([c972f51](#))

### [2.24.1](#) (2023-03-06)


### Bug Fixes

* Fix creation of invalid context ([#59](#)) ([8fd489c](#))

## [2.24.0](#) (2023-03-02)


### Features

* allow new sessions to preempt existing ones ([f064dc8](#))
* Capabilities support ([#49](#)) ([6cc45e5](#))
* **capabilities:** add dynamic capabilities functionality ([#55](#)) ([b5f49ea](#))
* support non-FQDN socket URLs ([afa43e4](#))


### Bug Fixes

* encoding glitches on iPad with iOS 15 when in the split-screen mode ([#52](#)) ([567a4ba](#))
* redacted content is displayed after a full device session is ended ([#56](#)) ([ba06718](#))

### [2.23.4](#) (2023-01-17)


### Bug Fixes

* Fix/UI text field redaction ([#47](#)) ([9ecfe89](#))

### [2.23.3](#) (2023-01-16)


### Bug Fixes

* must push before linting as linting fetches from repo ([1298735](#))

### [2.23.2](#) (2023-01-16)


### Bug Fixes

* improve Carthage binary support ([#48](#)) ([6231952](#))

### [2.23.1](#) (2022-12-13)


### Features

* Remove all dependencies from the SDK. *Note*: if you are importing our Framework / XCFramework directly and not via a package manager, you can safely remove the previously required dependencies. If you are using a package manager this should be done automatically on upgrade to this version.


### Bug Fixes

* remove `kCGBitmapByteOrder32Little` CGBitmap option
* Try to fix excessive memory usage in the extension

### [2.22.4](#) (2022-11-08)

### [2.22.3](#) (2022-11-08)

### [2.22.2](#) (2022-11-08)

### [2.22.1](#) (2022-09-21)

## [2.22.0](#) (2022-09-20)


### Features

* Xcode 14 has dropped support for iOS versions below iOS 11, and macOS versions below 10.13, as well as the armv7 and i386 architectures. As such we have also dropped support for those platforms.
* Xcode 14 support


### Bug Fixes

* remote redaction not applying to UITextField in UIAlertController.

### [2.21.2](#) (2022-08-29)

### [2.21.1](#) (2022-08-29)

## [2.21.0](#) (2022-08-29)


### Features

* add ability to switch between window and full-device capturing mechanisms on macOS.
* add new cobrowseShouldAllowTouchEvent and cobrowseShouldAllowKeyEvent callbacks on macOS.
* implement a full-device confirmation prompt on macOS.
* implement localizable strings on macOS.

### [2.20.1](#) (2022-06-14)


### Bug Fixes

* make render method more aware of what's redacted to optimise render strategy

## [2.20.0](#) (2022-06-14)


### Features

* add API and License configuration to the sample app.

## [2.19.0](#) (2022-05-12)


### Features

* lock sessions to devices


### Bug Fixes

* deadlock in the ReplayKit frame source.
* EXC_BAD_ACCESS when working with CVImageBufferRef.
* full-device gets disabled when the ReplayKit suspends broadcasting.

## [2.18.0](#) (2022-04-19)


### Features

* expose new full device APIs
* set full_device state as enum properties


### Bug Fixes

* fix duplicate requests, update delegate api
* simplify broadcast extension check

### [2.17.1](#) (2022-02-07)


### Bug Fixes

* only call loaded event after call completes

## [2.17.0](#) (2022-02-02)


### Features

* add delegate method that's called the first time a session is fetched from the server

### [2.16.4](#) (2022-01-29)


### Bug Fixes

* use XCFramework for broadcast extension via Pods

### [2.16.3](#) (2022-01-28)


### Bug Fixes

* skip custom data updates that match the cached version

### [2.16.2](#) (2022-01-25)


### Bug Fixes

* fix full device mode when session are initiated with full_device already set to true

### [2.16.1](#) (2021-12-08)

## [2.16.0](#) (2021-11-15)


### Features

* send device and custom data on session creation

### [2.15.1](#) (2021-10-12)


### Bug Fixes

* restore macos build

## [2.15.0](#) (2021-09-08)


### Features

* add XCFramework of the broadcast extension

### [2.14.4](#) (2021-09-02)


### Bug Fixes

* the delegate can now be dynamically updates during an active session

### [2.14.3](#) (2021-08-10)


### Bug Fixes

* optimise lazy removal of redaction on next activation when possible

### [2.14.2](#) (2021-08-09)


### Bug Fixes

* ensure redacted views are cleaned up if no longer specified as redacted by the delegate

### [2.14.1](#) (2021-07-28)


### Bug Fixes

* replace redaction layers that are no longer valid

### [2.14.0] - 2021-07-13
- Added `Session.setFullDevice:callback:` API for setting desired full device state

### [2.13.1] - 2021-05-25
- Swift 5.4

### [2.13.0] - 2021-05-21
- Added support for overriding the default remote control consent prompt

### [2.12.0] - 2021-04-28
- Added API for setting full device state

### [2.11.0] - 2021-04-09
- Added API for getting full device state

### [2.9.0] - 2020-11-14
- Added support for arm64 to macOS and iOS simulator builds

### [2.8.0] - 2020-08-24
- Improves streaming quality and responsiveness
- Provides access to agent email when account settings allow
- Add support for requesting consent before using remote control tools

### [2.7.0] - 2020-07-15
- Add delegate method for handling screen capture permissions errors on MacOS
- Fixed an issue that could cause high CPU usage when redaction was active on iOS

### [2.6.5] - 2020-07-11
- Add support for realtime updates of session custom data

### [2.6.4] - 2020-07-10
- Fix for Open GL based layers with default iOS rendering method

### [2.6.3] - 2020-07-08
- Fixed memory leak on macOS

### [2.6.2] - 2020-07-07
- More suppport for Open GL based views on iOS
- Fixed tap gesture recognizer edge case

### [2.6.1] - 2020-06-25
- Multi-monitor support for MacOS

### [2.6.0] - 2020-06-21
- Enable swift module compatibilty
- Adds support for MacOS
- Add XCFramework build

### [2.5.0] - 2020-03-27
- Swift 5.2

### [2.4.0] - 2020-02-19
- Added support for pan gesture recognition

### [2.3.0] - 2020-01-21
- Switch to a faster rendering method

### [2.2.0] - 2020-01-15
- Added support for remote control of WKWebViews

### [2.1.0] - 2019-11-30
- Added support for full device capture

### [2.0.0] - 2019-11-05
- BREAKING: A confirmation prompt is now shown to the user by default when a session is requested.
            You can disable or change this using the Cobrowse delegate methods.
- BREAKING: You must now call [CobrowseIO.instance start] once you have set your license key and are
            for Cobrowse to start listening for session requests.
- BREAKING: The API for overriding session control has changed. It is now two methods `cobrowseShowSessionControls` and `cobrowseHideSessionControls`
- BREAKING: Added many nullability specifiers which will affect the Swift API
- BREAKING: Dropped SocketIO dependency in favour of using websockets directly
- BREAKING: Removed `onStatusTap` from API

### [1.15.0] - 2019-08-09
- Added plist setting for configuring render paths

### [1.14.7] - 2019-08-01
- Dependency version bump

### [1.14.6] - 2019-06-14
- Dynamically adjust render quality

### [1.14.5] - 2019-06-14
- Optimisations to keep devices responsive during continuous gesture

### [1.14.4] - 2019-06-11
- Fix reinitialisation of overlay on some devices caused by rotation event

### [1.14.2] - 2019-06-10
- Fixed potential crash parsing resource from server

### [1.14.0] - 2019-06-03
- Optimised rendering process to avoid excessive CPU usage when idle
