//
//  P2UXElementState.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 9/26/16.
//  Copyright (c) 2016 Phase 2 Industries, LLC. All rights reserved.
//
//  Version 2

#import <Foundation/Foundation.h>
#import <P2UXCore/P2UXEvent.h>
@class P2UXCoordinate;

@interface P2UXState : NSObject
{
    NSMutableDictionary*    _constraints;
    NSMutableDictionary*    _sizeChangeConstraints;
    NSMutableArray*         _events;
    NSString*               _elId;
}
@property (nonatomic, readonly) NSString* elId;
@property (nonatomic, readonly) BOOL visible;
@property (nonatomic, readonly) P2UXElementLayoutDim ignored;
@property (nonatomic, readonly) float opacity;
@property (nonatomic, readonly) float rotation;
@property (nonatomic, readonly) BOOL disabled;
@property (nonatomic, readonly) NSDictionary* constraints;
@property (nonatomic, readonly) P2UXCoordinate* x;
@property (nonatomic, readonly) P2UXCoordinate* y;
@property (nonatomic, readonly) P2UXCoordinate* w;
@property (nonatomic, readonly) P2UXCoordinate* h;
@property (nonatomic, readonly) NSArray* events;
@property (nonatomic, readonly) NSDictionary* itemspec;
@property (nonatomic)           CGRect frame;
@property (nonatomic, readonly) BOOL requiresSizeUpdate;

- (id) initWithSpec:(NSDictionary*)spec elId:(NSString*)elId;
- (id) initWithSpec:(NSDictionary*)spec elId:(NSString*)elId defaults:(P2UXState*)defaults;

- (void) initializeState:(OSViewClass*)view parent:(OSViewClass*)parent parentRect:(CGRect)parentRect controls:(NSDictionary*) controls;
- (void) initializeState:(OSViewClass*)view parent:(OSViewClass*)parent parentRect:(CGRect)parentRect controls:(NSDictionary*) controls def:(P2UXState*)def;
- (BOOL) attributeInState:(NSString*)attribute;

- (void) cleanup;
- (void) clearEvents;

- (void) parse:(NSDictionary*)dict;
- (id) constraintForKey:(NSString*) key;

- (CGRect) rectFromParentX:(CGRect)xRect y:(CGRect)yRect w:(CGSize)w h:(CGSize)h scale:(CGFloat)scale;
- (CGRect) rectFromParentX:(CGRect)xRect y:(CGRect)yRect w:(CGSize)width h:(CGSize)height def:(P2UXState*)def scale:(CGFloat)scale;

- (void) updateFrameUsingParent:(OSViewClass*)parent parentRect:(CGRect)parentRect controls:(NSDictionary*)controls def:(P2UXState*)def;
- (BOOL) updateConstraintsForSizeChange:(OSViewClass*)view parent:(OSViewClass*)parent controls:(NSDictionary*) controls def:(P2UXState*)def;

- (BOOL) isValidFrameSpec;

- (NSArray*) eventsWithEventType:(P2UXElementEvent)event;
- (BOOL) hasDefinedEvents;
- (void) addEvent:(P2UXEvent*)event;
- (void) setRect:(CGRect)rect;
- (BOOL) sizeToFitWidth;
- (BOOL) sizeToFitHeight;
@end
