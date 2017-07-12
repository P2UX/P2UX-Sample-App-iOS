//
//  P2UXAppErrorViewController.h
//  P2UXApp
//
//  Created by Stephen Schalkhauser on 10/11/15.
//  Copyright © 2015 Phase 2 Industries, LLC. All rights reserved.
//

#import <P2UXApp/P2UXApp.h>
#import <P2UXApp/P2UXAppUpdateContentManager.h>

@interface P2UXAppErrorViewController : P2UXViewController
{
    NSString* _assetPath;
    P2UXLabel* _errorLabel;
}
@property (nonatomic) NSString* internalContent;

- (id) initWithSpec:(NSString*) spec viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;
- (NSDictionary*) loadDefinition;
- (void) setErrorText:(NSString*)text;
- (void) setErrorResult:(ContentManagerError)result;
@end
