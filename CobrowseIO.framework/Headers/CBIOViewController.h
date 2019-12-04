#import <UIKit/UIKit.h>

#import "CobrowseIODelegate.h"

@class CBIOSession;

@interface CBIOViewController : UIViewController

-(nonnull instancetype) loadSession: (nonnull NSString*) codeOrId;

-(IBAction) endSession:(nonnull id)sender;

@end
