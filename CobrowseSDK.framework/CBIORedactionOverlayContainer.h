


@protocol CBIORedactionOverlayContainer <NSObject>
-(nonnull instancetype) initWithParent:(nonnull UIView*) parent;
-(void) show;
-(void) hide;
-(void) destroy;
-(bool) isValid;

@end
