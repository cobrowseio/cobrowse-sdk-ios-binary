#import <Foundation/Foundation.h>

#import "CBIOHasViewProperties.h"

NS_ASSUME_NONNULL_BEGIN

@interface CBIOViewProperties : NSObject <CBIOHasViewProperties>

@property (copy, nullable) NSString *tag;
@property (copy, nullable) NSString *id;
@property (copy, nonnull) NSDictionary<NSString *, NSString *> *attributes;

- (instancetype)initWithTag:(nullable NSString *)tag
                         id:(nullable NSString *)id
                 attributes:(NSDictionary<NSString *, id> *)attributes NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

