//
//  P2UXAppLoader.h
//  P2UXApp
//
//  Created by Stephen Schalkhauser on 16.02.16.
//  Copyright © 2016 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <P2UXApp/P2UXAppDefinition.h>
#import <P2UXApp/P2UXAppUpdateContentManager.h>
#import <P2UXCore/P2UXKeyConnectionManager.h>
#import <P2UXCore/P2UXUserManager.h>

typedef enum {
    P2UXAppState_Unknown = 0,
    P2UXAppState_NoSpec,
    P2UXAppState_Initialized,
    P2UXAppState_Error_NotFound
} P2UXAppState;

@protocol P2UXAppLoaderDelegate <NSObject>
- (void) appInitialized;
- (void) authStart;
- (void) authComplete:(BOOL)success;
@optional
- (void) loadContentStart;
- (void) loadContentComplete:(ContentManagerError)result;
- (void) contentItemStart:(P2UXContentItem*)item;
- (void) contentItemProgress:(P2UXContentItem*)item;
- (void) contentItemComplete:(P2UXContentItem*)item result:(ContentManagerError)result;

- (void) updateStart;
- (void) updateSessionError;
- (void) updateComplete:(BOOL)success manual:(BOOL)manual;
- (void) manualUpdateComplete;
- (void) initialLoad;
@end

@interface P2UXAppLoader : NSObject<P2UXKeyConnectionManagerDelegate,
                                        P2UXUpdateContentManagerDelegate,
                                        P2UXContentManagerDelegate,
                                        P2UXUserManagerDelegate>
{
    BOOL    _manualUpdate;
    NSDictionary*   _resource;
}
@property (nonatomic) P2UXAppState state;
@property (nonatomic) NSString* appId;
@property (nonatomic) P2UXFormFactor formFactor;
@property (nonatomic) BOOL autoConnect;
@property (nonatomic) NSArray* resources;
@property (nonatomic) NSString* contentKey;
@property (nonatomic, weak) id<P2UXAppLoaderDelegate> delegate;
@property (nonatomic) BOOL locked;

- (void) reauth;
- (void) requestUpdateCheck;
- (BOOL) checkForUpdates:(BOOL)manual;

//- (P2UXAppState) loadFromAuthCode:(NSString*)key formFactor:(P2UXFormFactor)formFactor delegate:(id<P2UXAppLoaderDelegate>)delegate forceLoad:(BOOL) forceLoad;
- (P2UXAppState) loadApp:(NSString*)appId formFactor:(P2UXFormFactor)formFactor delegate:(id<P2UXAppLoaderDelegate>)delegate forceLoad:(BOOL) forceLoad;
- (void) setInitialized;
- (P2UXAppState) reloadCurrentAppWithDelegate:(id<P2UXAppLoaderDelegate>)delegate forceLoad:(BOOL)forceLoad;

- (P2UXAppDefinition*) definitionWithBehavior:(P2UXAppBehavior*)behavior;
- (void) setKeyMode:(BOOL)keyMode;

#pragma mark - P2UXKeyConnectionManagerDelegate
- (void) connectionResultSuccess:(ConnectionLoginError)result request:(NSDictionary *)request;
#pragma mark - P2UXUpdateContentManagerDelegate
- (void) upgradeStart;
- (void) upgradeSessionError;
- (void) upgradeComplete:(BOOL)success manual:(BOOL)manual;

#pragma mark - P2UXContentManagerDelegate
- (void) contentComplete:(BOOL)success;
- (void) contentItemDownloaded:(P2UXContentItem *)item result:(ContentManagerError)result;
- (void) contentItemProgress:(P2UXContentItem *)item value:(long long)value total:(long long)total;
- (void) contentItemStart:(P2UXContentItem *)item;
- (BOOL) willStartNextDownload:(P2UXContentItem *)item;

@end
