//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIView (CobrowseRedacted)

/// Redact this view, hiding it and everything inside it from a support agent.
///
/// - Returns: this view, so the call can be chained.
/// - You can also implement the ``CobrowseIORedacted`` protocol on your view
///   controller to provide the views to redact there instead.
/// - To reveal one view inside a redacted region, see `cobrowseUnredacted`.
-(UIView *)cobrowseRedacted API_AVAILABLE(ios(14.0));

@end

NS_ASSUME_NONNULL_END
