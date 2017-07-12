//
//  P2UXRadialProgress.h
//  P2UXCore
//
//  Created by Mark Leyfman on 6/30/14.
//  Copyright (c) 2014 Phase 2 Industries, LLC. All rights reserved.
//

#import <P2UXCore/P2UXControl.h>
#import <P2UXCore/P2UXVarLink.h>
#import <P2UXCore/P2UXRadialProgressStateView.h>

@class P2UXElementInstance, P2UXElement, P2UXDisplayLayout, P2UXShape;


typedef NS_ENUM(NSInteger, P2UXRadialProgressType) {
    P2UXRadialProgressType_Determinate = 0,
    P2UXRadialProgressType_Indeterminate
};

typedef NS_ENUM(NSInteger, P2UXRadialProgressFillMode) {
    P2UXRadialProgressFillMode_Clip = 0,
    P2UXRadialProgressFillMode_Fill
};

@interface P2UXRadialProgress : UIControl<P2UXControl, P2UXRadialProgressStateViewDelegate>
{
    CGFloat                     _rate;
    NSString*                   _state;
    P2UXShape*                    _background;
    P2UXRadialProgressStateView*  _stateView;
}
@property (nonatomic) P2UXRadialProgressType type;
@property (nonatomic) P2UXRadialProgressFillMode fillmode;
@property (nonatomic) BOOL active;

- (id)   initWithFrame:(CGRect)frame elemInst:(P2UXElementInstance*)elemInst uipath:(NSString*)path ext:(BOOL)ext viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate index:(id)index;
- (void) updateFromLayout;
- (void) setState:(NSString*)state;

- (void) setValue:(CGFloat)value update:(BOOL)update;

#pragma mark - P2UXControl
- (void) setData:(NSDictionary *)data;
- (void) cleanup;
- (BOOL) setAttribute:(id)value withName:(NSString*)name relative:(BOOL)relative animated:(id)animated itemspec:(NSDictionary*)itemspec;

#pragma mark - P2UXRadialProgressStateViewDelegate
- (void) stateComplete:(P2UXRadialProgressStateView *)view;
@end
