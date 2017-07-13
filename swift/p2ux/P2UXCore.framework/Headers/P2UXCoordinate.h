//
//  P2UXCoordinate.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 11/6/12.
//  Copyright (c) 2014 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, P2UXRelativeType) {
    P2UXRelative_Undefined = -1,
    P2UXRelative_Left = 0,
    P2UXRelative_Center,
    P2UXRelative_Right,
    P2UXRelative_Top,
    P2UXRelative_Bottom,
    P2UXRelative_RightOf,
    P2UXRelative_LeftOf,
    P2UXRelative_Above,
    P2UXRelative_Below,
    P2UXRelative_LeftRight,
    P2UXRelative_RightLeft,
    P2UXRelative_TopBottom,
    P2UXRelative_BottomTop,
    P2UXRelative_SizeToFit,
    P2UXRelative_DimMatches
};

typedef NS_ENUM(NSInteger, P2UXCoordinateType) {
    P2UXCoordinate_Absolute = 0,
    P2UXCoordinate_Percent,
    P2UXCoordinate_RelativeDepricated,
    P2UXCoordinate_Aspect
};

typedef NS_ENUM(NSInteger, P2UXCoordinateValue) {
    P2UXCoordinateValue_X = 0,
    P2UXCoordinateValue_Y,
    P2UXCoordinateValue_Width,
    P2UXCoordinateValue_Height
};

typedef NS_ENUM(NSInteger, P2UXDimType) {
    P2UXDimType_Vert = 0,
    P2UXDimType_Horz = 1
};

@interface P2UXCoordinate : NSObject
{
    float       _value;
    int         _type;
    int         _relType;
    NSString*   _elId;
}
@property (nonatomic) float value;
@property (nonatomic) int type;
@property (nonatomic) int relType;
@property (nonatomic, readonly) P2UXCoordinateValue coordVal;
@property (nonatomic, retain) NSString* elId;
@property (nonatomic, readonly) BOOL requiresSizeUpdate;

+ (P2UXCoordinate*) coordinateFromValue:(float)value coordVal:(P2UXCoordinateValue)coordVal;
+ (NSLayoutConstraint*) constraintForCoordinate:(P2UXCoordinate*)coord item:(OSViewClass*)item parent:(OSViewClass*)parent controls:(NSDictionary*)controls;

- (id) initFromObject:(NSDictionary*)object dim:(P2UXDimType)dim coordVal:(P2UXCoordinateValue)coordVal;
- (id) initFromValue:(float)value coordVal:(P2UXCoordinateValue)coordVal;
- (float) valueFromStart:(float)start total:(float)total scale:(CGFloat)scale;
- (float) valueFromStart:(float)start total:(float)total size:(float)size parentSize:(float)parentSize scale:(CGFloat)scale;
- (void) setAbsoluteValue:(float)val;
// only for w/h calc
- (float) sizeValueFromStart:(float)start total:(float)total scale:(CGFloat)scale;
@end
