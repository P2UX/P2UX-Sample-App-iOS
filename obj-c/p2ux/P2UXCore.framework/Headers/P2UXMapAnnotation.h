//
//  P2UXMapAnnotation.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 8/3/14.
//  Copyright (c) 2014 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>

@interface P2UXMapAnnotation : NSObject<MKAnnotation>
{
    CLLocationCoordinate2D _coord;
    NSString*              _title;
    NSString*              _subtitle;
}
- (id)initWithCoordinate:(CLLocationCoordinate2D)coordinate;

@end
