//
//  P2UXScreen.h
//  P2UXApp
//
//  Created by Stephen Schalkhauser on 6/3/14.
//  Copyright (c) 2014 Phase 2 Industries, LLC. All rights reserved.
//

#import <P2UXCore/P2UXCore.h>
#import <P2UXApp/P2UXAppDefinition.h>

extern NSString* const StatusBarUpdate_Message;

@class P2UXAppBehavior;
@class P2UXAppDefinition;

@interface P2UXScreen : P2UXView
@property (nonatomic, readonly) P2UXAppBehavior* appBehavior;
@property (nonatomic, readonly) P2UXStatusBar statusBar;
@end
