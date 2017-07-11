//
//  P2UXMapWaypoint.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 8/13/15.
//  Copyright © 2015 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>
#import <P2UXCore/P2UXMapRegionDelegate.h>

@class P2UXMapPointAnnotation;
@class P2UXMapRegion;

extern NSString* const P2UXMapWaypoint_Current;
extern NSString* const P2UXMapWaypoint_LatLon;

extern NSString* const P2UXMapWaypoint_Attrib_Ident;

extern NSString* const P2UXMapWaypoint_Action_Update;
extern NSString* const P2UXMapWaypoint_Action_Remove;

@protocol P2UXMapWaypointDelegate <NSObject>

- (void) updatedWaypoint:(P2UXMapWaypoint*)wapoint valid:(BOOL)valid;

@end

extern double const P2UXMap_Invalid_Loc;
typedef enum
{
    MapSizeUnits_Feet =0,
    MapSizeUnits_Miles,
    MapSizeUnits_Meters,
    MapSizeUnits_Kilometers
} MapSizeUnits;

@interface P2UXMapWaypoint : NSObject
@property (nonatomic,readonly) NSString* ident;
@property (nonatomic,readonly) NSString* type;
@property (nonatomic,readonly) NSString* marker;
@property (nonatomic,readonly) NSString* geocode;
@property (nonatomic,readonly) BOOL persist;
@property (nonatomic) CLLocationDegrees lat;
@property (nonatomic) CLLocationDegrees lon;
@property (nonatomic) double altitude;
@property (nonatomic) CLLocationDistance width;
@property (nonatomic) CLLocationDistance height;
@property (nonatomic) MKAnnotationView* annotation;
@property (nonatomic) P2UXMapPointAnnotation* point;
@property (nonatomic) MapSizeUnits units;
@property (nonatomic) BOOL visible;
@property (nonatomic) P2UXMapRegion* region;
@property (nonatomic) MKMapItem* mapItem;
@property (nonatomic, weak) id<P2UXMapWaypointDelegate> delegate;

- (id) initFromSpec:(NSDictionary*)spec defaultUnits:(MapSizeUnits)defaultUnits defaultMarker:(NSString*)defaultMarker regionDelegate:(id<P2UXMapRegionDelegate>)regionDelegate;
- (void) updateFromAttributeSpec:(NSDictionary*)spec value:(id)value;
- (void) cleanup;
- (void) clear;
- (void) setInvalid;
- (BOOL) valid;
- (BOOL) setLatLon:(NSString*)latlon;
@end
