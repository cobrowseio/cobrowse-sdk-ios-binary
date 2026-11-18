#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// A push token together with the push provider it came from, for `+[CobrowseIO setPushToken:]`.
/// Create one with a class method such as `+firebaseInstallationId:`; the class is not meant to be subclassed.
@interface CBIOPushToken : NSObject

-(instancetype) init NS_UNAVAILABLE;
+(instancetype) new NS_UNAVAILABLE;

/// The Firebase installation ID (FID) that Firebase Messaging registers this app with FCM by.
/// Firebase Messaging hands it to `messaging(_:didReceiveRegistration:)`.
+(instancetype) firebaseInstallationId:(NSString*)fid;

@end

NS_ASSUME_NONNULL_END
