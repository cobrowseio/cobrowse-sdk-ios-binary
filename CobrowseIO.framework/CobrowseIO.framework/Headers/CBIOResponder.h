#import <Foundation/Foundation.h>

@class CBIOTouch;
@class CBIOTouchEvent;
@class CBIOKeyPress;

@protocol CBIOResponder <NSObject>

@optional

// touch events
-(void) cobrowseTouchesBegan:(NSSet<CBIOTouch*> *)touches withEvent:(CBIOTouchEvent*)event;
-(void) cobrowseTouchesMoved:(NSSet<CBIOTouch*> *)touches withEvent:(CBIOTouchEvent*)event;
-(void) cobrowseTouchesEnded:(NSSet<CBIOTouch*> *)touches withEvent:(CBIOTouchEvent*)event;
-(void) cobrowseTouchesCancelled:(NSSet<CBIOTouch*> *)touches withEvent:(CBIOTouchEvent*)event;

// keyboard events
-(void) cobrowseKeyDown:(CBIOKeyPress*)event;

@end
