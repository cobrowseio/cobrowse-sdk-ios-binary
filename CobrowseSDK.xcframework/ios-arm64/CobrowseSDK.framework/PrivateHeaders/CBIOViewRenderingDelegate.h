#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// WARNING: This protocol is used by external wrapper SDK's (e.g. flutter).
/// If the interface changes it needs to be updated in any wrapper SDK that uses it as well.
@protocol CBIOViewRenderingDelegate <NSObject>

-(BOOL)cobrowseCanCaptureViewController:(UIViewController *)controller;
-(void)cobrowseCaptureViewController:(UIViewController *)controller scale:(CGFloat)scale callback:(void(^)(CGImageRef _Nullable))callback;

@end

NS_ASSUME_NONNULL_END
