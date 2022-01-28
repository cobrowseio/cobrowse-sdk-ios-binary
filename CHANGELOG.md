# Changelog

All notable changes to this project will be documented in this file. See [standard-version](https://github.com/conventional-changelog/standard-version) for commit guidelines.

### [2.16.3](#) (2022-01-28)


### Bug Fixes

* skip custom data updates that match the cached version ([f0408ff](#))

### [2.16.2](#) (2022-01-25)


### Bug Fixes

* fix full device mode when session are initiated with full_device already set to true ([37951ba](#))

### [2.16.1](#) (2021-12-08)

## [2.16.0](#) (2021-11-15)


### Features

* send device and custom data on session creation ([bc19cf5](#))

### [2.15.1](#) (2021-10-12)


### Bug Fixes

* restore macos build ([0542b74](#))

## [2.15.0](#) (2021-09-08)


### Features

* add XCFramework of the broadcast extension ([8743ad8](#))

### [2.14.4](#) (2021-09-02)


### Bug Fixes

* the delegate can now be dynamically updates during an active session ([14206e8](#))

### [2.14.3](#) (2021-08-10)


### Bug Fixes

* optimise lazy removal of redaction on next activation when possible ([649ab04](#))

### [2.14.2](#) (2021-08-09)


### Bug Fixes

* ensure redacted views are cleaned up if no longer specified as redacted by the delegate ([1fd899c](#))

### [2.14.1](#) (2021-07-28)


### Bug Fixes

* replace redaction layers that are no longer valid ([a6b0d76](#))

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
