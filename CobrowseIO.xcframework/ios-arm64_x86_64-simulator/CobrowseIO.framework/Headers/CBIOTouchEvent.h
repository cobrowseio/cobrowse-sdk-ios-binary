#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

/// Represents the state of a remote agent touch point
@interface CBIOTouchEvent : NSObject

/// The position of the touch in relative coordinates
@property (readonly) CGPoint position;

// Timestamp the touch occurred in the agent dashbaord
@property (readonly, nonnull) NSDate* timestamp;

@end
