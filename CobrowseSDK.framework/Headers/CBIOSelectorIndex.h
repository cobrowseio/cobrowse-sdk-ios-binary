#import <Foundation/Foundation.h>
#import "CBIOSelector.h"

NS_ASSUME_NONNULL_BEGIN

typedef NSMutableDictionary<NSString *, NSMutableSet<CBIOSelector *> *> *CBIOSelectorStore;

@interface CBIOSelectorIndex : NSObject

@property (class, nonatomic, readonly) CBIOSelectorIndex *redacted;
@property (class, nonatomic, readonly) CBIOSelectorIndex *unredacted;

@property (nonatomic, strong, readonly) NSSet<NSString *> *knownAttributes;
@property (nonatomic, strong, nullable) NSSet<CBIOSelector *> *selectors;

@property (nonatomic, strong, readonly) CBIOSelectorStore byTag;
@property (nonatomic, strong, readonly) CBIOSelectorStore byAttribute;

- (NSSet<CBIOSelector *> *)possibleMatchesForView:(CBIOViewProperties *)view NS_SWIFT_NAME(possibleMatches(for:));
- (NSSet<CBIOSelector *> *)possibleMatchesForTag:(nullable NSString *)tag
                                       attributes:(nullable NSDictionary<NSString *, id> *)attributes;
- (BOOL) isEmpty;

@end

NS_ASSUME_NONNULL_END
