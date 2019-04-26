
@class CBIOSession;
@class CBIOTouchEvent;
@class CBIOKeyPress;

@protocol CobrowseIODelegate <NSObject>

-(void) cobrowseSessionDidUpdate: (CBIOSession*) session;
-(void) cobrowseSessionDidEnd: (CBIOSession*) session;

@optional

-(bool) cobrowseShouldAllowTouchEvent: (CBIOTouchEvent*) touchEvent forSession: (CBIOSession*) session;
-(bool) cobrowseShouldAllowKeyEvent: (CBIOKeyPress*) keyEvent forSession: (CBIOSession*) session;

-(bool) cobrowseShouldCaptureWindow: (UIWindow*) window;

-(void) cobrowseHandleSessionRequest: (CBIOSession*) session;

-(UIView*) cobrowseControlsForSession: (CBIOSession*) session;

@end
