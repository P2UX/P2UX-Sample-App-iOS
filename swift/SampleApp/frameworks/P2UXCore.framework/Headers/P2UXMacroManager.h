//
//  P2UXMacroManager.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 5/7/15.
//  Copyright (c) 2015 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface P2UXMacroManager : NSObject
+ (instancetype) instance;

- (void) reset;

#pragma mark - transitions
- (void) addTransitions:(NSDictionary*)transitions;
- (NSDictionary*)transitionWithName:(NSString*)name;
- (void) addLinkSources:(NSDictionary*)sources;
- (NSDictionary*)linkSourceWithName:(NSString*)name;
@end
