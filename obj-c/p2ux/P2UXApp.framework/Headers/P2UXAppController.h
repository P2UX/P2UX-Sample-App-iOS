//
//  P2UXAppController.h
//  P2UXApp
//
//  Created by Stephen Schalkhauser on 9/21/15.
//  Copyright © 2015 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <P2UXCore/P2UXPanel.h>
#import <P2UXApp/P2UXPanelController.h>
#ifdef LOCAL_NOTIFICATION_SUPPORT
#import <UserNotifications/UserNotifications.h>
#endif

@class P2UXEventTransition, P2UXScreenNavigation;

extern NSString* const UPDATE_CONTENTS_NOW;


/*!
 The Application controller
 @discussion Provides management of the screen workflow for a screen window, application level event handlers and application data. All screen/panel level event requests are funneled back through this object.
 */
@interface P2UXAppController : UIWindow<P2UXViewContainerDelegate, P2UXEventHandlerDelegate,
    UINavigationControllerDelegate,
    P2UXModalLayerDelegate,
    P2UXPanelDelegate>
{
    P2UXAppDefinition*          _def;
    NSMutableArray*             _eventHandlers;
    NSMutableArray*             _backStack;
    NSMutableDictionary*        _backStackTransitions;
    NSMutableDictionary*        _viewCache;
    NSMutableDictionary*        _visiblePanels;
}

/*!
 The current view controller
 */
@property (nonatomic, readonly) UIViewController* current;
/*!
 The home view controller
 */
@property (nonatomic, readonly) UIViewController* home;
/*!
 The current application behavior
 */
@property (nonatomic) P2UXAppBehavior* behavior;
/*!
 The form factor (screens and views) associated with this device screen
 */
@property (nonatomic, readonly) P2UXAppFormFactor* formFactor;
/**
 Indicates whether or not this is a primary device screen.
 */
@property (nonatomic) BOOL primary;
@property (nonatomic, readonly) P2UXScreenNavigation* navigation;

- (instancetype) initWithFrame:(CGRect)frame;
- (instancetype) initWithFormFactor:(P2UXAppFormFactor*)ff def:(P2UXAppDefinition*)def;
- (instancetype) initWithFormFactor:(P2UXAppFormFactor*)ff def:(P2UXAppDefinition*)def size:(CGSize)size;

- (void) setFormFactor:(P2UXAppFormFactor *)ff andDef:(P2UXAppDefinition*)def;

- (void) cleanup;
- (void) reloadContents:(P2UXAppFormFactor*)ff andDef:(P2UXAppDefinition*)def;
- (void) setAppStateFromAction:(P2UXEventAction*)action;
- (void) setAppState:(NSString*)state;
- (NSString*) appState;

- (NSArray*) eventsWithEventType:( P2UXElementEvent)eventType;
- (BOOL) handleExternalEvent:(NSString*)eventType params:(id)params;

#ifdef LOCAL_NOTIFICATION_SUPPORT
- (void) handleSystemLocalNotification:(UNNotificationRequest*)notification;
#endif

- (BOOL) setCurrentView:(NSString*)viewId
            backHistory:(BOOL)backHistory
                replace:(BOOL)replace
                   data:(id)data
             transition:(P2UXEventTransition*)transition
                 toggle:(BOOL)toggle
                  index:(id)index
           clearDefault:(BOOL)clearDefault
                   rect:(NSDictionary*)rect
                  modal:(BOOL)modal;

- (void) resetEvents;

- (void) presentViewController:(UIViewController *)viewControllerToPresent animated:(BOOL)flag completion:(void (^)(void))completion;

#pragma mark - Event handlers
- (void) handleEvents:(NSArray*)events element:(P2UXElementInstance*)element source:(id)source;

#pragma mark - Variable access
- (id) varForKey:(NSString*)key;
- (BOOL) setVarValue:(id)value forKey:(NSString*)key usingIdent:(NSString*)ident notify:(BOOL)notify itemspec:(NSDictionary*)itemspec;

#pragma mark - Current View methods
- (BOOL) setCurrentView:(NSString*)viewId backHistory:(BOOL)backHistory;
- (BOOL) setCurrentView:(NSString*)viewId backHistory:(BOOL)backHistory transition:(P2UXEventTransition*)transition;
- (BOOL) setCurrentView:(NSString*)viewId backHistory:(BOOL)backHistory replace:(BOOL)replace data:(id)data transition:(P2UXEventTransition*)transition toggle:(BOOL)toggle index:(id)index rect:(NSDictionary*)rect modal:(BOOL)modal;

#pragma mark - Overlay methods
- (P2UXPanel*) showPanel:(NSString*)ident timeout:(NSNumber*)timeout show:(NSInteger)show pos:(NSDictionary*)pos size:(NSDictionary*)size modalColor:(NSString*)modalColor transition:(P2UXEventTransition*)transition;
- (void) showPanelFromAction:(P2UXEventAction*)action;
- (P2UXPanelController*) visiblePanelWithIdent:(NSString*)ident;
- (void) hidePanel:(NSString*)ident transition:(P2UXEventTransition*)transition;
- (void) hidePanel:(NSString*)ident fade:(BOOL)fade;
- (void) hidePanelFromAction:(P2UXEventAction*)action;

#pragma mark - Modal Layer methods
- (void) createModalLayer:(UIView*)view color:(NSString*)color fade:(float)fade;

#pragma mark - Back stack methods
- (void) handleBack;
- (void) clearBackStack;
- (void) handleBackToView:(NSString*)viewId transition:(P2UXEventTransition*)transition;
- (void) addLayoutToBackStack:(UIView*)view layout:(NSString*)layout transient:(BOOL)transient duration:(float)duration replace:(BOOL)replace clear:(BOOL)clear;
- (void) removeLastOnBackStack;

#pragma mark - P2UXEventHandlerDelegate
- (void) eventsComplete:(id)handler;

#pragma mark - P2UXModalLayerDelegate
- (void) layerTap:(P2UXModalLayer *)layer;

#pragma mark - P2UXViewContainerDelegate
- (void) setValue:(id)value forLink:(P2UXVarLink *)link withIndex:(id)index;
- (P2UXDefinition*) screenDefWithIdentOrSystemType:(NSString*)ident;
- (P2UXDefinition*) panelDefWithIdentOrSystemType:(NSString*)ident;
- (P2UXView*) currentView;
- (P2UXView*) cachedView:(NSString*) ident;
- (void) cacheView:(P2UXView*)view;
- (UIViewController*) currentController;
- (NSDictionary*) nativeDialogWithIdent:(NSString*)ident;
- (CGRect)  containerBounds;
- (OSColorClass*) colorWithId:(NSString*)colorWithId;
- (NSDictionary*) gradientWithId:(NSString*)gradientWithId;
- (CGFloat) scale;
- (UIView*) overlayParent;
- (P2UXView*) createViewItemWithDef:(P2UXDefinition*)def rect:(CGRect)rect cache:(BOOL)cache index:(id)index data:(id)data;
- (void) handleTimeUpdate;
- (id<P2UXHelperDelegate>) helperDelegate;
- (void) showOverlaysForCurrentView;
- (void) removeOverlay:(NSString*)removeOverlay;

#pragma mark - P2UXPanelDelegate
- (void) viewDidClose:(id)view;
@end
