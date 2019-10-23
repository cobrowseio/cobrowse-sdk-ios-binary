# Changelog

## [2.0.0] - 2019-10-23
- BREAKING: A confirmation prompt is now shown to the user by default when a session is requested.
            You can disable or change this using the Cobrowse delegate methods.
- BREAKING: You must now call [CobrowseIO.instance start] once you have set your license key and are
            for Cobrowse to start listening for session requests.
- BREAKING: The API for overriding session control has changed. It is now two methods `cobrowseShowSessionControls` and `cobrowseHideSessionControls`
- BREAKING: Added many nullability specifiers which will affect the Swift API
- BREAKING: Dropped SocketIO dependency in favour of using websockets directly

## [1.15.0] - 2019-08-09
- Added plist setting for configuring render paths

## [1.14.7] - 2019-08-01
- Dependency version bump

## [1.14.6] - 2019-06-14
- Dynamically adjust render quality

## [1.14.5] - 2019-06-14
- Optimisations to keep devices responsive during continuous gesture

## [1.14.4] - 2019-06-11
- Fix reinitialisation of overlay on some devices caused by rotation event

## [1.14.2] - 2019-06-10
- Fixed potential crash parsing resource from server

## [1.14.0] - 2019-06-03
- Optimised rendering process to avoid excessive CPU usage when idle
