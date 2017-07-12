//
//  P2UXGroup.h
//  P2UXCore
//
//  Created by Phase 2 Industries, LLC on 11/14/12.
//  Copyright (c) 2013 Phase 2 Industries, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <P2UXCore/P2UXActionDelegate.h>
#import <P2UXCore/P2UXDefinition.h>
#import <P2UXCore/P2UXControl.h>
#import <P2UXCore/P2UXViewContainerDelegate.h>

@class P2UXElementInstance, P2UXGroupElement, P2UXDisplayLayout;


@interface P2UXGroup : UIControl<P2UXControl>
{
    __weak P2UXScreenStateDefinition*    _def;
    P2UXGroupElement*             _ctrlDef;
    NSMutableArray*             _controls;
    NSMutableDictionary*        _instMap;
    NSMutableDictionary*        _systemTypeMap;
    NSMutableArray*             _subGroups;
    NSDictionary*               _background;
    
    UISwipeGestureRecognizer*   _swipeLeft;
    UISwipeGestureRecognizer*   _swipeRight;
    UISwipeGestureRecognizer*   _swipeUp;
    UISwipeGestureRecognizer*   _swipeDown;
    UITapGestureRecognizer*     _tapHandler;
    UIPanGestureRecognizer*     _pan;
    __weak id<P2UXActionDelegate> _handler;
    __weak id                   _data;
}
@property (nonatomic, weak) id extraData;
@property (nonatomic) BOOL useConstraints;
@property (nonatomic, readonly) NSArray* controls;
@property (nonatomic, readonly) BOOL hasKeyboardControls;

- (id) initWithFrame:(CGRect)frame elemInst:(P2UXElementInstance*)elemInst uipath:(NSString*)path handler:(id<P2UXActionDelegate>)handler def:(P2UXScreenStateDefinition*)def  viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate index:(id)index data:(id)data;
- (void) updateFromState;

- (void) setData:(NSDictionary *)data;
- (void) cleanup;
- (void) initialize;

@end
