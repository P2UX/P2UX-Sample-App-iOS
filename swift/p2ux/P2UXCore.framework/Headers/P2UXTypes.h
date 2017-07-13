//
//  P2UXTypes.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 10/1/14.
//  Copyright (c) 2014 Phase 2 Industries, LLC. All rights reserved.
//

#ifndef P2UXCore_UXTypes_h
#define P2UXCore_UXTypes_h

#if TARGET_OS_IOS || TARGET_OS_TV
#define OSViewClass UIView
#define OSFontClass UIFont
#define OSColorClass UIColor
#define OSImageClass UIImage
#else
#define OSViewClass NSView
#define OSFontClass NSFont
#define OSColorClass NSColor
#define OSImageClass NSImage
#endif

#define SYSTEM_VERSION_EQUAL_TO(v)                  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define SYSTEM_VERSION_GREATER_THAN(v)              ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)     ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)

#define DEGREES_TO_RADIANS(x) (M_PI * x / 180.0)
#define FONT_SCALING 0.7
#define DEFAULT_TIMEOUT 5.0 //sec

#define kBGQueue dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0)

extern NSString* const P2UXSize;
extern NSString* const P2UXSize_Width;
extern NSString* const P2UXSize_Height;
extern NSString* const P2UXPos;
extern NSString* const P2UXPos_X;
extern NSString* const P2UXPos_Y;
extern NSString* const P2UXCoordinate_Type;
extern NSString* const P2UXCoordinate_Val;
extern NSString* const P2UXMaxSize;

extern NSString* const P2UXLabelType_Standard;
extern NSString* const P2UXLabelType_Time;
extern NSString* const P2UXLabelType_Date;
extern NSString* const P2UXLabelType_Temp;
extern NSString* const P2UXLabelType_Timestamp;

extern NSString* const P2UXApp_Type;
extern NSString* const P2UXMobileApp_Type;

extern NSString* const P2UXInfoType_Version;
extern NSString* const P2UXInfoType_Name;

extern NSString* const P2UXView_Landscape;
extern NSString* const P2UXView_Portrait;

extern NSString* const P2UXView_Background_Type;
extern NSString* const P2UXView_Background_Value;

extern NSString* const P2UXDefault_Control_Font;
extern NSString* const P2UXDefault_Button_Normal;
extern NSString* const P2UXDefault_Button_Touch;
extern NSString* const P2UXDefault_Button_Selected;
extern NSString* const P2UXDefault_Button_Disabled;
extern NSString* const P2UXDefault_Button_Selected_Down;
extern NSString* const P2UXDefault_Image;

extern NSString* const P2UXDefault_Scroll_Arrow_Up_Normal;
extern NSString* const P2UXDefault_Scroll_Arrow_Up_Touch;
extern NSString* const P2UXDefault_Scroll_Arrow_Up_Disabled;
extern NSString* const P2UXDefault_Scroll_Arrow_Down_Normal;
extern NSString* const P2UXDefault_Scroll_Arrow_Down_Touch;
extern NSString* const P2UXDefault_Scroll_Arrow_Down_Disabled;
extern NSString* const P2UXDefault_Scroll_Thumb;
extern NSString* const P2UXDefault_Scroll_Tray;

extern NSString* const P2UXDefault_Slider_Btn_Up_Normal;
extern NSString* const P2UXDefault_Slider_Btn_Up_Touch;
extern NSString* const P2UXDefault_Slider_Btn_Down_Normal;
extern NSString* const P2UXDefault_Slider_Btn_Down_Touch;

extern NSString* const P2UXDefault_Page_Indicator_Normal;
extern NSString* const P2UXDefault_Page_Indicator_Active;

extern NSString* const P2UXZipExt;
extern NSString* const P2UXJSONExt;

extern NSString* const P2UXElement_Ctrl;
extern NSString* const P2UXElement_Id;
extern NSString* const P2UXElement_Type;
extern NSString* const P2UXElement_SystemType;
extern NSString* const P2UXElement_Opacity;
extern NSString* const P2UXElement_AltId;
extern NSString* const P2UXElement_Focus;
extern NSString* const P2UXElement_CanFocus;
extern NSString* const P2UXElement_Background;
extern NSString* const P2UXElement_Style;

