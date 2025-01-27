#import <Foundation/Foundation.h>

@protocol CBIOHasViewProperties <NSObject>

@property (copy, nullable) NSString *tag;
@property (copy, nullable) NSString *id;
@property (copy, nonnull) NSDictionary<NSString *, NSString *> *attributes;

@end
