#import <Foundation/Foundation.h>

@protocol CBIOSelectableViewProperties <NSObject>

@property (copy, nullable) NSString *tag;
@property (copy, nonnull) NSDictionary<NSString *, NSString *> *attributes;

@end
