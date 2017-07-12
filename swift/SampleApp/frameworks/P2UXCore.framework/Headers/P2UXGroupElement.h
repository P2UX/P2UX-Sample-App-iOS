//
//  P2UXGroupElement.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 10/2/13.
//  Copyright (c) 2013 Phase 2 Industries, LLC. All rights reserved.
//

#import "P2UXElement.h"

@interface P2UXGroupElement : P2UXElement
{
    NSArray* _groupElements;
}
@property (nonatomic, readonly) NSArray* groupElements;

@end
