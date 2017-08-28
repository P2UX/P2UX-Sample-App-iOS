//
//  P2UXPanel
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 12/6/12.
//  Copyright (c) 2014 Phase 2 Industries, LLC. All rights reserved.
//

#import "P2UXView.h"
#import "P2UXBaseCtrl.h"

typedef enum {
    PanelShow_Normal = -1,
    PanelShow_Overlay,
    PanelShow_Dialog
} PanelShow;

@protocol P2UXPanelDelegate <NSObject>
- (void) viewDidClose:(id)view;
@end

@interface P2UXPanel : P2UXView
{
}
@property (nonatomic) id<P2UXPanelDelegate> delegate;
@property (nonatomic) BOOL autoCleanup;
@property (nonatomic) PanelShow showMode;
@property (nonatomic) P2UXEventTransition* transition;
@property (nonatomic) NSArray* constraints;
@property (nonatomic, readonly) NSInteger overlayReferences;

- (id)initWithFrame:(CGRect)frame contents:(P2UXDefinition*)contents viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;
- (id)initWithFrame:(CGRect)frame contents:(P2UXDefinition*)contents viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate index:(id)index data:(id)data;

- (void) decrementOverlayReference;
- (void) addOverlayReference;
- (void) clearOverlayReferences;

- (void) displayWithTimeout:(NSTimeInterval)timeout parent:(UIView*)parent;
- (void) displayWithParent:(UIView*)parent;
- (void) displayWithParent:(UIView*)parent fade:(BOOL)fade;
- (void) displayWithParent:(UIView*)parent top:(UIView*)top fade:(BOOL)fade;
- (void) displayAsOverlay:(UIView*)parent state:(P2UXScreenState*)state;
- (void) close;
- (void) closeNow;
- (void) setTimeout:(NSTimeInterval)timeout;

- (BOOL) boolAttributeWithType:(NSString*)type defValue:(BOOL)defValue;
- (void) closePopup;

- (void) resetTimeout;
- (void) restoreDefaultFrame;
- (BOOL) hasTimeout;
- (void) cancelTimeout;
- (void) overlayShown;

- (void) activateConstraints;
- (void) deactivateConstraints;
- (void) addElementInstance:(P2UXElementInstance*)inst screen:(NSString*)screenIdent;
- (void) restoreElementInstance:(NSString*)screenIdent reapply:(BOOL)reapply;
@end
