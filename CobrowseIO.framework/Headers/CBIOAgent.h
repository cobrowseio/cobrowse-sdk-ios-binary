#import <Foundation/Foundation.h>

@interface CBIOAgent : NSObject

@property (nonnull) NSString* name;
@property (nonnull) NSString* id;

+(nullable instancetype) from: (nonnull NSDictionary*) dict;

@end
