//
//  P2UXAppP2UXAppCreator.h
//  P2UXApp
//
//  Created by Stephen Schalkhauser on 6/9/17.
//  Copyright © 2017 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <P2UXApp/P2UXAppDefinition.h>

extern NSString* _Nonnull const P2UXAppCreator_Opt_Env;
extern NSString* _Nonnull const P2UXAppCreator_Opt_Env_Production;
extern NSString* _Nonnull const P2UXAppCreator_Opt_Env_Stage;
extern NSString* _Nonnull const P2UXAppCreator_Opt_LogLevel;

@protocol P2UXAppCreatorDelegate <NSObject>

@optional
- (P2UXAppBehavior* _Nonnull) createBehaviorForApplication:(nonnull NSString*)appid;
- (P2UXAppLoadingViewController* _Nonnull) createLoadingViewController;
- (P2UXAppErrorViewController* _Nonnull) createErrorViewController;
- (void) loadedApplication:(nonnull P2UXAppDefinition*)appDef;
@end

@interface P2UXAppCreator : NSObject<P2UXAppLoaderDelegate>
@property (nonnull, nonatomic, readonly) P2UXAppController* appController;


/**
 Create a new application instance from an application authorization key. This should be called from the AppDelegate application didFinishLaunchingWithOptions method to 
 start an instance of a P2UX managed application.

 @param appkey An application authorization key. This can be generated in Builder for your application and is required to startup the P2UX rendering library.
 @param opts A dictionary of options for the application. Allows customization of the app by providing different settings for the Environment (Stage or Production) and the logging level. If omitted, the default is Production environment and log level of Error.
 @param resources Allows for specification of how the application resources are to be handled. Each item in the supplied NSArray is a NSDictionary that defines how the resources for a particular form factor are managed. Options exist for specifying embedded versus remote resources as well for how to update the resources.
 @param delegate A P2UXAppCreatorDelegate instance. Delegate methods are called during application creation to allow for providing custom code.
 @return Returns an instance of a UIWindow. This window is automatically setup to be the current active window for the application.
 */
+ (UIWindow* _Nonnull) createApplicationWithKey:(nonnull NSString*)appkey opts:(nullable NSDictionary*)opts resources:(nullable NSArray*)resources delegate:(nullable id<P2UXAppCreatorDelegate>)delegate;
+ (BOOL) openURL:(nonnull NSURL*)url withAnnotation:(nullable id)annotation;
+ (void) listenForUpdates:(BOOL)listen;
+ (void) reloadCurrentApplicationAndForceUpdate:(BOOL)forceLoad;

#if !TARGET_OS_TV
+ (UIInterfaceOrientationMask) supportedInterfaceOrientationsForWindow:(nonnull UIWindow *)window;
#endif
@end
