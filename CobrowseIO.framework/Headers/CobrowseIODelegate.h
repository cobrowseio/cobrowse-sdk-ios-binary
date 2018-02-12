
@class CBIOSession;

@protocol CobrowseIODelegate

-(void) cobrowseSessionDidUpdate: (CBIOSession*) session;
-(void) cobrowseSessionDidEnd: (CBIOSession*) session;

@end
