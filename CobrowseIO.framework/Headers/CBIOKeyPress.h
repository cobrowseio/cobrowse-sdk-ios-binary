#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface CBIOKeyPress : NSObject

@property (readonly, nonnull) NSString* key;
@property (readonly, nonnull) NSString* code;
@property (readonly, nonnull) NSString* state;
@property (readonly) bool ctrlKey;
@property (readonly) bool shiftKey;
@property (readonly) bool altKey;
@property (readonly) bool metaKey;

@end