extern NSString* const P2UXElement_Attrib_Margins;
extern NSString* const P2UXElement_Attrib_Stops;
extern NSString* const P2UXElement_Attrib_Type;
extern NSString* const P2UXElement_Attrib_State;
extern NSString* const P2UXElement_Attrib_States;
extern NSString* const P2UXElement_Attrib_Value;
extern NSString* const P2UXElement_Attrib_Color;
extern NSString* const P2UXElement_Attrib_Image;
extern NSString* const P2UXElement_Attrib_Icon;
extern NSString* const P2UXElement_Attrib_Align;
extern NSString* const P2UXElement_Attrib_Offset;
extern NSString* const P2UXElement_Attrib_Rate;
extern NSString* const P2UXElement_Attrib_Label;
extern NSString* const P2UXElement_Attrib_Selected;
extern NSString* const P2UXElement_Attrib_Enabled;
extern NSString* const P2UXElement_Attrib_Font;
extern NSString* const P2UXElement_Attrib_Name;
extern NSString* const P2UXElement_Attrib_Max;
extern NSString* const P2UXElement_Attrib_Min;
extern NSString* const P2UXElement_Attrib_OffsetX;
extern NSString* const P2UXElement_Attrib_OffsetY;
extern NSString* const P2UXElement_Attrib_Rows;
extern NSString* const P2UXElement_Attrib_Cols;
extern NSString* const P2UXElement_Attrib_Empty;
extern NSString* const P2UXElement_Attrib_Itemspec;
extern NSString* const P2UXElement_Attrib_DataType;
extern NSString* const P2UXElement_Attrib_Datasource;
extern NSString* const P2UXElement_Attrib_Scale;
extern NSString* const P2UXElement_Attrib_Radius;
extern NSString* const P2UXElement_Attrib_DataIndexed;
extern NSString* const P2UXElement_Attrib_Events;
extern NSString* const P2UXElement_Attrib_Visible;
extern NSString* const P2UXElement_Attrib_LinkFilters;
extern NSString* const P2UXElement_Attrib_LinkVars;
extern NSString* const P2UXElement_Attrib_LinkConditions;
extern NSString* const P2UXElement_Attrib_LinkOutFilters;
extern NSString* const P2UXElement_Attrib_Data;
extern NSString* const P2UXElement_Attrib_Shadow;
extern NSString* const P2UXElement_Attrib_TapThrough;
extern NSString* const P2UXElement_Attrib_Fill;
extern NSString* const P2UXElement_Attrib_Links;
extern NSString* const P2UXElement_Attrib_Rotation;
extern NSString* const P2UXElement_Attrib_Animations;
extern NSString* const P2UXElement_Attrib_Duration;
extern NSString* const P2UXElement_Attrib_Easing;
extern NSString* const P2UXElement_Attrib_Delay;
extern NSString* const P2UXElement_Attrib_Ignored;
extern NSString* const P2UXElement_Attrib_KeyboardOffset;
extern NSString* const P2UXElement_Attrib_Vars;
extern NSString* const P2UXElement_Attrib_Location;
extern NSString* const P2UXElement_Attrib_Refresh;
extern NSString* const P2UXElement_Attributes;
extern NSString* const P2UXElement_Attributes_Tagged;
extern NSString* const P2UXElement_Attrib_Layout;
extern NSString* const P2UXElement_Attrib_GradientType;
extern NSString* const P2UXElement_Attrib_Direction;
extern NSString* const P2UXElement_Attrib_Rect;
extern NSString* const P2UXElement_Attrib_Controls;
extern NSString* const P2UXElement_Attrib_SizeToFitWidth;
extern NSString* const P2UXElement_Attrib_SizeToFitHeight;
extern NSString* const P2UXElement_Attrib_Increment;
extern NSString* const P2UXElement_Attrib_Decrement;
extern NSString* const P2UXElement_Attrib_RelType;
extern NSString* const P2UXElement_Attrib_Updates;
extern NSString* const P2UXElement_Attrib_Removals;
extern NSString* const P2UXElement_Attrib_Orientation;
extern NSString* const P2UXElement_Attrib_Indexes;
extern NSString* const P2UXElement_Attrib_ZOrder;
extern NSString* const P2UXElement_Attrib_Overlay;
extern NSString* const P2UXElement_Attrib_CtrlLink;
extern NSString* const P2UXElement_Attrib_Relative;
extern NSString* const P2UXElement_Attrib_RadioBtn;

