#import <Foundation/Foundation.h>

@class CBIOTouch;
@class CBIOTouchEvent;
@class CBIOKeyPress;

@protocol CBIOResponderExtension <NSObject>

@optional

-(bool) cobrowseTouchesBegan:(NSSet<CBIOTouch*> *)touches withEvent:(CBIOTouchEvent*)event withResponder: (UIResponder*) responder;
-(bool) cobrowseTouchesMoved:(NSSet<CBIOTouch*> *)touches withEvent:(CBIOTouchEvent*)event withResponder: (UIResponder*) responder;
-(bool) cobrowseTouchesEnded:(NSSet<CBIOTouch*> *)touches withEvent:(CBIOTouchEvent*)event withResponder: (UIResponder*) responder;
-(bool) cobrowseTouchesCancelled:(NSSet<CBIOTouch*> *)touches withEvent:(CBIOTouchEvent*)event withResponder: (UIResponder*) responder;

-(bool) cobrowseKeyDown:(CBIOKeyPress*)event withResponder: (UIResponder*) responder;

@end
