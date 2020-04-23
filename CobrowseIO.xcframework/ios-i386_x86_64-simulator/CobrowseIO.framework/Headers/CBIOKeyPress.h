#import <Foundation/Foundation.h>

@interface CBIOKeyPress : NSObject

@property (readonly, nonnull) NSString* key;
@property (readonly, nonnull) NSString* code;
@property (readonly, nonnull) NSString* state;

@end