extern NSString* const P2UXElement_Gradient_DefaultColor;

extern NSString* const P2UXGeneral_Size_Attrib;
extern NSString* const P2UXGeneral_Position_Attrib;

extern NSString* const P2UXElement_Align_Center;
extern NSString* const P2UXElement_Align_Top;
extern NSString* const P2UXElement_Align_Bottom;
extern NSString* const P2UXElement_Align_Left;
extern NSString* const P2UXElement_Align_Right;

extern NSString* const P2UXElement_Swipe_Direction_Left;
extern NSString* const P2UXElement_Swipe_Direction_Right;
extern NSString* const P2UXElement_Swipe_Direction_Up;
extern NSString* const P2UXElement_Swipe_Direction_Down;

extern NSString* const P2UXVariable_Attrib_Value;
extern NSString* const P2UXVariable_Attrib_Values;
extern NSString* const P2UXVariable_Attrib_Ident;
extern NSString* const P2UXVariable_Attrib_Attribute;
extern NSString* const P2UXVariable_Attrib_Attributes;
extern NSString* const P2UXVariable_Attrib_Var;
extern NSString* const P2UXVariable_Attrib_Key;
extern NSString* const P2UXVariable_Attrib_Request;
extern NSString* const P2UXVariable_Attrib_Requests;
extern NSString* const P2UXVariable_Attrib_SystemType;
extern NSString* const P2UXVariable_Attrib_Args;
extern NSString* const P2UXVariable_Attrib_Success;
extern NSString* const P2UXVariable_Attrib_Animated;
extern NSString* const P2UXVariable_Attrib_ValuesFmt;
extern NSString* const P2UXVariable_Attrib_NotifyChange;
extern NSString* const P2UXVariable_Attrib_Context;
extern NSString* const P2UXVariable_Attrib_ItemContext;
extern NSString* const P2UXVariable_Attrib_Index;
extern NSString* const P2UXVariable_Attrib_Parent;
extern NSString* const P2UXVariable_Attrib_Screen;
extern NSString* const P2UXVariable_Attrib_Container;
extern NSString* const P2UXVariable_Attrib_DefaultState;

extern NSString* const P2UXControl_Attrib_Index;

// External Notifications
extern NSString* const P2UXExternalEvent_Route;

// Notifications
extern NSString* const P2UXNotify_VehicleDataUpdate;
extern NSString* const P2UXNotify_DestinationUpdate;
extern NSString* const P2UXNotify_LoadNavigationRoute;
extern NSString* const P2UXNotify_SpeedManualChange;
extern NSString* const P2UXNotify_HeadingManualChange;
extern NSString* const P2UXNotify_SettingsUpdate;
extern NSString* const P2UXNotify_AppInstall;
extern NSString* const P2UXNotify_RadioInit;
extern NSString* const P2UXNotify_AppFocus;
extern NSString* const P2UXNotify_SetDest;
extern NSString* const P2UXNotify_AlertMsg;
extern NSString* const P2UXNotify_PhoneDialing;
extern NSString* const P2UXNotify_PhoneCallConnected;
extern NSString* const P2UXNotify_PhoneCallRinging;
extern NSString* const P2UXNotify_PhoneCallMissed;
extern NSString* const P2UXNotify_PhoneCallEnded;
extern NSString* const P2UXNotify_LaunchMap;
extern NSString* const P2UXNotify_TimeUpdate;
extern NSString* const P2UXNotify_LanguageChange;
extern NSString* const P2UXNotify_NewLocation;
extern NSString* const P2UXNotify_SwitchedTheme;
extern NSString* const P2UXNotify_ControlState;
extern NSString* const P2UXNotify_CurrentApp;
extern NSString* const P2UXNotify_PredefinedMessagesChange;
extern NSString* const P2UXNotify_NewText;
extern NSString* const P2UXNotify_DeleteText;
extern NSString* const P2NotifyValue_ChangedKeys;

extern NSString* const P2UXNotify_DataSource_Fetch_Start;
extern NSString* const P2UXNotify_DataSource_Fetch_Complete;

extern NSString* const P2UXTime_Format;
extern NSString* const P2UXAnimation_Image_Format;

