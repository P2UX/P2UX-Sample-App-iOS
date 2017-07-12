//
//  P2UXEvent.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 6/11/13.
//  Copyright (c) 2013  Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <P2UXCore/P2UXEventAction.h>
typedef NS_ENUM(NSInteger, P2UXElementEvent) {
    P2UXElementEvent_Invalid = 0,
    P2UXElementEvent_Tap,
    P2UXElementEvent_LongPress,
    P2UXElementEvent_Selected,
    P2UXElementEvent_Deselected,
    P2UXElementEvent_SwipeLeft,
    P2UXElementEvent_SwipeRight,
    P2UXElementEvent_SwipeUp,
    P2UXElementEvent_SwipeDown,
    P2UXElementEvent_LoadView,
    P2UXElementEvent_Pan,
    P2UXElementEvent_StateChanged,
    P2UXElementEvent_Message,
    P2UXElementEvent_AppLoaded,
    P2UXElementEvent_Media,
    P2UXElementEvent_ValueChanged,
    P2UXElementEvent_FetchData_Start,
    P2UXElementEvent_FetchData_Complete,
    P2UXElementEvent_WillPullToRefresh,
    P2UXElementEvent_CancelPullToRefresh,
    P2UXElementEvent_PullToRefresh = 20,
    P2UXElementEvent_ExternalRequest,
    P2UXElementEvent_AttributeChanged,
    P2UXElementEvent_SystemNotifyTapped,
    P2UXElementEvent_Keyboard_Return,
    P2UXElementEvent_FingerprintAuth,
    P2UXElementEvent_UserAuth = 200
};

@class P2UXEventTransition;
@class P2UXElementInstance;

extern NSString* const P2UXEvent_Global_Message;
extern NSString* const P2UXEvent_Message_Name;
extern NSString* const P2UXEvent_Message_Data;
extern NSString* const P2UXEvent_Message_Element;
extern NSString* const P2UXEvent_Message_Sender;
extern NSString* const P2UXEvent_Media_Message;
extern NSString* const P2UXEvent_Layout;
extern NSString* const P2UXEvent_Target_Success;
extern NSString* const P2UXEvent_Target_Fail;
extern NSString* const P2UXEvent_Global_Attribute_Changed;
extern NSString* const P2UXEvent_Attrib_Value;
extern NSString* const P2UXEvent_Attrib_Name;
extern NSString* const P2UXEvent_Attrib_Actions;

extern NSString* const P2UXEvent_INPUT_VALUE;
extern NSString* const P2UXEvent_INPUT_BACKSPACE;
extern NSString* const P2UXEvent_INPUT_SPACE;
extern NSString* const P2UXEvent_INPUT_CUSTOM;
extern NSString* const P2UXEvent_INPUT_CLEAR;
extern NSString* const P2UXEvent_INPUT_NEWLINE;

extern NSString* const P2UXEvent_UserAuth_Message;
extern NSString* const P2UXEvent_UserAuth_Action;
extern NSString* const P2UXEvent_UserAuth_Result;
extern NSString* const P2UXEvent_Fingerprint_Result;

@interface P2UXEvent : NSObject
{
    P2UXElementEvent            _event;
    NSMutableDictionary*    _linkActions;
    NSArray*                _actions;
}
@property (nonatomic,readonly) P2UXElementEvent event;
@property (nonatomic,readonly) NSDictionary* itemspec;
@property (nonatomic) NSDictionary* eventParams;
@property (nonatomic, weak) id eventContext;
@property (nonatomic, weak) id<P2UXViewContainerDelegate> viewDelegate;
@property (nonatomic) BOOL enabled;

+ (void) SendGlobalMessageEvent:(NSString*)message data:(id)data sender:(id)sender;
+ (void) NotifyAttributeChanged:(NSString*)attribute value:(id)value sender:(id)sender;
+ (void) NotifyFingerprintResult:(BOOL)result data:(id)data sender:(id)sender;
+ (NSArray*) dataEventsWithEventType:(P2UXElementEvent)eventType ident:(NSString*)ident request:(NSString*)request events:(NSArray*)events;
+ (NSArray*) dataEventsWithEventType:(P2UXElementEvent)eventType systemType:(NSString*)systemType request:(NSString*)request events:(NSArray*)events;

- (id) initWithEventSpec:(NSDictionary *)spec;
- (id) initWithActions:(NSArray*)actions itemspec:(NSDictionary*)itemspec;
- (void) cleanup;
- (void) clearLinks;

- (P2UXVarLinks*) links;

- (NSArray*) actions;
- (NSArray*) actionsWithResult:(NSInteger)result context:(id)context;
- (id) itemSpecItem:(NSString*)itemName;

- (BOOL) isMessageEventNamed:(NSString*)message;
- (BOOL) isStateEventNamed:(NSString*)state;
- (BOOL) isFingerprintResultEqualTo:(BOOL)fingerprint;
- (BOOL) isAttributeEventForSender:(P2UXElementInstance*)elem named:(NSString*)named value:(id)value;
- (BOOL) isMediaAttributeEvent:(NSString*)attribute value:(id)value;
- (BOOL) isValueChangedEvent:(NSString*)msg;
- (void) resetLinks;
@end
