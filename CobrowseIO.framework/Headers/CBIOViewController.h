#import <UIKit/UIKit.h>

#import "CobrowseIODelegate.h"

@class CBIOSession;

@interface CBIOViewController : UIViewController

-(instancetype) loadSession: (NSString*) codeOrId;

-(IBAction) endSession:(id)sender;

@end
