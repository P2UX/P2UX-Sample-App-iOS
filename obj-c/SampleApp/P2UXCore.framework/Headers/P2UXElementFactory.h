//
//  P2UXElementFactory.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 10/2/13.
//  Copyright (c) 2013 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
@class P2UXElement, P2UXElementInstance, P2UXDefinition;

@interface P2UXElementFactory : NSObject
+ (P2UXElement*) createElement:(NSDictionary*)spec;
+ (P2UXElement*) createElement:(NSDictionary*)spec def:(P2UXDefinition*)def;
+ (P2UXElementInstance*) createElementInstance:(P2UXElement*)element;
@end
