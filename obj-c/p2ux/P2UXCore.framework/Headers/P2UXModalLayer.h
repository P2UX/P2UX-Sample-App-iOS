//
//  P2UXModalLayer.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 11/25/13.
//  Copyright (c) 2013 Phase 2 Industries, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@class P2UXModalLayer;

@protocol P2UXModalLayerDelegate <NSObject>
- (void) layerTap:(P2UXModalLayer*)layer;
@end

@interface P2UXModalLayer : UIView
@property (nonatomic, weak) id<P2UXModalLayerDelegate> delegate;
- (void) removeFromSuperview;
@end
