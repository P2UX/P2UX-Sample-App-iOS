//
//  P2UXDirectionPanGestureRecognizer.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 9/5/14.
//  Copyright (c) 2014 Phase 2 Industries, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <UIKit/UIGestureRecognizerSubclass.h>

typedef NS_ENUM(NSInteger, DirectionPangestureRecognizerDirection) {
    P2UXDirectionPanGestureRecognizerVertical,
    P2UXDirectionPanGestureRecognizerHorizontal
} ;

@interface P2UXDirectionPanGestureRecognizer : UIPanGestureRecognizer {
    BOOL _drag;
    int _moveX;
    int _moveY;
    DirectionPangestureRecognizerDirection _direction;
}

@property (nonatomic, assign) DirectionPangestureRecognizerDirection direction;
@end
