//
//  P2UXView.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 11/26/12.
//  Copyright (c) 2013 Phase 2 Industries, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <P2UXCore/P2UXActionDelegate.h>
#import <P2UXCore/P2UXDefinition.h>
#import <P2UXCore/P2UXControl.h>
#import <P2UXCore/P2UXBaseCtrl.h>
#import <P2UXCore/P2UXElementInstance.h>
#import <P2UXCore/P2UXPanEventHandler.h>
#import <P2UXCore/P2UXData.h>
#import <P2UXCore/P2UXHelperDelegate.h>
#import <P2UXCore/P2UXScreenOrientation.h>

extern NSString* const P2UXView_Attribute_DragHandle;

@class P2UXBehavior, P2UXButton2, P2UXApplication, P2UXElementInstance, P2UXVarLinks, P2UXScreenOrientation;

@protocol P2UXViewInteractionDelegate <NSObject>
- (void) pageChange:(NSInteger)page pages:(NSInteger)pages;
@end

@interface P2UXView : UIView<UIGestureRecognizerDelegate, P2UXControl, P2UXActionDelegate, P2UXPanEventHandlerDelegate, P2UXData, P2UXScreenStateDelegate>
{
    NSString*                       _path;
    NSMutableDictionary*            _attributes;
    NSMutableArray*                 _focusChain;
    NSInteger                       _focusIndex;
    UIView*                         _currentView;
    id                              _initialBtn;
    P2UXElement*                      _initialElement;
    P2UXBaseCtrl*                     _navCtrl;
    NSMutableDictionary*            _radioStates;
    BOOL                            _initialized;
    id                              _viewData;
    BOOL                            _useTapHandler;
    BOOL                            _resizable;
    UITapGestureRecognizer*         _tapHandler;
    UILongPressGestureRecognizer*   _longHandler;
    int                             _eventIndex;
    NSString*                       _state;
    BOOL                            _useConstraints;
    __weak P2UXBehavior*              _behavior;
    UIImageView*                    _backgroundImage;
    NSString*                       _appState;
    P2UXScreenOrientation*            _orientation;
}
@property (nonatomic) P2UXDefinition* contents;
@property (nonatomic, weak) id<P2UXViewInteractionDelegate> behaviorDelegate;
@property (nonatomic, readonly) NSInteger pages;
@property (nonatomic, readonly) NSInteger page;
@property (nonatomic) NSString* title;
@property (nonatomic, readonly) NSString* type;
@property (nonatomic) BOOL topmost;
@property (nonatomic, weak) P2UXBehavior* behavior;
@property (nonatomic) id viewData;
@property (nonatomic) BOOL useTapHandler;
@property (nonatomic) BOOL cached;
@property (nonatomic) CGRect originalRect;
@property (nonatomic) NSString* state;
@property (nonatomic, readonly) NSString* ident;
@property (nonatomic) BOOL partialVisible;
@property (nonatomic,readonly) NSArray* loadEvents;
@property (nonatomic) BOOL stackCached;
@property (nonatomic) BOOL tapThrough;
@property (nonatomic,readonly) NSString* systemType;
@property (nonatomic) UIView* dragHandle;
@property (nonatomic) CGSize measuredSize;
@property (nonatomic, readonly) NSString* displayName;
@property (nonatomic, readonly) BOOL tagged;
@property (nonatomic, weak) id<P2UXActionDelegate> actionHandler;
@property (nonatomic) BOOL primary;
@property (nonatomic, readonly) BOOL requiresSizeUpdate;
@property (nonatomic, readonly) NSArray<UIView*> *overlays;

+ (P2UXView*) viewFromBundleResource:(NSBundle*)bundle name:(NSString*)name frame:(CGRect)frame viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate index:(id)index data:(id)data supportedOrientation:(P2UXOrientationType)supportedOrientation;

- (id)initWithFrame:(CGRect)frame contents:(P2UXDefinition*)contents viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate index:(id) index data:(id)data;

- (void) initializeWithContents:(P2UXDefinition*)contents viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate index:(id)index;
- (void) initializeContents;

- (BOOL) sizeToFitHeight;
- (BOOL) sizeToFitWidth;
- (void) elementCreated:(P2UXElement*)element control:(UIView*)control;
- (void) parseContent;
- (void) parseComplete;
- (void) showView;
- (void) activateView;
- (void) viewClose;
- (void) viewDidClose;
- (void) displayLoaded;
- (void) setInitialized;
- (void) clearConstraints;

- (void) updateContents;

- (id)   attributeWithName:(NSString*)name;
- (BOOL) setAttribute:(id)attrib withName:(NSString*)name relative:(BOOL)relative animated:(id)animated itemspec:(NSDictionary *)itemspec;
- (void) setValue:(NSInteger)value forElementWithType:(NSString*)type;
- (void) setValue:(NSInteger)value forElement:(P2UXElement*)element;
- (void) setValueWithString:(NSString*)value forElement:(P2UXElement*)element;
- (void) setValueWithString:(NSString*)value forElementWithType:(NSString*)type;
- (void) setDefaultFrame:(CGRect) rect;
- (void) handleLoadEvents;

#pragma mark - State methods
- (P2UXScreenState*) stateWithName:(NSString*)name;
- (P2UXScreenState*) screenState;

- (UIView*)  controlWithElementType:(NSString*) type;
- (P2UXElementInstance*) elementInstanceWithTag:(NSInteger)tag;
- (UIView*)  viewForElement:(P2UXElement*)element;
- (UIView*) containingViewForElement:(P2UXElement*)element;
- (NSArray*) childContainers;
- (void) loadedView;

