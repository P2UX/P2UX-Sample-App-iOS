//
//  P2UXAnalyticsManager.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 8/19/15.
//  Copyright © 2015 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <P2UXCore/P2UXAnalytics.h>

typedef NS_ENUM(NSInteger, P2UXAnalyticsPolicy) {
    P2UXAnalyticsPolicy_Off = 0,
    P2UXAnalyticsPolicy_All,
    P2UXAnalyticsPolicy_Tagged,
    P2UXAnalyticsPolicy_Untagged
};

@interface P2UXAnalyticsManager : NSObject

+ (instancetype) instance;
@property (nonatomic) P2UXAnalyticsPolicy policy;
@property (nonatomic) NSInteger events;

- (BOOL) addAnalytics:(id<P2UXAnalytics>)analytics withName:(NSString*)key;
- (void) disablePlugin:(NSString*)name;
- (void) enablePlugin:(NSString*)name;
- (void) reset;
- (void) clear;

// events passed on to analytics instances
- (void) start;
- (void) shutdown;
- (void) triggerEvent:(P2UXAnalyticsEvent) event senderIdent:(id)senderIdent param:(id)param tagged:(BOOL)tagged;
- (void) triggerCustomEvent:(NSString*)event senderIdent:(id)senderIdent param:(id)param;
- (void) triggerCustomEvent:(NSString*)event data:(id)data;
- (void) setSessionValue:(id)value forKey:(NSString*)key;
- (void) setUserId:(NSString*)userId;

- (NSString*) stringForEvent:(P2UXAnalyticsEvent)event;
@end
