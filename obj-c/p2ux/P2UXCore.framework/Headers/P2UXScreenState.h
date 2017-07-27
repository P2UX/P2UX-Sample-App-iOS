//
//  P2UXScreenState.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 9/28/16.
//  Copyright © 2016 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <P2UXCore/P2UXState.h>
@class P2UXScreenStateDefinition, P2UXContainerElement;

@protocol P2UXScreenStateDelegate<NSObject>
- (UIView*) createControlFromElement:(P2UXElement*)element controls:(NSDictionary*)controlsMap parent:(UIView*)parent def:(P2UXDefinition*)def;
- (void) elementCreated:(P2UXElement*)element control:(UIView*)control;
@end

@interface P2UXScreenState : P2UXState
{
    P2UXScreenStateDefinition*    _def;
    NSMutableDictionary*        _controlsMap;
    NSMutableArray*             _controlInstances;
    NSMutableDictionary*        _results;
    NSString*                   _stateName;
    NSMutableDictionary*        _aggregateMap;
}
@property (nonatomic)           NSArray* controls;
@property (nonatomic, readonly) BOOL base;
@property (nonatomic, readonly) NSArray* removals;
@property (nonatomic, readonly) NSDictionary* updates;
@property (nonatomic)           NSMutableDictionary* controlsMap;
@property (nonatomic)           NSArray* controlInstances;
@property (nonatomic)           BOOL useConstraints;
@property (nonatomic, readonly) BOOL initialized;
@property (nonatomic, readonly) NSArray<UIView*> *overlays;
@property (nonatomic, readonly) NSMutableArray* controlsOrder;
@property (nonatomic) NSDictionary*   background;


+ (instancetype) createScreenStateFromDef:(P2UXScreenStateDefinition*)def;

- (instancetype) initWithDef:(P2UXScreenStateDefinition*)def;
- (instancetype) initWithDef:(P2UXScreenStateDefinition*)def defaults:(P2UXScreenState*)defaults;
///FIXME- (instancetype) initWithContainer:(P2UXContainerElement*)container defaults:(P2UXScreenState*)defaults;

- (NSMutableDictionary*) buildViewWithParent:(UIView *)parent constraintParent:(UIView*)constraintParent handler:(id<P2UXActionDelegate>)handler viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate index:(id)index data:(id)data addToParent:(BOOL)addToParent delegate:(id<P2UXScreenStateDelegate>)delegate;
- (void)         renderViewWithParent:(P2UXView*)view;
- (void)         clearContents;
- (void)         updateIndexValue:(id)indexValue;

// State Methods
- (void)         activate:(NSArray*)updates orientation:(P2UXOrientationType)type parent:(UIView*)parent;
- (NSArray*)     deactivate;
- (void)         clearEvents;

// protected
- (void)         removeControlsInList:(NSArray*)controls;
- (UIView*)      controlInstanceWithIdent:(NSString*)ident;
@end
