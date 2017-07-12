//
//  P2UXMapPointAnnotation.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 8/14/15.
//  Copyright © 2015 Phase 2 Industries, LLC. All rights reserved.
//

#import <MapKit/MapKit.h>
@class P2UXMapWaypoint;

@interface P2UXMapPointAnnotation : MKPointAnnotation
@property (nonatomic, weak) P2UXMapWaypoint* waypoint;

@end
