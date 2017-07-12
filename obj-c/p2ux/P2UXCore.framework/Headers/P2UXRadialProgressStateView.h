//
//  P2UXRadialProgressStateView.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 2/23/15.
//  Copyright (c) 2015 Phase 2 Industries, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
@class P2UXShape;
@class P2UXRadialProgressStateView;
@protocol P2UXRadialProgressStateViewDelegate <NSObject>
- (void) stateComplete:(P2UXRadialProgressStateView*)view;
@end

@interface P2UXRadialProgressStateView : UIView
{
    P2UXShape*        _shape;
    UIImageView*    _imageView;
    CGFloat         _showTime;
    CGFloat         _hideTime;
    CGFloat         _visibleTime;
    NSString*       _imagePath;
    NSString*       _path;
}
@property (nonatomic, weak) id<P2UXRadialProgressStateViewDelegate>delegate;
- (id) initWithFrame:(CGRect)frame spec:(NSDictionary*)spec path:(NSString *)path ext:(BOOL)ext viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;
- (void) cleanup;
- (void) show:(BOOL)show;

@end
