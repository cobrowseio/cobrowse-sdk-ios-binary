#import <Foundation/Foundation.h>

/// Represents a support agent viewing the cobrowsing session
@interface CBIOAgent : NSObject

/// The display name of the support agent
@property (nonnull) NSString* name;

/// The email of the support agent, may be nil if account privacy settings
/// restrict access to the agent email
@property (nullable) NSString* email;

/// The id of the support agent
@property (nonnull) NSString* id;

/// Creates a CBIOAgent object from the JSON representation
/// @param dict JSON object representation as NSDictionary
+(nullable instancetype) from: (nonnull NSDictionary*) dict;

@end
