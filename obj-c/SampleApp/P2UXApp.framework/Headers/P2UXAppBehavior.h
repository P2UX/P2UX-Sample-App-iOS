//
//  P2UXAppBehavior.h
//  P2UXApp
//
//  Created by Stephen Schalkhauser on 6/3/14.
//  Copyright (c) 2014 Phase 2 Industries, LLC. All rights reserved.
//

#import <P2UXCore/P2UXCore.h>
#ifdef LOCAL_NOTIFICATION_SUPPORT
@import UserNotifications;
#endif
@class P2UXScreen;
@class P2UXAppLoadingView;
@class P2UXAppDefinition;
@class P2UXNavigationController;

extern NSString* const kServiceName;

/*!
 @class P2UXAppBehavior
 @brief The starting point for custom behavior in your mobile application.
 @discussion Create a subclass of this class to add custom controls, view controllers, and screen or panel instances.
 */
#if TARGET_OS_IOS
@interface P2UXAppBehavior : P2UXBehavior<P2UXDataAuthDelegate,P2UXDataSourceDelegate,P2UXDataManagerDelegate,UIWebViewDelegate,UNUserNotificationCenterDelegate>
#else
@interface P2UXAppBehavior : P2UXBehavior<P2UXDataAuthDelegate,P2UXDataSourceDelegate,P2UXDataManagerDelegate>
#endif

/*!
 The instance of the home view for your application
 */
@property (nonatomic, readonly) P2UXScreen* homeView;
/*!
 The definition of the application.
 */
@property (nonatomic) P2UXAppDefinition* appDef;
@property (nonatomic,strong) P2UXAuthParamResponse paramCallback;

- (void) cleanup;
- (void) clearContents;

/*!
 @brief Get an instance of a view from a view definition
 @discussion This will access an instance of a view from the current application. If the view exists in the view cache, it will return the cached instance, otherwise it will call createScreenWithDef to request a new instance of the view.
 @param def The view definition
 @param rect A rect that defines the size to create the view
 @param cache Whether or not to cache the view when its created
 @param index An index value to pass to the view
 @param data Additional data to pass to the view. This data can be used with linking
 @param viewDelegate The current view delegate
 @return A P2UXScreen instance of the view
 */
- (P2UXScreen*) viewWithDef:(P2UXDefinition*)def rect:(CGRect)rect cache:(BOOL)cache  index:(id)index data:(id)data viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;

/*!
 @brief Creates a new instance of a screen.
 @discussion This is called from a request to show a screen when a cached version of the view isn't available. Override this method to return a custom screen instance.
 
 @param def The view definition
 @param rect A rect that defines the size to create the view
 @param index An index value to pass to the view
 @param data Additional data to pass to the view. This data can be used with linking
 @param viewDelegate The current view delegate
 @return A P2UXScreen instance of the view
 */
- (P2UXScreen*) createScreenWithDef:(P2UXDefinition*)def rect:(CGRect)rect index:(id)index data:(id)data viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;

/*!
 @brief Creates a view controller for a view
 @discussion This is called from a request to show a view. Override this method to return a custom view controller instance for the supplied view definition.
 
 @param def The view definition
 @param cache Whether or not to cache the view managed by this view controller
 @param index An index value to pass to the view
 @param data Additional data to pass to the view. This data can be used with linking
 @param viewDelegate The current view delegate
 @return A P2UXViewController instance
 */
- (P2UXViewController*) createViewControllerWithDef:(P2UXDefinition*)def cache:(BOOL)cache index:(id)index data:(id)data viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;

/*!
@brief Creates a panel controller for a view
@discussion This is called from a request to show a view. Override this method to return a custom view controller instance for the supplied view definition.

@param def The view definition
@param cache Whether or not to cache the view managed by this view controller
@param index An index value to pass to the view
@param data Additional data to pass to the view. This data can be used with linking
@param viewDelegate The current view delegate
@return A P2UXViewController instance
*/
- (P2UXViewController*) createPanelControllerWithDef:(P2UXDefinition*)def cache:(BOOL)cache index:(id)index data:(id)data viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;

/*!
 @brief Creates a navigation view controller for a view
 @discussion This is called from a request to show a view. Override this method to return a custom view controller instance for the supplied view definition.
 
 @param def The view definition
 @return A P2UXAppNavigationController instance
 */
