//
//  P2UXContainerElement.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 11/20/13.
//  Copyright (c) 2013 Phase 2 Industries, LLC. All rights reserved.
//

#import "P2UXGroupElement.h"
@class P2UXScrollContainerStateDefinition;
@interface P2UXContainerElement : P2UXElement
{
    P2UXElement*          _defaultLabel;
    NSInteger           _dataSource;
    NSInteger           _dataType;
}
@property (nonatomic, readonly) NSInteger dataSource;
@property (nonatomic, readonly) NSInteger dataType;
@property (nonatomic, readonly) P2UXElement* defaultLabel;
@property (nonatomic, readonly) P2UXScrollContainerStateDefinition* def;

- (instancetype) initWithDictionary:(NSDictionary *)dict def:(P2UXDefinition*)def;
@end
