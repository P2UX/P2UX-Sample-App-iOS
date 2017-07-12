//
//  P2UXCacheable.h
//  P2UXCore
//
//  Created by Mark Leyfman on 7/9/14.
//  Copyright (c) 2014 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol P2UXCacheable <NSObject>
- (NSDictionary*)cacheState;
- (void)restoreState:(NSDictionary*)state;
@optional
- (NSString*)cacheName;
@end
