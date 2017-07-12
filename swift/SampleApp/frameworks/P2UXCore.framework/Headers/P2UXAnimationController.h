//
//  P2UXAnimationController.h
//  App Player
//
//  Created by Stephen Schalkhauser on 11/24/14.
//  Copyright (c) 2014 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface P2UXAnimationController : NSObject<UIViewControllerAnimatedTransitioning>
{
    UIView* _setToView;
}
@property (nonatomic, assign) NSTimeInterval duration;
@property (nonatomic, assign) BOOL reverse;

- (void)animateTransition:(id<UIViewControllerContextTransitioning>)transitionContext
           fromController:(UIViewController *)fromController
             toController:(UIViewController *)toController
                 fromView:(UIView *)fromView
                   toView:(UIView *)toView;

- (void) animateForwardTransition:(id<UIViewControllerContextTransitioning>)transitionContext
                  fromController:(UIViewController *)fromController
                    toController:(UIViewController *)toController
                        fromView:(UIView *)fromView
                          toView:(UIView *)toView;
- (void) animateReverseTransition:(id<UIViewControllerContextTransitioning>)transitionContext
                  fromController:(UIViewController *)fromController
                    toController:(UIViewController *)toController
                        fromView:(UIView *)fromView
                          toView:(UIView *)toView;
- (void) removeOtherViews:(UIView*)viewToKeep;

@end
