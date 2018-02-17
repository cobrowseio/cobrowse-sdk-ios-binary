#import <Foundation/Foundation.h>

@interface CBIOAgent : NSObject

@property NSString* name;
@property NSString* id;

+(instancetype) from: (NSDictionary*) dict;

@end
