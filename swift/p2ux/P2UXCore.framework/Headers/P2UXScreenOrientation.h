//
//  P2UXScreenOrientation.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 9/28/16.
//  Copyright © 2016 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <P2UXCore/P2UXScreenState.h>
@class P2UXState;

@interface P2UXScreenOrientation : NSObject
{
    P2UXScreenState*          _state;
    P2UXScreenOrientation*    _baseOrientation;
}

@property (nonatomic) P2UXOrientationType type;
@property (nonatomic, readonly) P2UXScreenState* state;
@property (nonatomic, readonly) NSString* stateName;
@property (nonatomic, readonly) NSArray<UIView*> *overlays;
@property (nonatomic, readonly) BOOL initialized;
@property (nonatomic, readonly) NSDictionary* background;

- (instancetype) initWithSpec:(P2UXScreenStateDefinition*)statedef;
- (void) cleanup;

- (P2UXScreenState*) changeState:(NSString*)stateName parent:(UIView*)parent force:(BOOL)force;
- (P2UXScreenState*) changeState:(NSString*)stateName parent:(UIView*)parent;

- (P2UXScreenState*) stateWithName:(NSString*)stateName;
- (void) activate:(NSArray*)prevUpdates type:(P2UXOrientationType) type state:(NSString*)state parent:(UIView*)parent;
- (NSArray*) deactivate;

- (NSMutableDictionary*) buildViewWithParent:(UIView *)parent constraintParent:(UIView*)constraintParent handler:(id<P2UXActionDelegate>)handler viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate index:(id)index data:(id)data addToParent:(BOOL)addToParent delegate:(id<P2UXScreenStateDelegate>)delegate updates:(NSArray*)updates;

@end
