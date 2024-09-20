#import <Foundation/Foundation.h>

#import "CBIOViewProperties.h"

NS_ASSUME_NONNULL_BEGIN

@interface CBIOSelectorPart : NSObject <CBIOHasViewProperties>
@property (copy, nullable) NSString *tag;
@property (copy, nullable) NSString *id;
@property (copy, nonnull) NSDictionary<NSString *, NSString *> *attributes;

+ (nonnull instancetype)fromDictionary:(NSDictionary*) dictionary;

- (nonnull instancetype)initWithTag:(nullable NSString *)tag
                         id:(nullable NSString *)id
                      attributes:(nullable NSDictionary<NSString *, NSString *> *)attributes;

- (BOOL)matches:(CBIOViewProperties *)view;

@end

NS_ASSUME_NONNULL_END
