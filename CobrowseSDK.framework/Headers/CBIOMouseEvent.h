#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

/// Represents the state of a remote agent mouse point
@interface CBIOMouseEvent : NSObject

/// The position of the mouse event in relative coordinates
@property (readonly) CGPoint position;

// Timestamp the mouse event occurred in the agent dashbaord
@property (readonly, nonnull) NSDate* timestamp;

@end
