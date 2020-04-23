#import <Foundation/Foundation.h>
#import "CBIORESTResource.h"

@interface CBIODevice : CBIORESTResource

@property (nullable) NSData* token;

-(nonnull NSString*) id;

@end
