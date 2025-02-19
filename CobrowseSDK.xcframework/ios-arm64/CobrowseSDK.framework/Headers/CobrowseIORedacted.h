#import <Foundation/Foundation.h>

/// Implement this protocol on a view controller to redact certain
/// elements from the view of a support agent
/// @see CobrowseIOUnredacted
@protocol CobrowseIORedacted <NSObject>

/// Return the list of UIView subclasses to redact
-(nonnull NSArray<UIView *>*) redactedViews;

@end
