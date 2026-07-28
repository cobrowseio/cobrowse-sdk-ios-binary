#import <Foundation/Foundation.h>
#import <ReplayKit/ReplayKit.h>

// TODO: RPBroadcastSampleHandler is deprecated in iOS 27. Should we consider a screen capture kit alternative for 27?
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
@interface CobrowseIOReplayKitExtension : RPBroadcastSampleHandler
#pragma clang diagnostic pop

@end
