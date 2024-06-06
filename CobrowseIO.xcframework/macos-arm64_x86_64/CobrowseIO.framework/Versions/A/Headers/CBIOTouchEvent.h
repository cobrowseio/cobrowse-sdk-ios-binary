#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

/// Represents the state of a remote agent touch point
@interface CBIOTouchEvent : NSObject

/// The identifier of the event. You will likely never need to access this.
@property (readonly, nonnull) NSString* id;

/// The state of the event, either @c touchstart, @c touchmove, or @c touchend.
@property (readonly, nonnull) NSString* state;

/// The position of the touch in relative coordinates
@property (readonly) CGPoint position;

// Timestamp the touch occurred in the agent dashbaord
@property (readonly, nonnull) NSDate* timestamp;

@end
