//
//  P2UXHelperDelegate.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 9/11/15.
//  Copyright (c) 2015 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol P2UXHelperDelegate <NSObject>
- (UIView*) createControlWithType:(NSString*)type elementInstance:(P2UXElementInstance*)elementInstance frame:(CGRect)frame viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate index:(id)index data:(id)data parent:(UIView*)parent;

@end

@protocol P2UXHelperViewCreatorDelegate <NSObject>
- (UIView*) createControlFromElement:(P2UXElement*)element controls:(NSDictionary*)controlsMap parent:(UIView*)parent def:(P2UXDefinition*)def;
- (void) elementCreated:(P2UXElement*)element control:(UIView*)control;
@end
