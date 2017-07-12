//
//  P2UXOAuthDataAuthSubclass.h
//  P2UXCore
//
//  Created by Steve Ansell on 1/28/15.
//  Copyright (c) 2015 Phase 2 Industries, LLC. All rights reserved.
//

#import "P2UXOAuthDataAuth.h"
#import "P2UXFileUtil.h"


@interface P2UXOAuthDataAuth()

-(BOOL)prepareRequest:(NSMutableURLRequest*)request withParams:(NSDictionary*)params andSession:(NSURLSession*)session;
-(NSMutableDictionary*)parseResponseData:(NSData*)data;
-(void)handleResponseError:(NSUInteger) errorCode andMessage:(NSString*) errorMessage;

@end