- (void) handleNavigate:(BOOL)next;
- (void) handleNavigateClick;
- (void) handleNavigateCtrl:(UIView*)focusCtrl focus:(BOOL)focus next:(BOOL)next;
- (BOOL) handleSwipeLeft;
- (BOOL) handleSwipeRight;
- (void) handleTextInput:(P2UXEventAction*)action element:(P2UXElementInstance*)elem;
- (void) handleIncrement:(P2UXEventAction*)event element:(P2UXElementInstance*)elem;
- (void) handleSwipe:(id)sender direction:(NSString *)direction;
- (BOOL) handleTap:(id)sender element:(P2UXElementInstance*)element events:(NSArray*)events;

- (BOOL) handleEventAction:(P2UXEventAction*)action element:(P2UXElementInstance*)element sender:(id)sender;
- (BOOL) handleGroupAction:(P2UXEventAction*)action element:(P2UXElementInstance*)element sender:(id)sender;
- (BOOL) handleRadioButton:(id)sender element:(P2UXElementInstance*)element;
- (BOOL) handlePostButtonClick:(id)sender element:(P2UXElementInstance*)element;
- (BOOL) handleRadioButtonSelected:(id)sender element:(P2UXElementInstance*)element;
- (BOOL) handleButtonClick:(id)sender element:(P2UXElementInstance*)element;
- (BOOL) handleButtonToggle:(id)sender element:(P2UXElementInstance*)element;
- (BOOL) handleButtonLongPress:(id)sender element:(P2UXElementInstance*)element;
- (BOOL) handleSlideIncrement:(id)sender element:(P2UXElementInstance*)element;
- (BOOL) handleLabelToggle:(id)sender element:(P2UXElementInstance*)element;
- (BOOL) handleOnMessage:(NSNotification*)notification;
- (BOOL) handleKeyboardReturn:(id)sender element:(P2UXElementInstance*)element;
- (BOOL) handleRotaryChange:(id)sender element:(P2UXElementInstance*)element;
- (BOOL) handleRotaryIncrement:(id)sender element:(P2UXElementInstance*)element inc:(BOOL)inc;

- (void) postEventHandler:(P2UXElementInstance*)element actions:(NSArray*)actions;
- (void) setViewState:(NSString *)viewState;
- (void) setViewState:(NSString *)viewState notify:(BOOL)notify;

- (BOOL) selectRadioButton:(P2UXElementInstance*)element radioName:(NSString*)radioName triggerEvents:(BOOL)triggerEvents;

- (void) showElement:(P2UXElement*)element show:(BOOL)show;

- (void) setLabel:(NSString*)label withType:(NSString*)type;
- (void) setButtonLabel:(NSString*)label withType:(NSString*)type;

- (BOOL) renderBackground:(NSDictionary *)background;
- (void) updateBackground;

- (UIView*) createControlFromElement:(P2UXElement*)element controls:(NSDictionary*)controlsMap parent:(UIView*)parent def:(P2UXDefinition*)def;

- (void) handleViewSwipeRight:(UISwipeGestureRecognizer*)recognizer;
- (void) handleViewSwipeLeft:(UISwipeGestureRecognizer*)recognizer;
- (void) handleViewSwipeUp:(UISwipeGestureRecognizer*)recognizer;
- (void) handleViewSwipeDown:(UISwipeGestureRecognizer*)recognizer;
- (void) handleLongPress:(UILongPressGestureRecognizer*)recognizer;
- (void) handleTapGesture:(UITapGestureRecognizer *)recognizer;

- (BOOL) hasWeather;
- (BOOL) hasTimeOrDate;

- (void) handleLanguageChange:(NSNotification*)notification;

- (void) updateTimeDateControls:(NSString*)type;
- (BOOL) handleOnStateChange:(NSString*)layoutName;
- (void) setupEvents;

- (void) handleKeyboardVisible:(BOOL)visible;

#pragma mark - P2UXControl
- (void) cleanup;
- (void) setData:(NSDictionary *)data;

#pragma mark - P2UXActionDelegate
- (BOOL) handleButtonClick:(id)sender;
- (BOOL) handleButtonToggle:(id)sender;
- (BOOL) handleButtonRadio:(id)sender;
- (BOOL) handleButtonRadioState:(id)sender;
- (BOOL) handleButtonLongPress:(id)sender;
- (BOOL) handleSlideIncrement:(id)sender;
- (BOOL) handleLabelToggle:(id)sender;
- (void) handleTextChange:(id)sender;
- (void) handleTextBeginEditing:(id)sender;
- (void) handleTextEndEditing:(id)sender;
- (BOOL) handleKeyboardReturn:(id)sender;
- (BOOL) gestureRecognizerShouldBegin:(UIGestureRecognizer *)recognizer;
- (void) registerPanGesture:(UIPanGestureRecognizer*)gesture direction:(NSInteger)direction;
- (BOOL) handleRotaryChange:(id)sender;
- (BOOL) handleRotaryIncrement:(id)sender;

#pragma mark - P2UXPanEventHandlerDelegate
- (void) panComplete:(BOOL)cancelled;

#pragma mark - P2UXData
- (id) valueForAttribute:(NSString *)attribute;

#pragma mark - Orientation
- (void) setOrientation:(P2UXOrientationType)orientationType size:(CGSize)size;
@end
