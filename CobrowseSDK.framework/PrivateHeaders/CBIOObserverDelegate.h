#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// WARNING: This protocol is used by external wrapper SDK's (e.g. flutter).
/// If the interface changes it needs to be updated in any wrapper SDK that uses it as well.
@protocol CBIOObserverDelegate <NSObject>

-(void)cobrowseDelegateDidChange;

@end

NS_ASSUME_NONNULL_END
