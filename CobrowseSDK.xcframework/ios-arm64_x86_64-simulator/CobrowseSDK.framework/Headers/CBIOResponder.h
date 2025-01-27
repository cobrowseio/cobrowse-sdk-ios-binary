#import <Foundation/Foundation.h>

@class CBIOTouch;
@class CBIOTouchEvent;
@class CBIOKeyPress;

@protocol CBIOResponder <NSObject>

@optional

// touch events
-(void) cobrowseTouchesBegan:(nonnull NSSet<CBIOTouch*> *)touches withEvent:(nonnull CBIOTouchEvent*)event;
-(void) cobrowseTouchesMoved:(nonnull NSSet<CBIOTouch*> *)touches withEvent:(nonnull CBIOTouchEvent*)event;
-(void) cobrowseTouchesEnded:(nonnull NSSet<CBIOTouch*> *)touches withEvent:(nonnull CBIOTouchEvent*)event;
-(void) cobrowseTouchesCancelled:(nonnull NSSet<CBIOTouch*> *)touches withEvent:(nonnull CBIOTouchEvent*)event;

// keyboard events
-(void) cobrowseKeyDown:(nonnull CBIOKeyPress*)event;

@end
