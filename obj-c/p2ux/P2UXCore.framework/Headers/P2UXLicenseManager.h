//
//  P2UXLicenseManager.h
//  P2UXCore
//
//  Created by Steve Ansell on 9/23/14.
//  Copyright (c) 2014 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    kLicenseValid = 0,
    kLicenseInvalid,
    kLicenseCantAquire
} LicenseStatusResult;

@protocol P2UXLicenseDelegate <NSObject>
@required
-(void)licenseCheckStatus:(LicenseStatusResult)status andMessage:(NSString*)statusMessage;
@end

@interface P2UXLicenseManager : NSObject

+(NSDictionary*)licenseForAuthCode:(NSString*)authCode;
+(BOOL)removeLicenseForAuthCode:(NSString*)authCode;
+(void)retreiveLicenseForAuthCode:(NSString *)authCode
                 thenCallDelegate:(id<P2UXLicenseDelegate>)delegate;
+(void)retreiveLicenseForAuthCode:(NSString *)authCode serverURL:(NSString*)serverURL
                 thenCallDelegate:(id<P2UXLicenseDelegate>)delegate;

+(NSString*) userCode;

@end
