//
//  P2UXAnalytics.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 8/19/15.
//  Copyright © 2015 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_OPTIONS(NSInteger, P2UXAnalyticsEvent) {
    P2UXAnalyticsEvent_All = 4095,
    P2UXAnalyticsEvent_ShowView = 1,
    P2UXAnalyticsEvent_LeaveView = 1<<1,
    P2UXAnalyticsEvent_Press = 1<<2,
    P2UXAnalyticsEvent_LongPress = 1<<3,
    P2UXAnalyticsEvent_Swipe = 1<<4,
    P2UXAnalyticsEvent_RestDataRequest = 1<<5,
    P2UXAnalyticsEvent_RestDataRequestFail = 1<<6,
    P2UXAnalyticsEvent_PullDown = 1<<7,
    P2UXAnalyticsEvent_KeyboardReturn = 1<<8
};

@protocol P2UXAnalytics <NSObject>
- (void)        start;
- (void)        shutdown;
- (NSString*)   name;
- (void)        triggerEvent:(P2UXAnalyticsEvent) event senderIdent:(id) senderIdent param:(id)param;
- (void)        triggerCustomEvent:(NSString*) event senderIdent:(id) senderIdent param:(id)param;
- (void)        triggerCustomEvent:(NSString*)event data:(id)data;
- (void)        setSessionValue:(id)value forKey:(NSString*)key;
- (void)        setUserId:(NSString*)userId;
@end
