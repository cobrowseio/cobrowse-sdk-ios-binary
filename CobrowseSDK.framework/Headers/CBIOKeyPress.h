#import <Foundation/Foundation.h>

/// Represents a key event triggered by a support agent
@interface CBIOKeyPress : NSObject

@property (readonly, nonnull) NSString* key;
@property (readonly, nonnull) NSString* code;
@property (readonly, nonnull) NSString* state;

@end
