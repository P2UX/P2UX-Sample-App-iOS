//
//  GMUXGroupElementInstance.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 7/23/14.
//  Copyright (c) 2014 Phase 2 Industries, LLC. All rights reserved.
//

#import "P2UXElementInstance.h"

@interface P2UXGroupElementInstance : P2UXElementInstance
#ifdef NO_CONSTRAINTS
- (BOOL) changeStateNC:(NSString *)stateName parent:(OSViewClass *)parent;
#else
- (NSArray*) changeState:(NSString *)stateName;
#endif
@end
