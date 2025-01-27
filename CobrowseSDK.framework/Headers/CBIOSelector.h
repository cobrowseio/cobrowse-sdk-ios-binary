#import <Foundation/Foundation.h>

#import "CBIOViewProperties.h"
#import "CBIOSelectorPart.h"

NS_ASSUME_NONNULL_BEGIN

@interface CBIOSelector : NSObject

@property (readonly) NSArray<CBIOSelectorPart *>* parts;

+ (nullable instancetype)from:(nonnull NSArray*) selector;

- (nonnull instancetype)init NS_UNAVAILABLE;
- (nonnull instancetype)initWithParts:(NSArray<CBIOSelectorPart *>*) parts;

- (BOOL)matches:(CBIOViewProperties *)view withParents:(NSArray<CBIOViewProperties *> *)parents;

@end

NS_ASSUME_NONNULL_END
