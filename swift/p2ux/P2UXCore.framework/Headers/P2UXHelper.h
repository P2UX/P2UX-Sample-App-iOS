//
//  P2UXHelper.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 11/15/12.
//
//

#import <Foundation/Foundation.h>
#import <P2UXCore/P2UXElement.h>
#import <P2UXCore/P2UXActionDelegate.h>
#import <P2UXCore/P2UXDefinition.h>
#import <P2UXCore/P2UXData.h>
#import <P2UXCore/P2UXViewContainerDelegate.h>
#import <P2UXCore/P2UXHelperDelegate.h>

extern NSString* const CreateViewKey_MeasuredSize;
extern NSString* const CreateViewKey_BottomMostCtrl;
extern NSString* const CreateViewKey_RightMostCtrl;
extern NSString* const CreateViewKey_FocusChain;
extern NSString* const CreateViewKey_LinkCtrls;
extern NSString* const CreateViewKey_RequiresSizeUpdate;

@class P2UXView, SVGKImage, P2UXScreenStateDefinition, P2UXScreenState;
@interface P2UXHelper : NSObject
+(P2UXOrientationType) currentOrientation;
+(UIView*) createControlFromElement:(P2UXElement*)element controls:(NSDictionary*)controls parentSize:(CGRect)parentSize path:(NSString*)path ext:(BOOL)ext handler:(id<P2UXActionDelegate>)handler def:(P2UXScreenStateDefinition*)def viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate index:(id)index data:(id)data parent:(OSViewClass*)parent;
+(UIView*) createControlFromElement:(P2UXElement*)element controls:(NSDictionary*)controls parentSize:(CGRect)parentSize path:(NSString*)path ext:(BOOL)ext handler:(id<P2UXActionDelegate>)handler def:(P2UXScreenStateDefinition*)def viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate index:(id)index data:(id)data parent:(OSViewClass*)parent layout:(NSString*)layoutType;
+(CGRect) controlRectFromElementInstance:(P2UXElementInstance*)elemInst controls:(NSDictionary*)controls parentSize:(CGRect)parentSize scale:(CGFloat)scale;
+(CGRect) controlRectFromElementInstance:(P2UXElementInstance*)elemInst controls:(NSDictionary*)controls parentSize:(CGRect)parentSize layout:(NSString*)layoutType scale:(CGFloat)scale;
+(CGSize) sizeFromSpec:(NSDictionary*)spec parent:(CGSize)parentSize scale:(CGFloat)scale;
+ (CGSize) controlSize:(NSDictionary*)size parentSize:(CGSize)parentSize scale:(CGFloat)scale;

+ (CGPoint) pointFromSpec:(NSDictionary*)spec controls:(NSDictionary*)controls parentSize:(CGRect)parentSize size:(CGSize)size scale:(CGFloat)scale;
+ (CGPoint) pointFromSpec:(NSDictionary*)spec controls:(NSDictionary*)controls parentSize:(CGRect)parentSize size:(CGSize)size layout:(NSString *)layoutType scale:(CGFloat)scale;

+ (CGRect) rectFromSpec:(NSDictionary*)spec parent:(CGRect)parent scale:(CGFloat)scale;
+ (CGRect) rectFromPos:(NSDictionary*)pos size:(NSDictionary*)size parent:(CGRect)parent scale:(CGFloat)scale;

+ (CGSize) currentSize;
//+ (CGSize) sizeInOrientation:(UIInterfaceOrientation)orientation;

+ (UIImage*) imageForRef:(NSString*)ref path:(NSString*)path external:(BOOL)external;
+ (UIImage*) imageForRef:(NSString*)ref path:(NSString*)path external:(BOOL)external size:(CGSize)size colorize:(id)colorize viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;

+ (UIImage*) imageForRef:(NSString*)ref path:(NSString*)path external:(BOOL)external type:(NSInteger)type state:(NSInteger)state;
+ (UIImage*) imageForRef:(NSString*)ref path:(NSString*)path external:(BOOL)external type:(NSInteger)type state:(NSInteger)state size:(CGSize)size colorize:(id)colorize viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;
+ (NSString*) pathForRef:(NSString*)ref path:(NSString*)path external:(BOOL)external;
+ (void) drawLinearGradient:(CGContextRef) context rect:(CGRect) rect startColor:(CGColorRef) startColor endColor:(CGColorRef)endColor;
+ (float) valueFromSpec:(NSDictionary*)spec parent:(float)parent scale:(CGFloat)scale;;
+ (float) valueFromMixedSpec:(id)spec parent:(float)parent scale:(CGFloat)scale;;

+(NSString*) formatDateTime:(NSDate*)date itemspec:(NSDictionary*)itemspec def:(NSString*)defFormat;
+ (NSString*) formatRelativeTime:(NSDate*)date;

+ (P2UXView*) parentViewForElementView:(UIView*)viewElement;

+ (id) valueFromSpec:(NSDictionary*)spec source:(id<P2UXData>)source;
+ (id) cornersFromSpec:(id)spec parent:(float)parent;
+ (NSDictionary*) parseGradientFromSpec:(id)spec clockwise:(BOOL)clockwise viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;
+ (void) parseGradientColors:(NSArray*)spec colors:(NSMutableArray*)colors locations:(NSMutableArray*)locations clockwise:(BOOL)clockwise;
+ (NSDictionary*) buildViewWithParent:(UIView *)parent constraintParent:(UIView*)constraintParent controls:(NSArray *)controls def:(P2UXScreenStateDefinition*)def orientation:(P2UXOrientationType)orientationType handler:(id<P2UXActionDelegate>)handler viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate index:(id)index data:(id)data useConstraints:(BOOL)useConstraints delegate:(id<P2UXHelperViewCreatorDelegate>)delegate;
+ (void) applyShadow:(NSDictionary*)shadow toLayer:(CALayer*)layer parent:(UIView*)parent path:(CGPathRef)path viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;
+ (NSArray*) constraintsFromPos:(NSDictionary*)pos size:(NSDictionary*)size view:(UIView*)view parent:(UIView*)parent;
+ (NSArray*) constraintsFromPos:(NSDictionary*)pos state:(P2UXScreenState*)state view:(UIView*)view parent:(UIView*)parent;
+ (NSShadow*) shadowFromSpec:(NSDictionary*)spec size:(CGSize)size viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;
+ (NSDictionary*) reverseGradientColors:(NSDictionary*)gradient;

@end