extern NSString* const P2UXApplicationStateChange_Notify;
extern NSString* const P2UXApplicationState_Attrib_Name;
extern NSString* const P2UXApplicationState_Attrib_App;
extern NSString* const P2UXCloseTextInput_Message;

extern NSString* const P2UXDictionary_PathSeparator;

extern NSString* const P2UXDefault_Screen_State;
extern CGFloat const P2UXDefault_Shadow_Opacity;
extern CGFloat const P2UXDefault_Shadow_Radius;
extern CGFloat const P2UXDefault_Shadow_Offset;
extern CGFloat const P2UXDefault_Fade_In_Time;
extern CGFloat const P2UXDefault_Fade_Out_Time;
extern CGFloat const P2UXInvalid_Lat;
extern CGFloat const P2UXInvalid_Lon;


typedef NS_ENUM(NSInteger, P2UXBackgroundType) {
    P2UXBackgroundType_None = -1,
    P2UXBackgroundType_Color = 0,
    P2UXBackgroundType_Image,
    P2UXBackgroundType_Remote,
    P2UXBackgroundType_URL,
    P2UXBackgroundType_Gradient
};

typedef NS_ENUM(NSInteger, P2UXControlState) {
   P2UXControlState_Normal = 0,
   P2UXControlState_Down,
   P2UXControlState_Selected,
   P2UXControlState_Disabled,
   P2UXControlState_SelectedDown // deprecated
};

typedef NS_ENUM(NSInteger, P2UXDataSourceType) {
   P2UXDataSourceType_UserDef = 0,
   P2UXDataSourceType_Apps,
   P2UXDataSourceType_AllMusic,
   P2UXDataSourceType_MusicArtists,
   P2UXDataSourceType_MusicAlbums,
   P2UXDataSourceType_Photos,
   P2UXDataSourceType_PhotoAlbums
};

typedef NS_ENUM(NSInteger, P2UXGradientType) {
    P2UXGradientType_None = -1,
    P2UXGradientType_Angular = 0,
    P2UXGradientType_Radial,
    P2UXGradientType_Linear
};

typedef NS_ENUM(NSInteger, P2UXControlType) {
    P2UXCtrlType_Radio = 0,
    P2UXCtrlType_Button,
    P2UXCtrlType_Slider,
    P2UXCtrlType_Label,
    P2UXCtrlType_Group,
    P2UXCtrlType_BtnPopup,
    P2UXCtrlType_Grid,
    P2UXCtrlType_Image,
    P2UXCtrlType_Progress_Deprecated,
    P2UXCtrlType_RotaryButton,
    P2UXCtrlType_TouchSlider_Deprecated,
    P2UXCtrlType_Divider,
    P2UXCtrlType_ToggleLabel,
    P2UXCtrlType_List,
    P2UXCtrlType_PageIndicator,
    P2UXCtrlType_Clock,
    P2UXCtrlType_BusyIndicator,
    P2UXCtrlType_DropDown,
    P2UXCtrlType_ScrollContainer,
    P2UXCtrlType_RadialProgress,
    P2UXCtrlType_Map,
    P2UXCtrlType_ViewContainer,
    P2UXCtrlType_Button2,
    P2UXCtrlType_TextInput,
    P2UXCtrlType_Shape,
    P2UXCtrlType_ListButton = 25,
    P2UXCtrlType_ListGroup = 26,
    P2UXCtrlType_CollectionView = 27,
    P2UXCtrlType_VideoPlayer,
    P2UXCtrlType_WebView,
    P2UXCtrlType_Scrollbar = 30,
    P2UXCtrlType_Progress,
    P2UXCtrlType_Custom = 32,
    P2UXCtrlType_Carousel = 33,
    P2UXCtrlType_DateTimePicker,
    P2UXCtrlType_CollectionGridView,
    P2UXCtrlType_TouchSlider,
    P2UXCtrlType_Picker,
    P2UXCtrlType_Switch,
    P2UXCtrlType_Line
};

typedef NS_ENUM(NSInteger, P2UXScrollStyle) {
    P2UXScrollStyle_None = -1,
    P2UXScrollStyle_Vert = 0,
    P2UXScrollStyle_Horz
};

typedef NS_ENUM(NSInteger, P2UXControlDataType) {
    P2UXControlDataType_Static = 0,
    P2UXControlDataType_Dynamic
};

