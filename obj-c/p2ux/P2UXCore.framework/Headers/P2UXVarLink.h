//
//  P2UXVarLink.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 12/20/13.
//  Copyright (c) 2013 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, P2UXVarLinkSystemType)
{
    P2UXVarLinkSystemType_Local,
    P2UXVarLinkSystemType_System
} ;

typedef NS_ENUM(NSInteger, P2UXVarLinkType)
{
    P2UXVarLinkType_Const = -1,
    P2UXVarLinkType_App = 0,
    P2UXVarLinkType_External,
    P2UXVarLinkType_DataSource,
    P2UXVarLinkType_Display,
    P2UXVarLinkType_GPS,
    P2UXVarLinkType_Control,
    P2UXVarLinkType_Param,
    P2UXVarLinkType_BatchDataSource,
    P2UXVarLinkType_ViewParam,
    P2UXVarLinkType_DataProgress,
    P2UXVarLinkType_TransientGlobal,
    P2UXVarLinkType_AppSecure,
    P2UXVarLinkType_DeviceMediaVariable,
    P2UXVarLinkType_ArrayNameValue
};

typedef NS_ENUM(NSInteger, P2UXDataPolicy)
{
    P2UXDataPolicy_Fetch_Never = 0,
    P2UXDataPolicy_Fetch_If_Empty,
    P2UXDataPolicy_Fetch_If_Expired,
    P2UXDataPolicy_Fetch_Always
};

typedef NS_ENUM(NSInteger, P2UXVarMessageType)
{
    P2UXVarMessageType_Data = 0,
    P2UXVarMessageType_Variable
};

extern NSString* const P2UXApplication_Value_Update;
extern NSString* const P2UXDisplay_Value_Update;
extern NSString* const P2UXTransientGlobal_Value_Update;
extern NSString* const P2UXDeviceMedia_Value_Update;
extern NSString* const P2UXDataSourceType_Value_Update;
extern NSString* const P2UXBatch_DataSource_Value_Update;
extern NSString* const P2UXDataSourceType_Item_Value_Update;
extern NSString* const P2UXVarLink_Attrib_Attribute;
extern NSString* const P2UXVarLink_Attrib_Attributes;
extern NSString* const P2UXIndexReplacement;
extern NSString* const P2UXDataSourceType_Progress;
extern NSString* const P2UXVarLink_Attrib_Transition;
extern NSString* const P2UXVarLink_Attrib_Fields;
extern NSString* const P2UXVarLink_Attrib_FieldValue;
extern NSString* const P2UXVarLink_Attrib_Src;
extern NSString* const P2UXVarLink_Attrib_Ctrls;

extern NSString* const P2UXVarLink_Message_TwoParam_Fmt;
extern NSString* const P2UXVarLink_Message_OneParam_Fmt;

@class P2UXVarLink;
@class P2UXView;
@class P2UXElementInstance;
@class P2UXEventTransition;
@class P2UXDataIndex;
@class P2UXSourcedData;

@interface P2UXVarLink : NSObject
{
    P2UXVarLinkType      _itemType;
    NSMutableDictionary* _args;
    NSMutableDictionary* _vars;
    NSString*            _itemContext;
    NSString*            _ident;
    NSString*            _request;
    NSString*            _context;
    NSString*            _var;
}
@property (nonatomic,readonly) P2UXVarLinkSystemType varType;
@property (nonatomic,readonly) P2UXVarLinkType itemType;
@property (nonatomic,readonly) NSString* name;
@property (nonatomic,readonly) NSString* ident;
@property (nonatomic,readonly) NSString* systemType;
@property (nonatomic,readonly) NSString* var;
@property (nonatomic,readonly) NSString* request;
@property (nonatomic,readonly) NSString* context;
@property (nonatomic,readonly) NSString* itemContext;
@property (nonatomic,readonly) NSDictionary* params;
@property (nonatomic,readonly) NSArray*  sources;
@property (nonatomic,readonly) NSDictionary* itemSpec;
@property (nonatomic,readonly) P2UXEventTransition* transition;
@property (nonatomic,readonly) NSArray* args;
@property (nonatomic,readonly) BOOL defaultIndex;
@property (nonatomic,readonly) NSDictionary* argsValue;
@property (nonatomic,readonly) P2UXDataPolicy policy;
@property (nonatomic,readonly) BOOL notifyChange;
@property (nonatomic)          P2UXDataIndex* dataIndex;
@property (nonatomic,readonly) BOOL indexed;
@property (nonatomic)          id index;
@property (nonatomic,readonly) id indexValue;
@property (nonatomic,readonly) id val;
@property (nonatomic,readonly) NSArray* vars;
@property (nonatomic,readonly) id defaultValue;
@property (nonatomic,readonly) BOOL updatable;
@property (nonatomic,readonly) BOOL errorData;
@property (nonatomic)          BOOL async;
@property (nonatomic,readonly) BOOL autoUpdate;
@property (nonatomic,readonly) BOOL encode;
@property (nonatomic,readonly) NSArray* paths;

+ (NSString*) notificationMsg:(NSInteger)itemType;
+ (P2UXVarMessageType) notificationMsgType:(NSInteger)itemType;
+ (NSString*) formatNotificationType:(NSInteger)type param1:(NSString*)param1;
+ (NSString*) formatNotificationType:(NSInteger)type param1:(NSString*)param1 param2:(NSString*)param2;
+ (NSString*) formatNotificationFromMsg:(NSString*)msg param1:(NSString*)param1;
+ (NSString*) formatNotificationFromMsg:(NSString*)msg param1:(NSString*)param1 param2:(NSString*)param2;

- (void)      cleanup;
- (id)        initWithDictionary:(NSDictionary*)spec index:(id)index context:(id)context viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;
- (NSString*) notificationMsg;
- (P2UXVarMessageType) notificationMsgType;
- (BOOL)      isFiltered;
- (id)        filteredValueFromData:(P2UXSourcedData*)data;
- (void)      updateIndexValue:(id)value;
- (BOOL)      hasAttribute:(NSString*)attribute;
- (void)      updateLinkedValues:(id)context viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;

- (void)      parse:(NSDictionary*)spec viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;
@end
