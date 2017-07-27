//
//  P2UXEventTransition.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 11/25/13.
//  Copyright (c) 2013 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <P2UXCore/easing.h>

typedef NS_ENUM(NSInteger, P2UXTransitionEasing) {
    P2UXTransitionEasing_None = 0,
    P2UXTransitionEasing_In,
    P2UXTransitionEasing_Out,
    P2UXTransitionEasing_InOut
};

typedef NS_ENUM(NSInteger, P2UXTransitionAttribute) {
    kP2UXTransitionAttribute_frame = 0,
    kP2UXTransitionAttribute_alpha
};

typedef NS_ENUM(NSInteger,P2UXTransitionSequence) {
    kP2UXTransitionSequence_Parallel = 0,
    kP2UXTransitionSequence_Serial
};

typedef NS_ENUM(NSInteger, P2UXTransitionBackHistory) {
    kP2UXTransitionBackHistory_No = 0,
    kP2UXTransitionBackHistory_Yes
};

@class P2UXEventTransition;

@protocol P2UXEventTransitionDelegate <NSObject>
- (void) transitionComplete:(OSViewClass *)view outgoing:(OSViewClass*)outgoing transition:(P2UXEventTransition*)transition;
- (void) transitionReverseComplete:(OSViewClass*)view outgoing:(OSViewClass*)outgoing transition:(P2UXEventTransition*)transition;
@end

typedef void (^TransitionComplete)(UIView* view, BOOL reverse);


@interface P2UXEventTransition : NSObject
{
    NSDictionary*           _desc;
    P2UXTransitionSequence  _sequence;
    NSMutableArray*         _delegates;
    NSMutableDictionary*    _transitionData;
}
@property (nonatomic, readonly) NSDictionary* desc;
@property (nonatomic, weak)     OSViewClass* source;
@property (nonatomic, readonly) NSString* ref;
@property (nonatomic)           BOOL reverse;
@property (nonatomic)           BOOL outgoing;
@property (nonatomic, readonly) CGFloat duration;
@property (nonatomic)           id data;
@property (nonatomic)           CGFloat delay;
@property (nonatomic, readonly) P2UXTransitionBackHistory backHistory;
@property (nonatomic) BOOL      below;
@property (nonatomic) NSDictionary* rect;
@property (nonatomic) BOOL      valid;
@property (nonatomic) BOOL      isDefault;
@property (nonatomic) BOOL      isFullScreen;

+ (AHEasingFunction) easing:(NSDictionary*)transition;
+ (P2UXEventTransition*) transitionForLayout:(NSString*)layout duration:(float)duration easing:(P2UXTransitionEasing)easing;

- (id)   initWithDictionary:(NSDictionary*)desc;
- (void) cleanup;

- (void) apply:(OSViewClass *)view outgoing:(OSViewClass*)outgoing data:(id)data;
- (void) apply:(OSViewClass *)view outgoing:(OSViewClass*)outgoing data:(id)data completion:(TransitionComplete)completion;
- (void) addDelegate:(__weak id<P2UXEventTransitionDelegate>)delegate;
- (void) removeDelegate:(id<P2UXEventTransitionDelegate>)delegate;
- (void) applyTransitionsToAttribute:(UICollectionViewLayoutAttributes*)attr parentBounds:(CGRect)parentBounds;
@end
