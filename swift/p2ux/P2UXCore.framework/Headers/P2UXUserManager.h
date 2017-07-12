//
//  P2UXUserManager.h
//  Ref P2UX
//
//  Created by Stephen Schalkhauser on 12/18/12.
//  Copyright (c) 2014 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "P2UXUser.h"

typedef NS_ENUM(NSInteger, UserState) {
    UserState_LoggedOut = 0,
    UserState_LoggingIn,
    UserState_LoggedIn,
    UserState_Offline
};

typedef NS_ENUM(NSInteger, UserLoginError) {
    UserLoginError_None = 0,
    UserLoginError_Unknown,
    UserLoginError_Network,
    UserLoginError_Credentials
};

@protocol P2UXUserManagerDelegate <NSObject>
- (void) loginResultSuccess:(UserLoginError)success request:(NSDictionary*)request;
@end

@interface P2UXUserManager : NSObject
@property (nonatomic) NSString* pwd;
@property (nonatomic) NSString* username;
@property (nonatomic, weak) id<P2UXUserManagerDelegate> delegate;
@property (nonatomic) BOOL rememberMe;
@property (nonatomic) BOOL autoLogin;
@property (nonatomic, readonly) BOOL validCredentials;
@property (nonatomic, readonly) BOOL loggedIn;
@property (nonatomic, readonly) P2UXUser* currentUser;
@property (nonatomic, readonly) BOOL offline;
@property (nonatomic) BOOL sessionTest;
@property (nonatomic) NSDictionary* requestContext;

+ (instancetype) instance;
- (BOOL) login;
- (void) loginWithKey:(NSString*)apiKey;
- (BOOL) loginWithRequest:(NSDictionary*)request;
- (void) loginWithUsername:(NSString*)username pwd:(NSString*)pwd;
- (void) loginWithUsername:(NSString*)uname pwd:(NSString*)pwd request:(NSDictionary*)request;
- (void) logout;
- (void) setOfflineUser:(NSString*)uname;
- (void) setRefreshSession;
- (void) setOfflineCurrent;
- (void) setOfflineAnon;
- (void) anonLogin;
- (void) clearCredentials;
- (OSImageClass*) userImageAsset;
- (void) enable:(BOOL)enable;
@end
