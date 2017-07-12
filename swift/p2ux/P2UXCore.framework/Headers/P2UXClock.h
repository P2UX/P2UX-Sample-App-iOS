//
//  P2UXClock.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 5/24/13.
//  Copyright (c) 2013 Phase 2 Industries, LLC. All rights reserved.
//

#import <P2UXCore/P2UXElement.h>
#import <P2UXCore/P2UXControl.h>
@class P2UXElementInstance;

@interface P2UXClock : UIControl<P2UXControl>
{
    P2UXElement*                  _element;
}
- (id) initWithFrame:(CGRect)frame elemInst:(P2UXElementInstance*)elemInst uipath:(NSString*)path ext:(BOOL)ext;
;
-(void) updateFromState;
-(void) updateClock;

#pragma mark - P2UXControl
- (void) setData:(NSDictionary *)data;
- (void) cleanup;
- (void) refreshControl;
@end
