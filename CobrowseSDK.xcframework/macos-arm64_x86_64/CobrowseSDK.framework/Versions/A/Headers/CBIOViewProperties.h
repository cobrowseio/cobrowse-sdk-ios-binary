#import <Foundation/Foundation.h>

#import "CBIOSelectableViewProperties.h"

NS_ASSUME_NONNULL_BEGIN

@interface CBIOViewProperties : NSObject <CBIOSelectableViewProperties>

@property (copy, nonnull) NSString *viewId;
@property (copy, nullable) NSString *tag;
@property (copy, nonnull) NSDictionary<NSString *, NSString *> *attributes;
@property (assign) CGPoint origin;
@property (assign) CGSize size;

+(NSString*) nextId;

- (instancetype)initWithTag:(nullable NSString *)tag
                         id:(nullable NSString *)id
                 attributes:(NSDictionary<NSString *, id> *)attributes;

- (instancetype)initWithTag:(nullable NSString *)tag
                         id:(nullable NSString *)id
                 attributes:(NSDictionary<NSString *, id> *)attributes
                     viewId: (NSString*) viewId NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

