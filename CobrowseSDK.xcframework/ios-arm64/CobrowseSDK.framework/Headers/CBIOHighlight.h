#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Information about a highlight that needs to be displayed. Passed through
/// ``CobrowseIODelegate/cobrowseShowHighlight:onDismiss:`` when overriding the default
/// Cobrowse highlight style.
@interface CBIOHighlight : NSObject

/// The view that should be highlighted
@property (readonly, nonatomic) UIView *view;

/// The optional message associated with the highlight.
///
/// This text is typically provided by the support agent and should be shown
/// alongside the highlighted content, for example in a tooltip, popover,
/// or callout.
@property (readonly, nonatomic, nullable) NSString *title;
@end

NS_ASSUME_NONNULL_END
