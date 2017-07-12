//
//  P2UXRotaryButton.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 11/13/12.
//
//

#import <P2UXCore/P2UXMHRotaryKnob.h>
#import <P2UXCore/P2UXControl.h>
#import <P2UXCore/P2UXVarLink.h>
#import <P2UXCore/P2UXActionDelegate.h>

@class P2UXElement, P2UXElementInstance, P2UXDisplayLayout;

@interface P2UXRotaryButton :P2UXMHRotaryKnob<P2UXControl>
{
    id<P2UXActionDelegate>        _handler;    
}

-(id) initWithFrame:(CGRect)frame elemInst:(P2UXElementInstance*)elemInst uipath:(NSString*)path ext:(BOOL)ext handler:(id<P2UXActionDelegate>)handler viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate  index:(id) index;
-(void) updateFromState;
@end
