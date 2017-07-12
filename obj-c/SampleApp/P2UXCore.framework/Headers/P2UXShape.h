//
//  P2UXShape.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 12/12/14.
//  Copyright (c) 2014 Phase 2 Industries, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <P2UXCore/P2UXControl.h>
#import <P2UXCore/P2UXVarLinks.h>

@class P2UXElement, P2UXElementInstance;

extern NSString* const Shape_Attrib_FillColor;
extern NSString* const Shape_Attrib_BorderColor;

typedef NS_ENUM(NSInteger, ImageURLCachePolicy) {
    ImageURLCachePolicy_None = 0,
    ImageURLCachePolicy_Memory,
    ImageURLCachePolicy_Disk
};

typedef NS_ENUM(NSInteger, BorderEndCap) {
    BorderEndCap_None = 0,
    BorderEndCap_Square,
    BorderEndCap_Round
};

typedef NS_ENUM(NSInteger, BorderLineJoin) {
    BorderLineJoin_Miter = 0,
    BorderLineJoin_Bevel,
    BorderLineJoin_Round
};

@interface P2UXShape : UIView
{
    UIBezierPath*               _shapePath;
    UIBezierPath*               _borderPath;
    CGFloat                     _shapeOffset;
    
    NSString*                   _type;
    NSString*                   _img;
    
    NSInteger                   _fillType;
    UIColor*                    _fillColor;
    CGBlendMode                 _fillBlendMode;
    NSArray*                    _corners;
    
    UIColor*                    _borderColor;
    CGFloat                     _borderWidth;
    P2UXScaleType               _scale;
}
- (void) cleanup;

- (id) initWithFrame:(CGRect)frame elemInst:(P2UXElementInstance*)elemInst uipath:(NSString*)path ext:(BOOL)ext viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate index:(id)index;
- (id) initWithFrame:(CGRect)frame spec:(NSDictionary*)spec path:(NSString*)path ext:(BOOL)ext viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;
- (void) refreshControl;
- (void) updatePaths;
- (void) drawInContext:(CGContextRef)context rect:(CGRect)rect;
- (BOOL) canBeRendered;
- (void) setImage:(UIImage*)image;
@end