- (P2UXNavigationController*) createNavigationControllerWithDef:(P2UXDefinition *)def;


/*!
 @brief Get an instance of a panel from a view definition
 @discussion This will access an instance of a panel from the current application. If the panel exists in the panel cache, it will return the cached instance, otherwise it will call createPanelWithDef to request a new instance of the panel.
 @param def The panel definition
 @param rect A rect that defines the size to create the panel
 @param cache Whether or not to cache the panel when its created
 @param index An index value to pass to the panel
 @param data Additional data to pass to the panel. This data can be used with linking
 @param viewDelegate The current view delegate
 @return A P2UXPanel instance of the panel
 */
- (P2UXPanel*) panelWithDef:(P2UXDefinition*)def rect:(CGRect)rect cache:(BOOL)cache  index:(id)index data:(id)data viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;

/*!
 @brief Creates a new instance of a panel.
 @discussion This is called from a request to show a panel when a cached version of the panel isn't available. Override this method to return a custom panel instance.
 
 @param def The panel definition
 @param rect A rect that defines the size to create the panel
 @param index An index value to pass to the panel
 @param data Additional data to pass to the panel. This data can be used with linking
 @param viewDelegate The current view delegate
 @return A P2UXPanel instance of the panel
 */

- (P2UXPanel*) createPanelWithDef:(P2UXDefinition*)def rect:(CGRect)rect index:(id)index data:(id)data viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;

/*!
 @brief Creates a new instance of a view used as the item in a collection.
 @discussion This is called from a request to show a panel when a cached version of the panel isn't available. Override this method to return a custom panel instance.
 
 @param def The panel definition
 @param rect A rect that defines the size to create the panel
 @param index An index value to pass to the panel
 @param data Additional data to pass to the panel. This data can be used with linking
 @param viewDelegate The current view delegate
 @return A P2UXPanel instance of the panel
 */
- (P2UXView*) createViewItemWithDef:(P2UXDefinition*)def rect:(CGRect)rect index:(id)index data:(id)data viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;

/*!
 @brief Allows for overriding the default application loading screen which is seen at first run.
 @discussion This screen only appears if the application loads its content dynamically and there are no cached assets. The view returned from this method should be an instance of P2UXAppLoadingView so that loading progress can be found and displayed.
 
 @param frame The rectangle frame for the screen. This is provided by the frame and should be used to create the size of the screen returned
 @return Return a screen that is an instance of P2UXAppLoadingView
 */
- (P2UXAppLoadingView*) loadingView:(CGRect)frame;

/*!
 @brief Called after the application has been loaded.
 @discussion This is a good place to initialize any specific behavior for your app. This is called before the home view is constructed
 */
- (void) loadedApp;
/*!
 @brief Called after the home view has been loaded.
 @discussion This is a good place to initialize any specific behavior for your app. This is called after the home view is constructed
 @return A Boolean indicating if the application should start
 */
- (BOOL) startupApp;
- (void) initialViewLoaded;
- (P2UXScreen*) homeViewWithParentRect:(CGRect)parentRect viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;

- (UIImage*) loadingLogo;

- (void) showNativeDialogFromId:(NSString*)ident withData:(NSDictionary*)data delegate:(id<P2UXNativeDialogHandlerDelegate>)delegate viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;
- (void) showNativeDialogFromSpec:(NSDictionary*)spec withData:(NSDictionary*)data delegate:(id<P2UXNativeDialogHandlerDelegate>)delegate viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;

#ifdef LOCAL_NOTIFICATION_SUPPORT
- (BOOL) handleSystemLocalNotification:(UNNotificationRequest*)notification active:(BOOL)active;
- (void)userNotificationCenter:(UNUserNotificationCenter *)center didReceiveNotificationResponse:(UNNotificationResponse *)response withCompletionHandler:(void (^)(void))completionHandler;
- (void)userNotificationCenter:(UNUserNotificationCenter *)center willPresentNotification:(UNNotification *)notification withCompletionHandler:(void (^)(UNNotificationPresentationOptions options))completionHandler;
#endif

#pragma mark - P2UXDataManagerDelegate
- (void) postDataSourceFetch:(NSString *)ident request:(NSString *)request args:(NSDictionary *)args data:(P2UXSourcedData *)data cached:(BOOL)cached;
- (void) postVarFetch:(NSString *)ident var:(NSString *)var value:(id)value;

@end

