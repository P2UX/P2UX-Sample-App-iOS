//
//  NSNotificationCenter+P2UX.h
//  P2UXCore
//
//  Created by Steve Ansell on 1/25/13.
//  Copyright (c) 2014 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSNotificationCenter (P2UX)
- (void)postNotificationOnMainName:(NSString *)aName object:(id)anObject userInfo:(NSDictionary *)aUserInfo wait:(BOOL)willWait;
@end
