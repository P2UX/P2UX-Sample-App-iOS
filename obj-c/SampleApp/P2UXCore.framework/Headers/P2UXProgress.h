//
//  P2UXProgress.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 4/6/15.
//  Copyright (c) 2015 Phase 2 Industries, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@class P2UXShape, P2UXElementInstance, P2UXElement, P2UXDisplayLayout, P2UXVarLinks;

typedef NS_ENUM(NSInteger, ProgressOrientation) {
    ProgressOrientation_Vertical = 0,
    ProgressOrientation_Horizontal
};

typedef NS_ENUM(NSInteger, ProgressFillMode) {
    ProgressFillMode_Clip = 0,
    ProgressFillMode_Fill
};

@interface P2UXProgress : UIView
{
    P2UXDisplayLayout*            _curLayout;
    BOOL                        _thumbVisibility;

    P2UXShape*                    _background;
    P2UXShape*                    _bar;
    P2UXShape*                    _thumb;
    CGFloat                     _maxBarWidth;
    CGFloat                     _maxBarHeight;
    CGFloat                     _thumbOffset;
    BOOL                        _initialized;
    CGRect                      _sliderRect;
    ProgressOrientation         _orientation;
    ProgressFillMode            _fillMode;
}
@property (nonatomic) CGFloat value;
@property (nonatomic) CGFloat maxValue;
@property (nonatomic) CGFloat minValue;

- (id)initWithFrame:(CGRect)frame elemInst:(P2UXElementInstance*)elemInst uipath:(NSString *)path ext:(BOOL)ext viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate index:(id)index;
- (void) layoutControls;
- (void) setValue:(CGFloat)value updateThumb:(BOOL)updateThumb force:(BOOL)force;
@end
