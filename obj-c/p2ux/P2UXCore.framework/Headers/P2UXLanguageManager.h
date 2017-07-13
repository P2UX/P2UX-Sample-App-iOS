//
//  P2UXLanguageManager.h
//  P2UXCore
//
//  Created by Mark Leyfman on 7/2/14.
//  Copyright (c) 2014 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <P2UXCore/P2UXCacheable.h>

extern NSString* const P2UXDefault_Language;
#define ALL_LANGUAGES nil

@interface P2UXLanguageManager : NSObject <P2UXCacheable>
{
    BOOL    _overriddenLocally;
}

@property (nonatomic) NSString* language;
@property (nonatomic) NSArray* acceptedLanguages;
@property (nonatomic, readonly) NSString* region;

+ (instancetype) instance;

- (void) checkForLocaleChange;

@end
