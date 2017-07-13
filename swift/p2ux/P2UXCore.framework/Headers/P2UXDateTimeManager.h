//
//  P2UXDateTimeManager.h
//  P2UXCore
//
//  Created by Mark Leyfman on 7/9/14.
//  Copyright (c) 2014 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "P2UXCacheable.h"

extern NSString* const DateTimeMgr_DayTimeFmt;

@interface P2UXDateTimeManager : NSObject<P2UXCacheable>

@property (nonatomic) NSTimeInterval offset;
@property (nonatomic, readonly) NSDate* date;
@property (nonatomic, readonly) NSInteger month;
@property (nonatomic, readonly) NSInteger day;
@property (nonatomic, readonly) NSInteger weekday;
@property (nonatomic, readonly) NSInteger year;
@property (nonatomic, readonly) NSInteger hour;
@property (nonatomic, readonly) NSInteger minute;
@property (nonatomic, readonly) NSInteger second;

+ (instancetype) instance;
+ (NSString*) formatDateTime:(NSDate*)date format:(NSString*)format;

- (void) incrementOffset:(NSTimeInterval) increment;

@end
