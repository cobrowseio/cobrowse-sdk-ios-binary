#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Represents the network metrics of a session
@interface CBIOSessionMetrics : NSObject

/// Returns the measured session latency. This is the round-trip time from the device to the server, it doesn't indicate the latency of the agent.
- (NSTimeInterval) latency;

/// Returns the timestamp of the last alive message that the SDK sent in a response to a probe from agent.
- (nullable NSDate*) lastAlive;

@end

NS_ASSUME_NONNULL_END
