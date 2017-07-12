//
//  P2UXEventHandler.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 12/4/13.
//  Copyright (c) 2013 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <P2UXCore/P2UXEventTransition.h>
#import <P2UXCore/P2UXViewContainerDelegate.h>

@class P2UXEventHandler;
@class P2UXEvent;
@class P2UXEventAction;
@class P2UXElement;
@class P2UXElementInstance;
@class P2UXEventTransition;

extern NSString* const P2UXNotification_CheckForUpdates;

@protocol P2UXEventHandlerDelegate <NSObject>
- (void) eventsComplete:(P2UXEventHandler*)handler;
@end

@interface P2UXEventHandler : NSObject<P2UXEventTransitionDelegate>
{
    P2UXElementInstance*        _element;
    P2UXEvent*                  _event;
    NSArray*                  _events;
    NSInteger                 _eventIndex;
    __weak id                 _source;
    NSInteger                 _result;
}
@property (nonatomic, weak) id<P2UXEventHandlerDelegate> delegate;
@property (nonatomic, weak) id<P2UXViewContainerDelegate> viewDelegate;

- (id) initWithEvents:(NSArray*)events element:(P2UXElementInstance*)element source:(id)source;
- (void) handleEvents:(NSInteger)result;

- (void) cleanup;
- (P2UXView*) currentView;

#pragma mark - P2UXEventTransitionDelegate
- (void) transitionComplete:(OSViewClass *)view outgoing:(OSViewClass*)outgoing transition:(P2UXEventTransition *)transition;
- (void) transitionReverseComplete:(OSViewClass *)view outgoing:(OSViewClass*)outgoing transition:(P2UXEventTransition*)transition;

#pragma protected
- (void) processNextEvent;
- (void) handleActionComplete;
- (BOOL) handleEvent:(id)sender event:(P2UXEvent*)event element:(P2UXElementInstance*)elem;
- (BOOL) handleShowView:(P2UXEventAction*)action transition:(P2UXEventTransition*)transition sender:(id)sender;
- (void) handleBack:(P2UXEventAction*)action;
- (void) handleViewAction:(P2UXEventAction*)action elem:(P2UXElementInstance*)elem sender:(id)sender;
- (void) handleTextInput:(P2UXEventAction*)action elem:(P2UXElementInstance*)elem sender:(id)sender;
- (void) handleIncrement:(P2UXEventAction*)action elem:(P2UXElementInstance*)elem;
- (void) handleCloseApp;
- (BOOL) handleSetState:(P2UXEventAction*)action element:(P2UXElementInstance*)elem sender:(id)sender;
- (void) handleEventComplete;
- (void) handleEventsComplete;
- (void) handleSendMessage:(P2UXEventAction*)action sender:(id)sender;
- (void) handleSetVariable:(P2UXEventAction*)action element:(P2UXElementInstance*)elem sender:(id)sender;
- (void) handleSetAttribute:(P2UXEventAction*)action sender:(id)sender result:(NSInteger)result;
- (BOOL) handleLaunchSystemApp:(P2UXEventAction*)action element:(P2UXElementInstance*)elem sender:(id)sender index:(id)index;
- (void) handleTimeIncrement:(P2UXEventAction*)action;
- (void) handleTimeOffset:(NSInteger)offset;
- (void) handleSetAppState:(P2UXEventAction*)action element:(P2UXElementInstance*)elem sender:(id)sender;
- (void) handleSetLanguage:(P2UXEventAction*)action;
- (void) handleCheckForUpdates;
- (void) handleShowNativeDialog:(P2UXEventAction*)action;
- (BOOL) handleSendSystemNotification:(P2UXEventAction*)action element:(P2UXElementInstance*)elem sender:(id)sender;
- (void) handleAnalyticsEvent:(P2UXEventAction*)action element:(P2UXElementInstance*)elem sender:(id)sender;
- (void) handleFocusNextControl:(P2UXEventAction*)action elem:(P2UXElementInstance*)elem sender:(id)sender;
- (void) handleFingerprintAuth:(P2UXEventAction*)action element:(P2UXElementInstance*)elem sender:(id)sender;
- (void) replaceArgs:(NSMutableDictionary*)args key:(NSString*)key value:(NSString*)value;
- (void) evalArgs:(NSMutableDictionary*)args linkValues:(NSDictionary*)linkValues conditionals:(NSDictionary*)conditionals;

- (P2UXView*) viewFromSender:(id)sender;
- (P2UXView*) viewFromSender:(id)sender context:(NSString*)context;;
@end
