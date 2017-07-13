//
//  NSDate+P2UX.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 3/7/13.
//  Copyright (c) 2014 Phase 2 Industries, LLC. All rights reserved.
//
//

#import <Foundation/Foundation.h>

@interface NSDate (P2UX)
+ (NSDate*) dateWithISO:(NSString*)isodate;
- (NSString*) iso8601Date;
@end
