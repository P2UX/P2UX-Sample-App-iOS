//
//  UIImage+P2UX.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 4/2/14.
//  Copyright (c) 2014 Phase 2 Industries, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (P2UX)
+ (UIImage*) imageWithColor:(UIColor*)color;
+ (UIImage*) imageWithColor:(UIColor*)color rect:(CGRect)rect;
- (UIImage*)convertToGrayscale;
- (UIImage*)imageByNormalizingOrientation;
@end
