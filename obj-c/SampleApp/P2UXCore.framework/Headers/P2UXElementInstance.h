//
//  P2UXElementInstance.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 7/17/14.
//  Copyright (c) 2014 Phase 2 Industries, LLC. All rights reserved.
//

#import <P2UXCore/P2UXElement.h>
#import <P2UXCore/P2UXViewContainerDelegate.h>
#import <P2UXCore/P2UXState.h>

@class P2UXVarLinks, P2UXOrientation;

@interface P2UXElementInstance : NSObject
{
    NSMutableArray*         _constraints;
    BOOL                    _needCleanup;
    NSMutableDictionary*    _overriddenConstraints;
    NSMutableArray*         _notifyAttributes;
    P2UXOrientation*         _landscape;
    P2UXOrientation*         _portrait;
}
@property (nonatomic)           OSViewClass* ctrl;
@property (nonatomic, readonly) P2UXElement* element;
@property (nonatomic)           NSInteger tag;
@property (nonatomic) NSMutableArray* constraints;
@property (nonatomic, readonly) NSString* type;
@property (nonatomic) NSString* systemType;
@property (nonatomic, readonly) NSString* name;
@property (nonatomic, readonly) int ctrlType;
@property (nonatomic          ) NSDictionary* itemSpec;
@property (nonatomic, readonly) NSArray* events;
@property (nonatomic, readonly) NSString* altid;
@property (nonatomic, readonly) NSString* localizedValue;
@property (nonatomic)           BOOL locked;
@property (nonatomic, readonly) NSString* elId;
@property (nonatomic) P2UXElementLayoutDim ignored;
@property (nonatomic)           P2UXOrientation* orientation;
@property (nonatomic)           P2UXState* state;
@property (nonatomic, readonly) NSString* displayName;
@property (nonatomic, readonly) BOOL tagged;
@property (nonatomic, readonly) BOOL overlay;
@property (nonatomic) OSViewClass* parent;
@property (nonatomic) id<P2UXViewContainerDelegate> viewDelegate;

- (id) initWithElement:(P2UXElement*)elem tag:(NSInteger)tag;
- (void) cleanup;

- (void) initializeStates:(OSViewClass*)view parent:(OSViewClass*)parent parentRect:(CGRect)parentRect controls:(NSDictionary*)controls;
- (void) initialIngoreInView;
#ifdef NO_CONSTRAINTS
- (BOOL) changeStateNC:(NSString *)stateName parent:(OSViewClass*)parent;
#else
- (NSArray*) changeState:(NSString *)stateName;
#endif
- (BOOL) attributeInState:(NSString*)attribute;

- (P2UXOrientation*) addOrientationSpec:(NSDictionary*)spec forType:(P2UXOrientationType)type;
- (NSArray*) changeOrientation:(P2UXOrientationType)orientationType usingState:(NSString*)stateName;
- (void) addToParent;
//- (void) addToParent
- (id) constraintOfType:(NSString*)type forState:(P2UXState*)state def:(P2UXState*)def;
- (NSString*) valueForStateType:(NSString*)type;
- (void) addEvent:(P2UXEvent*)event;
- (NSArray*) eventsWithEventType:(P2UXElementEvent)event;
- (NSArray*) dataEventsWithEventType:(P2UXElementEvent)event ident:(NSString*)ident request:(NSString*)request;
- (NSArray*) dataEventsWithEventType:(P2UXElementEvent)event systemType:(NSString*)systemType request:(NSString*)request;
- (P2UXVarLinks*) links:(id)index context:(id)context viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;
- (P2UXState*) stateWithName:(NSString*)name;
- (void) setNotifyAttribute:(NSString*)attribute;
- (BOOL) notifyAttribute:(NSString*)attribute;

- (void) updateFrameUsingParent:(OSViewClass*)parent controls:(NSDictionary*)controls;
- (void) updateConstraintsForSizeChange:(OSViewClass*)view parent:(OSViewClass*)parent controls:(NSDictionary*) controls;

- (void) addToItemSpec:(NSDictionary*)data forKey:(NSString*)key;

- (void) createStates:(NSDictionary*)states;
- (void) createDefaultStates:(NSDictionary*)states;

- (BOOL) setupDataEvents:(OSViewClass*)parent viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;

- (void) replaceConstraintsFromRect:(CGRect)rect;
- (void) overrideConstraint:(NSLayoutConstraint*)constraint forKey:(NSString*)key;
- (id) varValueWithKey:(NSString*)key;
- (NSLayoutConstraint*) constraintForAttribute:(NSLayoutAttribute)attribute;
- (void) updateStateValues;

- (P2UXOrientation*) createOrientation:(NSDictionary*)spec type:(P2UXOrientationType)type elId:(NSString*)elId defaults:(P2UXOrientation*)defaults;
@end
