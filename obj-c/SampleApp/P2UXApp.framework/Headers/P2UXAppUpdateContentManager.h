//
//  P2UXAppUpdateContentManager.h
//  P2UXApp
//
//  Created by Stephen Schalkhauser on 6/2/14.
//  Copyright (c) 2014 Phase 2 Industries, LLC. All rights reserved.
//

#import <P2UXCore/P2UXCore.h>

@interface P2UXAppUpdateContentManager : P2UXUpdateContentManager
@property (nonatomic) NSInteger formFactor;
+ (instancetype) instance;
- (BOOL) buildAndCheckForUpdates:(NSString*)appId delegate:(id<P2UXUpdateContentManagerDelegate>)delegate manual:(BOOL)manual;
- (BOOL) buildAndCheckForUpdatesToBundle:(NSString*)appId folder:(NSString*)folder delegate:(id<P2UXUpdateContentManagerDelegate>)delegate manual:(BOOL)manual;
- (BOOL) fetchApp:(NSString*)appId;
@end
