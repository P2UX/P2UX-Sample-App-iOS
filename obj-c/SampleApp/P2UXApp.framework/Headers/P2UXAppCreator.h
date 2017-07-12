//
//  P2UXAppP2UXAppCreator.h
//  P2UXApp
//
//  Created by Stephen Schalkhauser on 6/9/17.
//  Copyright © 2017 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <P2UXApp/P2UXAppDefinition.h>

extern NSString* const AppCreator_Opt_Env;
extern NSString* const AppCreator_Opt_Env_Production;
extern NSString* const AppCreator_Opt_Env_Stage;
extern NSString* const AppCreator_Opt_LogLevel;
extern NSString* const AppCreator_Opt_Mode;
extern NSString* const AppCreator_Opt_Mode_Key;
extern NSString* const AppCreator_Opt_Mode_UserPwd;

@protocol P2UXAppCreatorDelegate <NSObject>

@optional
- (P2UXAppBehavior*) createBehaviorForApplication:(NSString*)appid;
- (P2UXAppLoadingViewController*) createLoadingViewController;
- (P2UXAppErrorViewController*) createErrorViewController;
- (void) loadedApplication:(P2UXAppDefinition*)appDef;
@end

@interface P2UXAppCreator : NSObject<P2UXAppLoaderDelegate>
@property (nonatomic, readonly) P2UXAppController* appController;

+ (UIWindow*) createApplicationWithKey:(NSString*)appkey opts:(NSDictionary*)opts resources:(NSArray*)resources delegate:(id<P2UXAppCreatorDelegate>)delegate;
+ (BOOL) openURL:(NSURL*)url withAnnotation:(id)annotation;
+ (void) listenForUpdates:(BOOL)listen;
+ (void) reloadCurrentApplicationAndForceUpdate:(BOOL)forceLoad;

#if !TARGET_OS_TV
+ (UIInterfaceOrientationMask) supportedInterfaceOrientationsForWindow:(UIWindow *)window;
#endif
@end
