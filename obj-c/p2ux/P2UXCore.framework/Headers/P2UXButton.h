//
//  P2UXButton.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 10/1/14.
//  Copyright (c) 2014 Phase 2 Industries, LLC. All rights reserved.
//

#import <P2UXCore/P2UXControl.h>
#import <P2UXCore/P2UXActionDelegate.h>
#import <P2UXCore/P2UXVarLink.h>

enum {
    P2UXButton_ToggleEvent = 1 << 24,
    P2UXButton_TouchUpInsideEvent = 1<<25,
    P2UXButton_TouchUpInsideSelectorEvent = 1<<26,
    P2UXButton_LongPressEvent = 1<<27,
    P2UXButton_RadioEvent = 1<<28,
    P2UXButton_RadioStateEvent = 1<<29
};

// Button can have N states, but the default states are as follows:
#define P2UXButtonState_Unselected 0
#define P2UXButtonState_Selected 1

@class P2UXDefinition;

extern NSString* const P2UXButtonDisplayState_Normal;
extern NSString* const P2UXButtonDisplayState_Pressed;
extern NSString* const P2UXButtonDisplayState_Disabled;

extern NSString* const P2UXButtonType_Standard;
extern NSString* const P2UXButtonType_Toggle;
extern NSString* const P2UXButtonType_Radio;

extern NSString* const P2UXButtonLabelAttrib_AllCaps;
extern NSString* const P2UXButtonLabelAttrib_Font;

extern NSString* const P2UXButtonLabelAttrib_Text;
extern NSString* const P2UXButtonLabelAttrib_VAlign;
extern NSString* const P2UXButtonLabelAttrib_HAlign;
extern NSString* const P2UXButtonLabelAttrib_Height;
extern NSString* const P2UXButtonLabelAttrib_Underline;
extern NSString* const P2UXButtonLabelAttrib_Shadow;

extern NSString* const P2UXButtonAttrib_LongPress;
extern NSString* const P2UXButtonAttrib_Count;
extern NSString* const P2UXButtonAttrib_Pattern;
extern NSString* const P2UXButtonAttrib_Fill;
extern NSString* const P2UXButtonAttrib_Border;
extern NSString* const P2UXButtonAttrib_CornerRadius;
extern NSString* const P2UXButtonAttrib_Shadow;
extern NSString* const P2UXButtonAttrib_Width;

extern NSString* const P2UXButtonAttrib_BorderWidth;
extern NSString* const P2UXButtonAttrib_BorderColor;
extern NSString* const P2UXButtonAttrib_ShadowRadius;

extern NSString* const P2UXButtonAttrib_ShadowLayer;

extern NSString* const P2UXButtonShapeType_Rectangle;
extern NSString* const P2UXButtonShapeType_Ellipse;

extern NSString* const P2UXButton_Default_Label_Color;

@class P2UXElement;
@class P2UXElementInstance;
@class P2UXDisplayLayout;

@protocol P2UXButtonDelegate <NSObject>
- (void) itemBeforeClicked:(id)sender;
- (void) itemLongPressEvent:(UIGestureRecognizer*)recognizer;
@end

@interface P2UXButton : UIButton
{
    P2UXDefinition*     _parentDef;
    id<P2UXActionDelegate>    _handler;
    
    NSMutableArray*         _states;
    NSInteger               _currentState;  // The state of the button, Unselected, Selected, state-N
    
    float                   _marginX;
    float                   _marginY;
    UILongPressGestureRecognizer* _longPressRecognizer;
}

@property (nonatomic, weak) id<P2UXButtonDelegate> delegate;
@property (nonatomic, weak) id exdata;
@property (nonatomic, readonly) NSString* text;
@property (nonatomic, readonly) UILongPressGestureRecognizer* longPressRecognizer;
@property (nonatomic) NSInteger keyElem;
@property (nonatomic) NSString* iconPath;
@property (nonatomic) NSString* altData;
@property (nonatomic) CGRect originalFrame;
@property (nonatomic) BOOL notifyWhenSelected;
@property (nonatomic) NSArray* states;
@property (nonatomic) BOOL editMode;
@property (nonatomic) BOOL labelHidden;
@property (nonatomic) NSInteger currentState;
@property (nonatomic) NSString* btnType;

+ (CALayer*) createShadowMask:(NSDictionary*)shadowSpec shapeType:(NSString*)shapeType rect:(CGRect)rect borders:(NSArray*)borders borderMask:(UIBezierPath*)borderMaskPath viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;

-(id) initWithFrame:(CGRect)frame elemInst:(P2UXElementInstance*)elemInst uipath:(NSString*)path ext:(BOOL)ext handler:(id<P2UXActionDelegate>)handler viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate index:(id)index;
- (void) setupButton:(P2UXElementInstance*)elemInst uipath:(NSString*)path ext:(BOOL)ext;
- (void) handleDown:(id)sender;
- (void) handleUp:(id)sender;
- (void) click;

- (BOOL) setAttribute:(id)value withName:(NSString*)name relative:(BOOL)relative animated:(id)animated itemspec:(NSDictionary*)itemspec;
- (id) valueForAttribute:(NSString*)attribute;

- (void) setLabel:(NSString*)label;
- (void) setButtonFromSpec:(NSDictionary*)btnSpec refresh:(BOOL)refresh;
- (void) updateFromState;

#pragma mark - P2UXControl
-(void) setData:(NSDictionary *)data;
-(void) cleanup;
-(void) refreshControl;

@end
