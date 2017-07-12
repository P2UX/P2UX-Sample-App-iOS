//
//  P2UXLocationManager.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 2/6/15.
//  Copyright (c) 2015 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <MapKit/MapKit.h>

@protocol P2UXLocationManagerDelegate;

@interface P2UXLocationManager : NSObject
{
    NSMutableDictionary* _locations;
    CLGeocoder*          _geocoder;
    NSMutableDictionary* _requests;
}
+ (instancetype) instance;
+ (NSString*) formatLocationExpression:(NSString*)expression placemark:(CLPlacemark*)placemark;

- (CLPlacemark*) requestLocationLat:(CGFloat)lat lon:(CGFloat)lon delegate:(__weak id<P2UXLocationManagerDelegate>)delegate;
- (MKMapItem*) mapItemFromSpec:(id)spec label:(NSString*)label;
- (CLPlacemark*) getCoordFromAddress:(NSString*) address andCallback:(void (^)(double lat, double lon, NSError *error))callback;

@end
