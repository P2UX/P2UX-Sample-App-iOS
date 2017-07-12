//
//  P2UXControl.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 6/4/13.
//  Copyright (c) 2013 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
@class P2UXElementInstance;

@protocol P2UXControl <NSObject>
- (void) cleanup;
- (void) setData:(NSDictionary*)data;
- (P2UXElementInstance*) elemInstance;
- (id) valueForAttribute:(NSString*)attribute;
@optional
- (void) refreshControl;
- (void) updateContents;
- (void) initializeConstraints:(UIView*)constraintParent;
@end
