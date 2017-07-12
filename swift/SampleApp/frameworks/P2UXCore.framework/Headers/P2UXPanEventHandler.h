//
//  P2UXPanEventHandler.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 12/15/14.
//  Copyright (c) 2014 Phase 2 Industries, LLC. All rights reserved.
//

#import <P2UXCore/P2UXEventHandler.h>
@class P2UXBehavior;
@class P2UXEvent;

typedef NS_ENUM(NSInteger, P2UXPanAxisType)
{
    P2UXPanAxis_Any = 0,
    P2UXPanAxis_Y,
    P2UXPanAxis_X
} ;

typedef NS_ENUM(NSInteger, P2UXPanDirection)
{
    P2UXPanDirection_None = -1,
    P2UXPanDirection_Any = 0,
    P2UXPanDirection_Left = 1<<0,
    P2UXPanDirection_Right = 1<<1,
    P2UXPanDirection_Up = 1<<2,
    P2UXPanDirection_Down = 1<<3,
    P2UXPanDirection_Horizontal = P2UXPanDirection_Left|P2UXPanDirection_Right,
    P2UXPanDirection_Vertical = P2UXPanDirection_Up|P2UXPanDirection_Down
};

extern NSString* const P2UXPanEvent_Direction;

extern NSString* const P2UXPanEvent_Direction_Right;
extern NSString* const P2UXPanEvent_Direction_Left;
extern NSString* const P2UXPanEvent_Direction_Up;
extern NSString* const P2UXPanEvent_Direction_Down;
extern NSString* const P2UXPanEvent_Direction_Horizontal;
extern NSString* const P2UXPanEvent_Direction_Vertical;

@protocol P2UXPanEventHandlerDelegate <NSObject>

- (void) panComplete:(BOOL)cancelled;
@end

@interface P2UXPanEventHandler : P2UXEventHandler
{
}
@property (nonatomic, weak) id<P2UXPanEventHandlerDelegate> panDelegate;
+ (P2UXPanDirection) directionForEvents:(NSArray*)events;
+ (P2UXPanDirection) directionForEvent:(P2UXEvent*)event;
- (id) initWithEvents:(NSArray *)events element:(P2UXElementInstance *)element source:(id)source view:(P2UXView*)view;
- (BOOL) handlePanEvent:(UIPanGestureRecognizer*)recognizer;
@end
