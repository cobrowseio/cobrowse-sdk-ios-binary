#import <Foundation/Foundation.h>

@class UIWindow;
@class UIViewController;
@class UIView;

@class CBIOSession;
@class CBIOTouchEvent;
@class CBIOKeyPress;

@protocol CobrowseIODelegate <NSObject>

-(void) cobrowseSessionDidUpdate: (nonnull CBIOSession*) session;
-(void) cobrowseSessionDidEnd: (nonnull CBIOSession*) session;

@optional

-(bool) cobrowseShouldAllowTouchEvent: (nonnull CBIOTouchEvent*) touchEvent forSession: (nonnull CBIOSession*) session API_AVAILABLE(ios(9));
-(bool) cobrowseShouldAllowKeyEvent: (nonnull CBIOKeyPress*) keyEvent forSession: (nonnull CBIOSession*) session API_AVAILABLE(ios(9));

-(void) cobrowseHandleSessionRequest: (nonnull CBIOSession*) session;

-(void) cobrowseShowSessionControls: (nonnull CBIOSession*) session;
-(void) cobrowseHideSessionControls: (nonnull CBIOSession*) session;

-(bool) cobrowseShouldCaptureWindow: (nonnull UIWindow*) window API_AVAILABLE(ios(9));
-(nonnull NSArray<UIView*>*) cobrowseRedactedViewsForViewController: (nonnull UIViewController*) vc API_AVAILABLE(ios(9));

@end
