#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

@class UIView;

@interface CBIOTouch : NSObject

@property (readonly, nonnull) UIView* target;

-(CGPoint) position;

@end
