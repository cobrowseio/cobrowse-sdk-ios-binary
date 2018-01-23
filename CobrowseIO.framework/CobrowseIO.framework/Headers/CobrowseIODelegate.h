
@class CBIOSession;

@protocol CobrowseIODelegate

-(void) cobrowseSessionNeedsUserApproval: (CBIOSession*) session;
-(void) cobrowseSessionDidEnd: (CBIOSession*) session;

@end
