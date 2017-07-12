//
//  P2UXCoreComponent.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 5/23/14.
//  Copyright (c) 2014 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <P2UXCore/P2UXLicenseManager.h>

@protocol P2UXCoreComponentDelegate <NSObject>
- (void) validateAuthCodeInProgress:(NSString*)authCode;
- (void) validatedAuthCode:(NSString*)authCode result:(LicenseStatusResult)result license:(NSDictionary*)license statusMessage:(NSString*)statusMessage;
@end

@interface P2UXCoreComponent : NSObject<P2UXLicenseDelegate>
{
    CGFloat mWidthPixels;
    CGFloat mHeightPixels;
}
+ (NSBundle*) frameworkBundle;
+ (instancetype) instance;
+ (void) setLogLevel:(P2UXCoreLogLevel)level;
+ (BOOL) valid;
+ (NSString*) fullVersion;
- (void) initializeWithAuthCode:(NSString*)authCode delegate:(id<P2UXCoreComponentDelegate>)delegate;
@end

#define P2UXCoreLocalizedString(key, comment) \
[[P2UXCoreComponent frameworkBundle] localizedStringForKey:(key) value:@"" table:@"Localizable"]
