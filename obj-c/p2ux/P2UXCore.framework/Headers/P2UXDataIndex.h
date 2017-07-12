//
//  P2UXDataIndex.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 1/22/15.
//  Copyright (c) 2015 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@class P2UXVarLink;

@interface P2UXDataIndex : NSObject
@property (nonatomic, readonly) NSString* ident;
@property (nonatomic, readonly) NSString* request;
@property (nonatomic, readonly) NSString* context;
@property (nonatomic) id index;
@property (nonatomic) id value;
@property (nonatomic) P2UXVarLink* valueLink;

- (void) cleanup;

- (id) initWithIdent:(NSString*)ident request:(NSString*)request context:(NSString*)context;
- (BOOL) matchesLink:(P2UXVarLink*)link;
- (BOOL) setIndexValue:(id)value;
- (void) setValueLink:(P2UXVarLink*)link context:(id)context viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;
- (void) updateLinkedValue:(id) context viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;
- (void) updateIndexValue:(id)value;
@end
