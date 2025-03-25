
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@interface CBIOURLSession : NSURLSession

+ (NSURLSession *)sessionWithConfiguration:(NSURLSessionConfiguration *)configuration
                                  delegate:(nullable id <NSURLSessionDelegate>)delegate
                             delegateQueue:(nullable NSOperationQueue *)queue;

@end

NS_ASSUME_NONNULL_END
