#import "SampleBehavior.h"
@import P2UXApp;

@implementation SampleBehavior

/* Listed below are possible behaviors that can be customized for your app.
 Many feature the line:
 
if ([def.systemType isEqualToString:@"xxxxx"])
 
 The user should replace "xxxxx" with an appropriate type name. 
 
 Other possible behaviors that can be customized can be found in P2UXAppBehavior.*/

/*!
 @brief Get an instance of a view from a view definition
 @discussion This will access an instance of a view from the current application. If the view exists in the view cache, it will return the cached instance, otherwise it will call createScreenWithDef to request a new instance of the view.
 
 @param def The view definition
 @param rect A rect that defines the size to create the view
 @param cache Whether or not to cache the view when its created
 @param index An index value to pass to the view
 @param data Additional data to pass to the view. This data can be used with linking
 @param viewDelegate The current view delegate
 @return A P2UXScreen instance of the view
 */
- (P2UXScreen*) viewWithDef:(P2UXDefinition*)def rect:(CGRect)rect cache:(BOOL)cache  index:(id)index data:(id)data viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;
{
    return [super viewWithDef:def rect:rect cache:cache index:index data:data viewDelegate:viewDelegate];
}

/*!
 @brief Creates a new instance of a screen.
 @discussion This is called from a request to show a screen when a cached version of the view isn't available. Override this method to return a custom screen instance.
 
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
            //return [[SomeViewController alloc] initWithView:def behavior:self cache:cache index:index data:data viewDelegate:viewDelegate];
        }
    }
    return [super createViewControllerWithDef:def cache:cache index:index data:data viewDelegate:viewDelegate];
}

/*!
 @brief Creates a panel controller for a view
 @discussion This is called from a request to show a view. Override this method to return a custom view controller instance for the supplied view definition.
 
 @param def The view definition
 @param cache Whether or not to cache the view managed by this view controller
 @param index An index value to pass to the view
 @param data Additional data to pass to the view. This data can be used with linking
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
 @brief Get an instance of a panel from a view definition
 @discussion This will access an instance of a panel from the current application. If the panel exists in the panel cache, it will return the cached instance, otherwise it will call createPanelWithDef to request a new instance of the panel.
 @param def The panel definition
 @param rect A rect that defines the size to create the panel
 @param cache Whether or not to cache the panel when its created
 @param index An index value to pass to the panel
 @param data Additional data to pass to the panel. This data can be used with linking
 @param viewDelegate The current view delegate
 @return A P2UXPanel instance of the panel
 */
- (P2UXPanel*) panelWithDef:(P2UXDefinition*)def rect:(CGRect)rect cache:(BOOL)cache  index:(id)index data:(id)data viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;
{
    return [super panelWithDef:def rect:rect cache:cache index:index data:data viewDelegate:viewDelegate];
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
