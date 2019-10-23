#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface CBIOKeyPress : NSObject

@property (readonly, nonnull) NSString* key;
@property (readonly, nonnull) NSString* code;
@property (readonly, nonnull) NSString* state;

@end
