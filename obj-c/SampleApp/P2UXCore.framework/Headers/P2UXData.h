//
//  P2UXData.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 1/21/15.
//  Copyright (c) 2015 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol P2UXData <NSObject>
- (id) valueForAttribute:(NSString*)attribute;
- (void) setValue:(id)value forAttribute:(NSString*)attribute;
@end
