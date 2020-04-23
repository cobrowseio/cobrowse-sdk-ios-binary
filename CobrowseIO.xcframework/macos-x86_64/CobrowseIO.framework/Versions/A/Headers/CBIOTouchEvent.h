#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

@interface CBIOTouchEvent : NSObject

@property (readonly) CGPoint position;
@property (readonly, nonnull) NSDate* timestamp;

@end
