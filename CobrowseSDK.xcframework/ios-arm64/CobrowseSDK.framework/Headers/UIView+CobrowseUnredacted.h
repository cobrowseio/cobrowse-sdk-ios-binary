//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIView (CobrowseUnredacted)

/// Unredact this view, allowing it and its parents to be seen by a support agent
/// even when an ancestor is redacted. Other children of those parents stay redacted.
///
/// - Returns: this view, so the call can be chained.
/// - You can also implement the ``CobrowseIOUnredacted`` protocol on your view
///   controller to provide the views to unredact there instead.
-(UIView *)cobrowseUnredacted API_AVAILABLE(ios(14.0));

@end

NS_ASSUME_NONNULL_END
