//
//  P2UXScreenNavigation.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 6/8/17.
//  Copyright © 2017 P2UX, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <P2UXCore/P2UXActionDelegate.h>
extern NSString* const P2UXScreenNav_Attrib;
extern NSString* const P2UXScreenNav_Control_Left;
extern NSString* const P2UXScreenNav_Control_Center;
extern NSString* const P2UXScreenNav_Control_Right;

typedef NS_ENUM(NSInteger, P2UXScreenNavClass)
{
    P2UXScreenNavClass_Standard = 0,
    P2UXScreenNavClass_NavBar,
    P2UXScreenNavClass_TabBar
};

@interface P2UXScreenNavigation : NSObject
@property (nonatomic, readonly) P2UXScreenNavClass navClass;
@property (nonatomic, readonly) BOOL hasHeader;
@property (nonatomic, readonly) NSString* title;
@property (nonatomic, readonly) NSDictionary* headerBackground;
@property (nonatomic, readonly) id textColor;
@property (nonatomic, readonly) BOOL hasTitleFont;

- (instancetype) initWithSpec:(NSDictionary*)spec title:(id)title;
- (void) cleanup;
- (OSFontClass*) fontWithParent:(CGFloat)height scale:(CGFloat)scale;
- (NSArray*) headerControlsForType:(NSString*)type withParent:(UIView*)view handler:(id<P2UXActionDelegate>)handler path:(NSString*)path ext:(BOOL)ext viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate index:(id)index;
@end
