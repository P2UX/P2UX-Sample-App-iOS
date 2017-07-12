//
//  P2UXBtnGrpElement.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 10/2/13.
//  Copyright (c) 2013 Phase 2 Industries, LLC. All rights reserved.
//

#import "P2UXElement.h"

@class P2UXGroupElement;

@interface P2UXBtnGrpElement : P2UXElement
{
    P2UXGroupElement* _group;
}
@property (nonatomic, readonly) P2UXGroupElement* group;
@end
