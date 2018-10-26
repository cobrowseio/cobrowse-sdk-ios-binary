#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface CBIOTouch : NSObject

@property (readonly, nonnull) UIView* target;

-(CGPoint) position;

@end
