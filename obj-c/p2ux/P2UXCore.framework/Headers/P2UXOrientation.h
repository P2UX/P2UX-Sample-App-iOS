//
//  P2UXOrientation.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 9/27/16.
//  Copyright © 2016 Phase 2 Industries, LLC. All rights reserved.
//
//  Version 2

#import <Foundation/Foundation.h>
#import <P2UXCore/P2UXState.h>

@interface P2UXOrientation : NSObject
{
    NSDictionary*               _originalSpec;
    CGRect                      _rect;
    BOOL                        _visible;
    float                       _opacity;
    NSMutableDictionary*        _states;
    NSString*                   _elId;
    P2UXOrientation*              _defaults;
    P2UXState*                    _defState;
    P2UXState*                    _state;
    P2UXState*                    _prevState;
    
}
@property (nonatomic) P2UXOrientationType type;
@property (nonatomic, readonly) NSDictionary* itemspec;
@property (nonatomic, readonly) CGPoint position;
@property (nonatomic, readonly) CGSize size;
@property (nonatomic, readonly) CGRect rect;
@property (nonatomic, readonly) BOOL visible;
@property (nonatomic, readonly) CGFloat rotation;
@property (nonatomic, readonly) float opacity;
@property (nonatomic, readonly) P2UXState* defState;
@property (nonatomic, readonly) P2UXState* state;
@property (nonatomic, readonly) NSMutableDictionary* states;
@property (nonatomic) P2UXElementLayoutDim ignored;

- (instancetype) initWithSpec:(NSDictionary*)spec type:(P2UXOrientationType)type;
- (instancetype) initWithSpec:(NSDictionary*)dict type:(P2UXOrientationType)type elId:(NSString*)elId defaults:(P2UXOrientation*)defaults;
- (CGRect) rectFromParentX:(CGRect)xRect y:(CGRect)yRect w:(CGSize)w h:(CGSize)h scale:(CGFloat)scale;
- (void) updateWithDictionary:(NSDictionary*)dict;
- (void) addToItemSpec:(NSDictionary*)data forKey:(NSString*)key;
- (NSString*) value;
- (void) cleanup;
- (void) initializeStates:(OSViewClass*)view parent:(OSViewClass*)parent parentRect:(CGRect)parentRect controls:(NSDictionary*)controls;
- (P2UXState*) stateWithName:(NSString*)name;
- (void) createStates:(NSDictionary*)states elId:(NSString*)elid  ctrl:(UIView*)ctrl;
- (void) updateFrameUsingParent:(OSViewClass*)parent parentRect:(CGRect)parentRect controls:(NSDictionary*)controls;
- (P2UXState*) changeState:(NSString*)stateName;
- (BOOL) attributeInState:(NSString*)attribute;
@end
