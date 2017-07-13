//
//  P2UXReorderGestureRecognizer.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 3/25/15.
//  Copyright (c) 2015 Phase 2 Industries, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface P2UXReorderGestureRecognizer : UIPanGestureRecognizer
@property (nonatomic) UIView* viewToMove;
@end
