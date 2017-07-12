//
//  P2UXViewContainer.h
//  P2UXCore
//
//  This is just a management layer on top of a hosted P2UXView
//
//  Created by Stephen Schalkhauser on 9/24/14.
//  Copyright (c) 2014 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <P2UXCore/P2UXView.h>
#import <P2UXCore/P2UXData.h>
#import <P2UXCore/P2UXControl.h>
#import <P2UXCore/P2UXEventTransition.h>

@interface P2UXViewContainer : UIView<P2UXData, P2UXControl, P2UXEventTransitionDelegate>
{
    P2UXView*                   _view;
}
@property (nonatomic, readonly) BOOL overlay;
@property (nonatomic, readonly) NSString* viewIdent;
@property (nonatomic, readonly) NSInteger overlayReferences;

+ (NSString*) defaultViewFromInst:(P2UXElementInstance*)elemInst;

- (id) initWithFrame:(CGRect)frame elemInst:(P2UXElementInstance*)elemInst uipath:(NSString*)path ext:(BOOL)ext handler:(id<P2UXActionDelegate>)handler viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate index:(id)index data:(id)data;
- (void) setViewIndex:(NSInteger)index transition:(P2UXEventTransition*)transition;
- (UIView*) containingViewForElement:(P2UXElement*)element;
- (void) decrementOverlayReference;
- (void) addOverlayReference;

#pragma mark - P2UXControl
- (void) cleanup;
- (void) setData:(NSDictionary *)data;
- (void) handleActionParams:(NSDictionary*)action;
- (void) initializeConstraints:(UIView*)parent;

#pragma mark - P2UXData
- (id) valueForAttribute:(NSString*)attribute;
- (void) setValue:(id)value forAttribute:(NSString *)attribute;

#pragma mark - P2UXEventTransitionDelegate
- (void) transitionComplete:(UIView *)view outgoing:(UIView*)outgoing transition:(P2UXEventTransition*)transition;
- (void) transitionReverseComplete:(UIView*)view outgoing:(UIView*)outgoing transition:(P2UXEventTransition*)transition;

#pragma mark - Overlay methods
- (void) shownAsOverlay;
- (void) displayWithTimeout:(NSTimeInterval)timeout parent:(UIView*)parent;
- (void) displayWithParent:(UIView*)parent;
- (void) displayWithParent:(UIView*)parent fade:(BOOL)fade;
- (void) displayWithParent:(UIView*)parent top:(UIView*)top fade:(BOOL)fade;
- (void) close;
- (void) closeNow;
@end
