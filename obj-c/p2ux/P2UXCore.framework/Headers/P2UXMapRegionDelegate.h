//
//  P2UXMapRegionDelegate.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 8/3/16.
//  Copyright © 2016 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@class P2UXMapRegion;
@class P2UXMapWaypoint;

@protocol P2UXMapRegionDelegate <NSObject>

- (P2UXMapRegion*) regionInstanceWithIdent:(NSString*)ident forWaypoint:(P2UXMapWaypoint*)waypoint;
- (void) updateRegionVisibility:(P2UXMapRegion*)region visible:(BOOL)visible;
- (void) removeRegion:(P2UXMapRegion*)region;
@end
