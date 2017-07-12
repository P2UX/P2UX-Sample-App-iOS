//
//  P2UXPanelController.h
//  P2UXApp
//
//  Created by Stephen Schalkhauser on 6/15/17.
//  Copyright © 2017 Phase 2 Industries, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface P2UXPanelController : UIViewController
@property (nonatomic, readonly) P2UXPanel* panel;

- (instancetype) initWithView:(P2UXDefinition*)def behavior:(P2UXAppBehavior*)behavior cache:(BOOL)cache index:(id)index data:(id)data viewDelegate:(id<P2UXViewContainerDelegate>)delegate;
- (void) showPanelWithParent:(UIView*)parent pos:(NSDictionary*)pos size:(NSDictionary*)size;
- (void) showPanelWithParent:(UIView*)parent rect:(CGRect)rect elemInst:(P2UXElementInstance*)elemInst;
- (BOOL) close;
@end
