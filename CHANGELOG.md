# Changelog

All notable changes to this project will be documented in this file. See [standard-version](https://github.com/conventional-changelog/standard-version) for commit guidelines.

### [2.22.4](#) (2022-11-08)

### [2.22.3](#) (2022-11-08)

### [2.22.2](#) (2022-11-08)

### [2.22.1](#) (2022-09-21)

## [2.22.0](#) (2022-09-20)


### Features

* Xcode 14 has dropped support for iOS versions below iOS 11, and macOS versions below 10.13, as well as the armv7 and i386 architectures. As such we have also dropped support for those platforms. ([7d05756](#))
* Xcode 14 support ([11779e5](#))


### Bug Fixes

* remote redaction not applying to UITextField in UIAlertController. ([0b10e3f](#))

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
