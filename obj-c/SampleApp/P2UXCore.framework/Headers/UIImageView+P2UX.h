//
//  UIImageView+P2UX.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 10/22/13.
//  Copyright (c) 2013 Phase 2 Industries, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <P2UXCore/P2UXTypes.h>
@interface UIImageView (P2UX)
- (void) cleanup;
- (void) setScaleType:(P2UXScaleType)scaleType;
@end
