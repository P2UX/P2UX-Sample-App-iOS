//
//  SampleBehavior.m
//  SampleApp
//
//  Copyright © 2017 P2UX, Inc. All rights reserved.
//


#import "SampleBehavior.h"
#import "SampleViewController.h"
@import P2UXApp;

@implementation SampleBehavior

/* Listed below are possible behaviors that can be customized for your app.
 Many feature the line:
 
 if ([def.systemType isEqualToString:@"xxxxx"])
 
 The user should replace "xxxxx" with an appropriate name of the item being customized.
 
 Other possible behaviors that can be customized can be found in P2UXAppBehavior.*/

/*!
 @brief Creates a new instance of a screen.
 @discussion This is called from a request to show a screen when a cached version of the screen isn't available. Override this method to return a custom screen instance.
 
 @param def The view definition
 @param rect A rect that defines the size to create the view
 @param index An index value to pass to the view
 @param data Additional data to pass to the view. This data can be used with linking
 @param viewDelegate The current view delegate
 @return A P2UXScreen instance of the view
 */
- (P2UXScreen*) createScreenWithDef:(P2UXDefinition*)def rect:(CGRect)rect index:(id)index data:(id)data viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;
{
    if (def != nil && def.systemType != nil)
    {
        if ([def.systemType isEqualToString:@"xxxxx"])
        {
            //return some screen here, for example:
            //return [[SomeScreen alloc] initWithView:def behavior:self cache:cache index:index data:data viewDelegate:viewDelegate];
        }
    }
    return [super createScreenWithDef:def rect: rect index: index data: data viewDelegate:viewDelegate];
}

/*!
 @brief Creates a view controller for a view
 @discussion This is called from a request to show a view. Override this method to return a custom view controller instance for the supplied view definition.
 
 @param def The view definition
 @param cache Whether or not to cache the view managed by this view controller
 @param index An index value to pass to the view
 @param data Additional data to pass to the view. This data can be used with linking
 @param viewDelegate The current view delegate
 @return A P2UXViewController instance
 */
- (P2UXViewController*) createViewControllerWithDef:(P2UXDefinition*)def cache:(BOOL)cache index:(id)index data:(id)data viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;
{
    if (def != nil && def.systemType != nil)
    {
        if ([def.systemType isEqualToString:@"xxxxx"])
        {
            //return some view controller here, for example:
            return [[SampleViewController alloc] initWithView:def behavior:self cache:cache index:index data:data viewDelegate:viewDelegate];
        }
    }
    return [super createViewControllerWithDef:def cache:cache index:index data:data viewDelegate:viewDelegate];
}

/*!
 @brief Creates a panel controller for a view
 @discussion This is called from a request to show a panel. Override this method to return a custom view controller instance for the supplied panel definition.
 
 @param def The panel definition
 @param cache Whether or not to cache the panel managed by this panel controller
 @param index An index value to pass to the panel
 @param data Additional data to pass to the panel. This data can be used with linking
 @param viewDelegate The current view delegate
 @return A P2UXViewController instance
 */
- (P2UXViewController*) createPanelControllerWithDef:(P2UXDefinition*)def cache:(BOOL)cache index:(id)index data:(id)data viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;
{
    if (def != nil && def.systemType != nil)
    {
        if ([def.systemType isEqualToString:@"xxxxx"])
        {
            //return some panel controller here, for example:
            //return [[SomePanelController alloc] initWithFrame:rect contents:def viewDelegate:viewDelegate index:index data:data];
        }
    }
    return [super createPanelControllerWithDef:def cache:cache index:index data:data viewDelegate:viewDelegate];

}

/*!
 @brief Creates a new instance of a panel.
 @discussion This is called from a request to show a panel when a cached version of the panel isn't available. Override this method to return a custom panel instance.
 
 @param def The panel definition
 @param rect A rect that defines the size to create the panel
 @param index An index value to pass to the panel
 @param data Additional data to pass to the panel. This data can be used with linking
 @param viewDelegate The current view delegate
 @return A P2UXPanel instance of the panel
 */
- (P2UXPanel*) createPanelWithDef:(P2UXDefinition*)def rect:(CGRect)rect index:(id)index data:(id)data viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;
{
    if (def != nil && def.systemType != nil)
    {
        if ([def.systemType isEqualToString:@"xxxxx"])
        {
            //return some panel here, for example:
            //return [[SomePanel alloc] initWithFrame:rect contents:def viewDelegate:viewDelegate index:index data:data];
        }
    }
    return [super createPanelWithDef:def rect:rect index:index data:data viewDelegate:viewDelegate];
}

/*!
 @brief Creates a new control.
 @discussion This is called from a request to create a control. Override this method to return a custom view with the supplied control type.
 
 @param type The control type
 @param elementInstance An instance of an element
 @param frame The frame the control will be within
 @param viewDelegate The current view delegate
 @return A P2UXView instance
 */
- (UIView*) createControlWithType:(NSString *)type elementInstance:(P2UXElementInstance *)elementInstance frame:(CGRect)frame viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate index:(id)index data:(id)data parent:(UIView*)parent
{
    /* if ([type isEqualToString:@"calendarview"])
    {
        Calendar *calendar = [[Calendar alloc] initWithFrame:frame];
        return calendar;
    }*/
    return [super createControlWithType:type elementInstance:elementInstance frame:frame viewDelegate:viewDelegate index:index data:data parent:parent];
}

@end
