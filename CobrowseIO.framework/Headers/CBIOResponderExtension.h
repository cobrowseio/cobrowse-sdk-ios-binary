#import <Foundation/Foundation.h>

@class CBIOTouch;
@class CBIOTouchEvent;
@class CBIOKeyPress;

@protocol CBIOResponderExtension <NSObject>

@optional

-(bool) cobrowseTouchesBegan:(NSSet<CBIOTouch*> *)touches withEvent:(CBIOTouchEvent*)event inView: (UIView*) view;
-(bool) cobrowseTouchesMoved:(NSSet<CBIOTouch*> *)touches withEvent:(CBIOTouchEvent*)event inView: (UIView*) view;
-(bool) cobrowseTouchesEnded:(NSSet<CBIOTouch*> *)touches withEvent:(CBIOTouchEvent*)event inView: (UIView*) view;
-(bool) cobrowseTouchesCancelled:(NSSet<CBIOTouch*> *)touches withEvent:(CBIOTouchEvent*)event inView: (UIView*) view;

-(bool) cobrowseKeyDown:(CBIOKeyPress*)event inView: (UIView*) view;

@end
