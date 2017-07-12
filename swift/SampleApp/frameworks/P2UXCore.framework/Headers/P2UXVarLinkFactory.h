//
//  P2UXVarLinkFactory.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 5/23/17.
//  Copyright © 2017 P2UX, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
@class P2UXVarLink;

@interface P2UXVarLinkFactory : NSObject
+ (P2UXVarLink*) linkWithSpec:(NSDictionary*)spec index:(id)index context:(id)context viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;

@end
