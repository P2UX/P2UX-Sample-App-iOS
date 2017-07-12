//
//  P2UXServiceManager.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 10/16/13.
//  Copyright (c) 2013 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

#define SERVICE_LIVE 0
#define SERVICE_STAGE 1
#define SERVICE_DEV 2

extern NSString* const SERVICE_NOTIFICATION_CHANGE;

@interface P2UXServiceManager : NSObject
{
    NSInteger _contentServiceType;
    NSString* _contentServiceURL;
    NSMutableArray* _servers;
}
@property (nonatomic, readonly) NSString* contentServiceURL;

+ (instancetype) instance;
- (void) initializeConnection;
- (void) shutdown;
- (void) updateServerList:(NSArray*)servers;
- (void) setContentServiceType:(NSInteger)type notify:(BOOL)notify;
@end
