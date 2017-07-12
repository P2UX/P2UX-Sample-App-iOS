//
//  P2UXMapRouteDelegate.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 8/5/16.
//  Copyright © 2016 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum
{
    MapRouteState_Idle = 0,
    MapRouteState_Calculating
} MapRouteState;

@class P2UXMapRoute;

@protocol P2UXMapRouteDelegate <NSObject>

- (void) routeStateChanged:(MapRouteState)state;
- (void) displayRoute:(P2UXMapRoute*)route;
@end
