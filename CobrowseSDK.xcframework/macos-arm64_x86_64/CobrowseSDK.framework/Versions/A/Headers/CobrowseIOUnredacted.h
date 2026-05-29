#import <Foundation/Foundation.h>

/// Implement this protocol on a view controller to unredact certain
/// elements from the view of a support agent
/// 
/// - See: ``CobrowseIORedacted``
@protocol CobrowseIOUnredacted <NSObject>

/// Return the list of UIView subclasses to unredact
-(nonnull NSArray<UIView *>*) unredactedViews;

@end
