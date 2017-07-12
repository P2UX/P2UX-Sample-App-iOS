//
//  P2UXAppLoadingViewController.h
//  P2UXApp
//
//  Created by Stephen Schalkhauser on 9/21/15.
//  Copyright © 2015 Phase 2 Industries, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface P2UXAppLoadingViewController : P2UXViewController
{
    P2UXProgress*  _progressView;
    NSString*    _assetPath;
}

- (void) setMessageText:(NSString*)msg;
- (void) setLogoImage:(UIImage*)logo;
- (void) setProgress:(NSInteger)progress;
@end
