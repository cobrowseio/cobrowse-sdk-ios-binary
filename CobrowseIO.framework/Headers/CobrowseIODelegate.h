#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class CBIOSession;
@class CBIOTouchEvent;
@class CBIOKeyPress;

@protocol CobrowseIODelegate <NSObject>

-(void) cobrowseSessionDidUpdate: (nonnull CBIOSession*) session;
-(void) cobrowseSessionDidEnd: (nonnull CBIOSession*) session;

@optional

-(bool) cobrowseShouldAllowTouchEvent: (nonnull CBIOTouchEvent*) touchEvent forSession: (nonnull CBIOSession*) session;
-(bool) cobrowseShouldAllowKeyEvent: (nonnull CBIOKeyPress*) keyEvent forSession: (nonnull CBIOSession*) session;

-(bool) cobrowseShouldCaptureWindow: (nonnull UIWindow*) window;

-(void) cobrowseHandleSessionRequest: (nonnull CBIOSession*) session;

-(void) cobrowseShowSessionControls: (nonnull CBIOSession*) session;
-(void) cobrowseHideSessionControls: (nonnull CBIOSession*) session;

-(nonnull NSArray<UIView*>*) cobrowseRedactedViewsForViewController: (nonnull UIViewController*) vc;

@end
