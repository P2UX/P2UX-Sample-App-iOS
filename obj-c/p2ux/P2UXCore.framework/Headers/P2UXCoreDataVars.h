//
//  P2UXCoreDataVars.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 5/7/16.
//  Copyright © 2016 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString* const P2UXCoreDataVar_User;
extern NSString* const P2UXCoreDataVar_CurrentView;

@interface P2UXCoreDataVars : NSObject
+ (id) varForKey:(NSString*)key;
@end
