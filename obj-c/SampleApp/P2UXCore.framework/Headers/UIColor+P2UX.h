//
//  UIColor+P2UX.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 11/9/12.
//  Copyright (c) 2014 Phase 2 Industries, LLC. All rights reserved.
//
//

#import <UIKit/UIKit.h>
#import <P2UXCore/P2UXViewContainerDelegate.h>

#define MAKEBYTE(_VALUE_) (int)(_VALUE_ * 0xFF) & 0xFF

@interface UIColor (P2UX)
+ (UIColor *)   colorWithHexString: (NSString *) hexString viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;
+ (CGFloat)     colorComponentFrom: (NSString *) string start: (NSUInteger) start length: (NSUInteger) length;
- (NSString *)  stringValue;
- (NSString *)  hexStringValue;
+ (CGFloat)     alphaFromHexString:(NSString*)hexString;
+ (CGFloat)     alphaFromHexString:(NSString*)hexString defaultValue:(CGFloat)defaultValue;
- (UIColor*)    colorWithTransparency:(CGFloat) alpha;
@end
