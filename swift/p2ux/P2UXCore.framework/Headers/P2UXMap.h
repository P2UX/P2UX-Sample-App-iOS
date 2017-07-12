//
//  P2UXMap.h
//  P2UXCore
//
//  Created by Mark Leyfman on 7/23/14.
//  Copyright (c) 2014 Phase 2 Industries, LLC. All rights reserved.
//

#import <P2UXCore/P2UXElement.h>
#import <P2UXCore/P2UXControl.h>
#import <P2UXCore/P2UXMapRegionDelegate.h>
#import <P2UXCore/P2UXMapRouteDelegate.h>
#import <P2UXCore/P2UXMapWaypoint.h>
#import <MapKit/MapKit.h>

@class P2UXElementInstance;

extern NSString* const P2UXMap_Attrib_RouteState;


@interface P2UXMap : MKMapView<P2UXControl, MKMapViewDelegate, CLLocationManagerDelegate, P2UXMapRegionDelegate, P2UXMapRouteDelegate, P2UXMapWaypointDelegate>
{
}
@property (nonatomic, readonly) MapRouteState routeState;
@property (nonatomic)           BOOL interactive;
@property (nonatomic)           NSInteger zoomMax;
@property (nonatomic)           NSInteger zoomMin;

- (id) initWithFrame:(CGRect)frame elemInst:(P2UXElementInstance*)elemInst uipath:(NSString*)path ext:(BOOL)ext viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate index:(id)index;
- (void) updateFromLayout;

#pragma mark - MKMapView
-(MKAnnotationView *)mapView:(MKMapView *)mapView viewForAnnotation:(id <MKAnnotation>)annotation;

#pragma mark - CLLocationManagerDelegate
- (void) locationManager:(CLLocationManager *)manager didUpdateLocations:(NSArray *)locations;

#pragma mark - P2UXMapRegionDelegate
- (P2UXMapRegion*) regionInstanceWithIdent:(NSString *)ident forWaypoint:(P2UXMapWaypoint *)waypoint;

#pragma mark - P2UXMapRouteDelegate
- (void) routeStateChanged:(MapRouteState)state;
- (void) displayRoute:(P2UXMapRoute *)route;

#pragma mark - P2UXMapWaypointDelegate
- (void) updatedWaypoint:(P2UXMapWaypoint *)wapoint valid:(BOOL)valid;
@end
