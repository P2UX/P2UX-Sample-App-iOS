//
//  P2UXUser.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 7/29/13.
//  Copyright (c) 2014 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <P2UXCore/P2UXCachedData.h>

@interface P2UXUser : P2UXCachedData

@property (nonatomic, readonly) NSString* name;
- (id) initWithName:(NSString*)username;
@end
