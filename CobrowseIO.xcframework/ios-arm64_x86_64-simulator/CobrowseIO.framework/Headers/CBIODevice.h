#import <Foundation/Foundation.h>
#import "CBIORESTResource.h"

/// Represents this device as registered with the Cobrowse service
@interface CBIODevice : CBIORESTResource

/// The APNS push notification token for this device
@property (nullable) NSData* token;

/// The Cobrowse generated id for this device
-(nonnull NSString*) id;

@end
