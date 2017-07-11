//
//  P2UXViewController.h
//  P2UXApp
//
//  Created by Stephen Schalkhauser on 9/21/13.
//  Copyright © 2013 Phase 2 Industries, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <P2UXApp/P2UXAppDefinition.h>
#import <P2UXApp/UIViewController+P2UXViewController.h>
@class P2UXAppBehavior;
@class P2UXEventTransition;

@interface P2UXViewController : UIViewController<UIViewControllerTransitioningDelegate, P2UXActionDelegate, P2UXEventTransitionDelegate>
{
    BOOL                 _cache;
    P2UXView*              _hostedView;
}
@property (nonatomic) NSDictionary* initialRect;
@property (nonatomic, readonly) BOOL hasSubView;

- (id)initWithView:(P2UXDefinition*)def behavior:(P2UXAppBehavior*)behavior cache:(BOOL)cache index:(id)index data:(id)data viewDelegate:(id<P2UXViewContainerDelegate>)delegate;
- (void) cleanup;
- (BOOL) isControllerActive:(P2UXViewController*)controller;


- (void) setViewState:(NSString*)state;

#pragma mark - navigation method overrides
- (P2UXViewController*) presentSubViewController:(P2UXViewController *)viewControllerToPresent rect:(NSDictionary*)rect transition:(P2UXEventTransition*)transition modal:(BOOL)modal completion:(void (^)(void))completion;
- (void) dismissSubViewControllerUsingTransition:(P2UXEventTransition*)transition completion:(void (^)(void))completion;

#pragma mark - P2UXEventTransitionDelegate methods
- (void) transitionComplete:(UIView *)view outgoing:(UIView*)outgoing transition:(P2UXEventTransition*)transition;
- (void) transitionReverseComplete:(UIView*)view outgoing:(UIView*)outgoing transition:(P2UXEventTransition*)transition;

@end
