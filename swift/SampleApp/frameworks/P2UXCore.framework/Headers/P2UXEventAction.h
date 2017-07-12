//
//  P2UXEventAction.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 3/11/15.
//  Copyright (c) 2015 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger,P2UXElementAction) {
    P2UXElementAction_Invalid = 0,
    P2UXElementAction_Show,
    P2UXElementAction_ShowPanel,
    P2UXElementAction_ShowDialog,
    P2UXElementAction_Back = 5,
    P2UXElementAction_HideGroup,
    P2UXElementAction_ShowGroup,
    P2UXElementAction_TextInput,
    P2UXElementAction_Media,
    P2UXElementAction_AudioStop,
    P2UXElementAction_AudioNext,
    P2UXElementAction_AudioPrev,
    P2UXElementAction_AudioPause,
    P2UXElementAction_HidePanel,
    P2UXElementAction_HideOverlay,
    P2UXElementAction_SetViewState = 18,
    P2UXElementAction_SetState = 19,
    P2UXElementAction_CloseApp,
    P2UXElementAction_Increment,
    P2UXElementAction_DataSourceRequest,
    P2UXElementAction_SetLanguage,
    P2UXElementAction_IncrementTime,
    P2UXElementAction_ResetTime,
    P2UXElementAction_Track,
    P2UXElementAction_SendMessage,
    P2UXElementAction_SetVariable,
    P2UXElementAction_SetAttribute,
    P2UXElementAction_CheckForUpdates = 30,
    P2UXElementAction_LaunchSystemApp,
    P2UXElementAction_ShowNativeDialog,
    P2UXElementAction_UpdateDataValue = 33,
    P2UXElementAction_UpdateData = 34,
    P2UXElementAction_BatchDataSourceRequest,
    P2UXElementAction_SendSystemNotification,
    P2UXElementAction_PostAnalyticsEvent,
    P2UXElementAction_SelectMedia,
    P2UXElementAction_RemoveFiles,
    P2UXElementAction_FocusNextControl,
    P2UXElementAction_Animate,
    P2UXElementAction_CancelAnimate,
    P2UXElementAction_Fingerprint,
    P2UXElementAction_UserAuthCode = 200,
    P2UXElementAction_UserAuthPwd = 201
};

typedef NS_ENUM(NSInteger,P2UXEventBackHistory) {
    P2UXEventBackHistory_No = 0,
    P2UXEventBackHistory_Yes,
    P2UXEventBackHistory_Replace
};

extern NSString* const P2UXAction_Attrib_Action;
extern NSString* const P2UXAction_Attrib_TargetItem;
extern NSString* const P2UXAction_Update_Save;
extern NSString* const P2UXAction_Update_Revert;
extern NSString* const P2UXAction_Update_Remove;
extern NSString* const P2UXAction_Attrib_ClearDefault;
extern NSString* const P2UXAction_Attrib_Context;
extern NSString* const P2UXAction_Context_Container;
extern NSString* const P2UXAction_Context_Screen;

extern NSString* const P2UXAction_SysNotify_Num;
extern NSString* const P2UXAction_SysNotify_Msg;
extern NSString* const P2UXAction_SysNotify_Item;
extern NSString* const P2UXAction_SysNotify_Id;
extern NSString* const P2UXAction_SysNotify_Title;
extern NSString* const P2UXAction_SysNotify_Date;
extern NSString* const P2UXAction_SysNotify_Sound;
extern NSString* const P2UXAction_SysNotify_Type;
extern NSString* const P2UXAction_SysNotify_Data;

extern NSString* const P2UXAction_SysNotify_Type_Post;
extern NSString* const P2UXAction_SysNotify_Type_Clear;

extern NSString* const P2UXAction_UserAuthCode_Redeem;
extern NSString* const P2UXAction_UserAuthCode_Clear;

extern NSString* const P2UXAction_UserAuthPwd_Login;
extern NSString* const P2UXAction_UserAuthPwd_Logout;
extern NSString* const P2UXAction_UserAuthPwd_Username;
extern NSString* const P2UXAction_UserAuthPwd_Password;

@class P2UXEventTransition, P2UXView, P2UXEvent;

@interface P2UXEventAction : NSObject
{
    P2UXEventTransition* _transition;
}
@property (nonatomic,weak) P2UXEvent* event;
@property (nonatomic,readonly) P2UXEventTransition* transition;
@property (nonatomic,readonly) NSDictionary* target;
@property (nonatomic,readonly) P2UXElementAction action;
@property (nonatomic,readonly) NSString* item;
@property (nonatomic,readonly) NSString* targetData;
@property (nonatomic,readonly) id targetValue;
@property (nonatomic,readonly) NSString* targetAppStart;
@property (nonatomic,readonly) NSString* targetType;
@property (nonatomic,readonly) NSString* targetTextType;
@property (nonatomic,readonly) BOOL targetToggle;
@property (nonatomic,readonly) BOOL targetClearDefault;
@property (nonatomic,readonly) id targetParams;
@property (nonatomic,readonly) NSNumber* targetIncrement;
@property (nonatomic,readonly) P2UXEventBackHistory targetBackHistory;
@property (nonatomic,readonly) BOOL targetClearAppHistory;
@property (nonatomic,readonly) CGFloat delay;

- (id) initWithSpec:(NSDictionary*)spec event:(P2UXEvent*)event;
- (void) cleanup;

- (id) targetObjectForKey:(NSString*)key;
- (id) targetObjectFromData:(NSDictionary*)data forKey:(NSString*)key;

- (NSNumber*) targetTimeout:(BOOL)useDefault;

- (P2UXEventTransition*) transitionForView:(OSViewClass*)view;
- (id) linkedValue:(id)value;
@end