typedef NS_ENUM(NSInteger, P2UXGridDataType) {
    P2UXGridDataType_Static = 0,
    P2UXGridDataType_Dynamic
};

typedef NS_ENUM(NSInteger, P2UXPageIndicatorType) {
    P2UXPageIndicator_Vertical = 0,
    P2UXPageIndicator_Horizontal
};

typedef NS_ENUM(NSInteger, P2UXPageIndicatorComponentType) {
    P2UXPageIndicator_Normal = 70,
    P2UXPageIndicator_Active
};

typedef NS_ENUM(NSInteger, P2UXListScrollType) {
    P2UXListScrollType_Default = 0,
    P2UXListScrollType_Pagination
};

typedef NS_ENUM(NSInteger, P2UXScrollBarComponentType) {
    P2UXScrollBarComponentType_UpBtn = 40,
    P2UXScrollBarComponentType_DownBtn,
    P2UXScrollBarComponentType_Thumb,
    P2UXScrollBarComponentType_Background
};

typedef NS_ENUM(NSInteger, P2UXScaleType) {
    P2UXScaleType_Both = 0,
    P2UXScaleType_FitAspect,
    P2UXScaleType_FillAspect,
    P2UXScaleType_Center,
    P2UXScaleType_Top,
    P2UXScaleType_Bottom,
    P2UXScaleType_Left,
    P2UXScaleType_Right,
    P2UXScaleType_TopLeft,
    P2UXScaleType_TopRight,
    P2UXScaleType_BottomLeft,
    P2UXScaleType_BottomRight
};

typedef NS_ENUM(NSInteger, P2UXAutoCaps) {
    P2UXAutoCaps_None = 0,
    P2UXAutoCaps_Words,
    P2UXAutoCaps_Sentences,
    P2UXAutoCaps_Characters
};

typedef NS_ENUM(NSInteger, P2UXKeyboardType) {
    P2UXKeyboardType_Default = 0,
    P2UXKeyboardType_NumberPad,
    P2UXKeyboardType_PhonePad,
    P2UXKeyboardType_Email,
    P2UXKeyboardType_DecimalPad,
    P2UXKeyboardType_URL
};

typedef NS_ENUM(NSInteger, P2UXArgType) {
    P2UXArgType_Constant = 0,
    P2UXArgType_Variable
};

typedef NS_ENUM(NSInteger, P2UXRequestState) {
    P2UXRequestState_Idle = 0,
    P2UXRequestState_Inprogress,
    P2UXRequestState_Complete
};

typedef NS_ENUM(NSInteger, P2UXElementLayoutDim) {
    P2UXElementLayoutDim_None = 0,
    P2UXElementLayoutDim_Height = 1,
    P2UXElementLayoutDim_Width = 2
};

typedef NS_ENUM(NSInteger, P2UXReturnKeyType) {
    P2UXReturnKeyType_Default = 0,
    P2UXReturnKeyType_Go,
    P2UXReturnKeyType_Join,
    P2UXReturnKeyType_Next,
    P2UXReturnKeyType_Search,
    P2UXReturnKeyType_Send,
    P2UXReturnKeyType_Done
};

typedef NS_OPTIONS(NSInteger, P2UXGesture) {
    P2UXGesture_Tap = 1,
    P2UXGesture_LongPress = 1<<2,
    P2UXGesture_SwipeLeft = 1<<3,
    P2UXGesture_SwipeRight = 1<<4,
    P2UXGesture_SwipeUp = 1<<5,
    P2UXGesture_SwipeDown = 1<<6,
    P2UXGesture_DoubleTap = 1<<7
};

typedef NS_ENUM(NSInteger, P2UXOrientationType) {
    P2UXOrientationType_Undefined = 0,
    P2UXOrientationType_Portrait = 1,
    P2UXOrientationType_Landscape = 2,
    P2UXOrientationType_Any = 3
};

typedef NS_ENUM(NSInteger, P2UXZOrder) {
    P2UXZOrder_Top = -1,
    P2UXZOrder_Bottom = 0
};

typedef NS_ENUM(NSInteger, P2UXFormFactor) {
    P2UXFormFactor_Phone = 0,
    P2UXFormFactor_Tablet,
    P2UXFormFactor_Vehicle,
    P2UXFormFactor_Watch,
    P2UXFormFactor_TV
};


#endif
