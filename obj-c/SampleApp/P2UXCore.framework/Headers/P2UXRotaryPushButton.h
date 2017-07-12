//
//  P2UXRotaryPushButton.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 1/7/13.
//  Copyright (c) 2013 Phase 2 Industries, LLC. All rights reserved.
//

#import <P2UXCore/P2UXRotaryButton.h>

@interface P2UXRotaryPushButton : P2UXRotaryButton

-(id) initWithFrame:(CGRect)frame elemInst:(P2UXElementInstance*)elemInst uipath:(NSString*)path ext:(BOOL)ext handler:(id<P2UXActionDelegate>)handler viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate index:(id)index;

- (void) handleButtonClick:(id)sender;
- (void) handleButtonToggle:(id)sender;
@end
