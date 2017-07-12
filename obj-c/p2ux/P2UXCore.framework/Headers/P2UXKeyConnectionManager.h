//
//  P2UXKeyConnectionManager.m
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 4/28/16.
//  Copyright (c) 2016 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
typedef NS_ENUM(NSInteger, ConnectionState) {
    ConnectionState_LoggedOut = 0,
    ConnectionState_LoggingIn,
    ConnectionState_LoggedIn,
    ConnectionState_Offline
};

typedef NS_ENUM(NSInteger, ConnectionLoginError) {
    ConnectionLoginError_None = 0,
    ConnectionLoginError_Unknown,
    ConnectionLoginError_Network,
    ConnectionLoginError_Auth
};

@protocol P2UXKeyConnectionManagerDelegate <NSObject>
- (void) connectionResultSuccess:(ConnectionLoginError)success request:(NSDictionary*)request;
@end

@interface P2UXKeyConnectionManager : NSObject
@property (nonatomic, readonly) NSString* key;
@property (nonatomic, readonly) BOOL valid;
@property (nonatomic, readonly) BOOL loggedIn;
@property (nonatomic, readonly) BOOL offline;
@property (nonatomic) NSDictionary* requestContext;

+ (instancetype) instance;
- (void) loginWithKey:(NSString*)apiKey;
- (void) loginWithKey:(NSString*)apiKey request:(NSDictionary*)request;
- (void) logout;
- (void) setRefreshSession;
- (void) addDelegate:(id<P2UXKeyConnectionManagerDelegate>)delegate;
- (void) removeDelegate:(id<P2UXKeyConnectionManagerDelegate>)delegate;
@end
