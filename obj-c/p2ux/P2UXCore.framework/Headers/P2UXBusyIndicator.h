//
//  P2UXBusyIndicator.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 6/6/13.
//  Copyright (c) 2013 Phase 2 Industries, LLC. All rights reserved.
//

#import <P2UXCore/P2UXControl.h>
@class P2UXElementInstance, P2UXElement, P2UXDisplayLayout;

@interface P2UXBusyIndicator : UIView<P2UXControl>
{
}

- (id) initWithFrame:(CGRect)frame elemInst:(P2UXElementInstance*)elemInst uipath:(NSString*)path ext:(BOOL)ext;

#pragma mark - P2UXControl
- (void) setData:(NSDictionary *)data;
- (void) cleanup;
@end
