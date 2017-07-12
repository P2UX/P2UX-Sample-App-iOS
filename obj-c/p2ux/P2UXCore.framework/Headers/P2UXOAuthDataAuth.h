//
//  P2UXOAuthDataAuth.h
//  P2UXCore
//
//  Created by Steve Ansell on 1/2/15.
//  Copyright (c) 2015 Phase 2 Industries, LLC. All rights reserved.
//

#import "P2UXDataAuthSubclass.h"

#define REDIRECT_URI        @"redirect_uri"

typedef NS_ENUM(NSInteger, P2UXOauthGrantType) {
    P2UXOauthGrantType_Unknown,
    P2UXOauthGrantType_AuthCode,
    P2UXOauthGrantType_Implicit,
    P2UXOauthGrantType_Password,
    P2UXOauthGrantType_Client
};


@interface P2UXOAuthDataAuth : P2UXDataAuth
{
@protected
    NSDictionary* _persistedData;
    NSString* _accessToken;
    NSString* _persistItem;
}
@property (readonly) P2UXOauthGrantType grantType;
@property (readonly) BOOL expired;


@end
