//
//  P2UXGeneric.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 6/17/13.
//  Copyright (c) 2013 Phase 2 Industries, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "P2UXElement.h"
#import "P2UXControl.h"

@interface P2UXGeneric : UIControl<P2UXControl>
{
    NSDictionary*               _background;
}

- (id) initWithFrame:(CGRect)frame elemInst:(P2UXElementInstance*)elemInst uipath:(NSString*)path ext:(BOOL)ext;
-(void) updateFromState;

#pragma mark - P2UXControl
- (void) cleanup;
- (void) setData:(NSDictionary *)data;

@end
