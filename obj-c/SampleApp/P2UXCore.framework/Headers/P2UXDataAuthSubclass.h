//
//  P2UXDataAuthSubclass.h
//  P2UXCore
//
//  Created by Steve Ansell on 1/5/15.
//  Copyright (c) 2015 Phase 2 Industries, LLC. All rights reserved.
//

#import "P2UXDataAuth.h"

@interface P2UXDataAuth()

-(id)initWithAuthSpec:(NSDictionary*)authSpec andURL:(NSURL*)URL;
-(void)handleRequestWithParams:(NSDictionary*)params andCallback:(P2UXAuthCallback)callback;
-(NSDictionary*)paramsForRequest;
-(void)addPendingAuth:(NSDictionary*)pendingItem;
-(BOOL)authIsPending;

@end
