//
//  P2UXViewContainerDelegate.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 3/11/15.
//  Copyright (c) 2015 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <P2UXCore/P2UXActionDelegate.h>

@class P2UXEventAction, P2UXElementInstance, P2UXEventTransition, P2UXDefinition, P2UXPanel, P2UXViewController;
@protocol P2UXHelperDelegate;

@protocol P2UXViewContainerDelegate <NSObject>
- (void)        showPanelFromAction:(P2UXEventAction*)action;
- (void)        hidePanelFromAction:(P2UXEventAction*)action;
- (void)        setAppStateFromAction:(P2UXEventAction*)action;
- (void)        hidePanel:(NSString*)systemType transition:(P2UXEventTransition*)transition;
- (NSDictionary*) nativeDialogWithIdent:(NSString*)ident;
- (void)        clearBackStack;
- (P2UXView*)   currentView;
- (P2UXView*)   screenWithIdent:(NSString*)ident rect:(CGRect)rect cache:(BOOL)cache index:(NSString*)index data:(id)data;
- (P2UXPanel*)  panelWithIdent:(NSString*)ident rect:(CGRect)rect cache:(BOOL)cache index:(NSString*)index data:(id)data;
- (void)        handleEvents:(NSArray*)events element:(P2UXElementInstance*)element source:(id)source;
- (void)        handleEvents:(NSArray*)events element:(P2UXElementInstance*)element source:(id)source result:(NSInteger)result;
- (BOOL)        setCurrentView:(NSString*)viewId backHistory:(BOOL)backHistory;
- (BOOL)        setCurrentView:(NSString*)viewId backHistory:(BOOL)backHistory replace:(BOOL)replace data:(id)data transition:(P2UXEventTransition*)transition toggle:(BOOL)toggle index:(id)index clearDefault:(BOOL)clearDefault rect:(NSDictionary*)rect modal:(BOOL)modal;
- (void)        handleBackToView:(NSString*)viewId transition:(P2UXEventTransition *)transition;
- (void)        reloadContents;
- (void)        addLayoutToBackStack:(UIView*)view layout:(NSString*)layout transient:(BOOL)transient duration:(float)duration replace:(BOOL)replace clear:(BOOL)clear;
- (void)        createModalLayer:(UIView*)view color:(NSString*)color fade:(float)fade;
- (void)        handleBack;
- (void)        resetEvents;
- (P2UXView*)   cachedView:(NSString*)ident;
- (void)        cacheView:(P2UXView*)view;
- (UIViewController*) currentController;
- (CGRect)      containerBounds;
- (P2UXDefinition*) screenDefWithIdentOrSystemType:(NSString*)ident;
- (P2UXDefinition*) panelDefWithIdentOrSystemType:(NSString*)ident;
- (void)        showOverlaysForCurrentView;
- (void)        presentViewController:(UIViewController *)viewControllerToPresent animated:(BOOL)flag completion:(void (^)(void))completion;
- (OSColorClass*) colorWithId:(NSString*)colorWithId;
- (NSDictionary*) gradientWithId:(NSString*)gradientWithId;
- (CGFloat)     scale;
- (UIView*)     overlayWithFrame:(CGRect)frame elemInst:(P2UXElementInstance*)elemInst uipath:(NSString*)path ext:(BOOL)ext handler:(id<P2UXActionDelegate>)handler index:(id)index data:(id)data;
- (UIView*)     overlayParent;
- (void)        removeOverlay:(NSString*)systemType;
- (P2UXView*)   createViewItemWithDef:(P2UXDefinition*)def rect:(CGRect)rect cache:(BOOL)cache index:(id)index data:(id)data;
- (void)        handleTimeUpdate;
- (id<P2UXHelperDelegate>) helperDelegate;
@end
