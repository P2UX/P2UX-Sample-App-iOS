//
//  UIViewController+P2UXViewController.h
//  P2UXApp
//
//  Created by Stephen Schalkhauser on 6/7/17.
//  Copyright © 2017 Phase 2 Industries, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@class P2UXDefinition;
@interface UIViewController (P2UXViewController)

- (void) initWithDef:(P2UXDefinition*)def behavior:(P2UXAppBehavior*)behavior cache:(BOOL)cache index:(id)index data:(id)data viewDelegate:(id<P2UXViewContainerDelegate>)delegate;
- (void) initialize;
- (void) cleanup;

- (P2UXDefinition*)def;
- (void) setDef:(P2UXDefinition*)def;
- (P2UXAppBehavior*) behavior;
- (void) setBehavior:(P2UXAppBehavior*)behavior;
- (UIView*) loadViewFromDef;
- (void) setViewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;
- (id<P2UXViewContainerDelegate>) viewDelegate;
- (void) setIndexValue:(id)indexValue;
- (id) indexValue;
- (void) setData:(id)data;
- (id) data;
- (void) setCache:(BOOL)cache;
- (BOOL) cache;
- (void) setAppStatusBar:(P2UXStatusBar) appStatusBar;
- (P2UXStatusBar) appStatusBar;
- (void) setOrientationOverride:(P2UXOrientationType)orientationType;
- (P2UXOrientationType) orientationOverride;
- (P2UXElementInstance*) elementInstanceWithTag:(NSInteger)tag;
- (void) setTransition:(P2UXEventTransition*)transition;
- (P2UXEventTransition*) transition;
- (void) setPath:(NSString*)path;
- (NSString*)path;
- (void) setExternal:(BOOL)external;
- (BOOL) external;

- (UIView*)  controlWithElementType:(NSString*) type;
- (UIView*)  controlWithElementSystemTypeOrId:(NSString*) type;

- (NSString*) displayName;
- (NSString*) ident;
- (NSString*) systemType;
- (BOOL)tagged;

- (BOOL) isIdentOrSystemType:(NSString*)ident;
- (NSArray*) overlaysForView;
- (void) setupOrientationChange:(CGSize)size withTransitionCoordinator:(id<UIViewControllerTransitionCoordinator>)coordinator;
- (void) orientationAnimating;
- (void) orientationComplete;

- (BOOL) isControllerActive:(UIViewController*)controller;

#pragma mark - P2UXActionDelegate
- (BOOL) handleButtonClick:(id)sender;
- (BOOL) handleButtonToggle:(id)sender;
- (BOOL) handleButtonRadio:(id)sender;
- (BOOL) handleButtonSelectorClick:(id)sender;
- (BOOL) handleButtonLongPress:(id)sender;
- (BOOL) handleRotaryChange:(id)sender;
- (BOOL) handleRotaryIncrement:(id)sender;
- (BOOL) handleSlideIncrement:(id)sender;
- (BOOL) handleLabelToggle:(id)sender;
- (BOOL) handleKeyboardReturn:(id)sender;
- (BOOL) viewStateWillChange:(NSString*)layout;
- (void) viewStateDidChange:(NSString*)layout;
- (void) handleTextBeginEditing:(id)sender;
- (void) handleTextEndEditing:(id)sender;
- (void) handleTextChange:(id)sender;
- (BOOL) handleOnMessage:(NSString*)msg data:(id)data sender:(id)sender;
- (BOOL) handleOnStateChange:(NSString*)stateName;
- (P2UXView*) parentContainer;
@end
