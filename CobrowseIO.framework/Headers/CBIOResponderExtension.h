#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class CBIOTouch;
@class CBIOTouchEvent;
@class CBIOKeyPress;

@protocol CBIOResponderExtension <NSObject>

@optional

-(bool) cobrowseTouchesBegan:(nonnull NSSet<CBIOTouch*> *)touches withEvent:(nonnull CBIOTouchEvent*)event withResponder: (nonnull UIResponder*) responder;
-(bool) cobrowseTouchesMoved:(nonnull NSSet<CBIOTouch*> *)touches withEvent:(nonnull CBIOTouchEvent*)event withResponder: (nonnull UIResponder*) responder;
-(bool) cobrowseTouchesEnded:(nonnull NSSet<CBIOTouch*> *)touches withEvent:(nonnull CBIOTouchEvent*)event withResponder: (nonnull UIResponder*) responder;
-(bool) cobrowseTouchesCancelled:(nonnull NSSet<CBIOTouch*> *)touches withEvent:(nonnull CBIOTouchEvent*)event withResponder: (nonnull UIResponder*) responder;

-(bool) cobrowseKeyDown:(nonnull CBIOKeyPress*)event withResponder: (nonnull UIResponder*) responder;

@end
