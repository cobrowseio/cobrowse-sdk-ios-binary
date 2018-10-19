#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface CBIOTouchEvent : NSObject

@property (readonly) CGPoint position;
@property (readonly) NSDate* timestamp;

@end
