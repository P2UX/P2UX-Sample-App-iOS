//
//  P2UXDataBatchRequest.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 4/29/15.
//  Copyright (c) 2015 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <P2UXCore/P2UXTypes.h>

@class P2UXSourcedData, P2UXEvent;

@interface P2UXDataBatchRequest : NSObject
{
}
@property (nonatomic, copy) NSString* sourceDir;
@property (nonatomic, readonly) NSString* mode;
@property (nonatomic, readonly) NSString* type;
@property (nonatomic, readonly) NSString* ident;
@property (nonatomic, readonly) NSArray* sources;
@property (nonatomic, readonly) P2UXRequestState state;
@property (nonatomic, readonly) BOOL success;
@property (nonatomic, readonly) BOOL active;
@property (nonatomic) BOOL subBatch;
@property (nonatomic) P2UXSourcedData* data;
@property (nonatomic, weak) id<P2UXViewContainerDelegate> viewDelegate;

+ (P2UXDataBatchRequest*) requestWithIdent:(NSString*)ident andSources:(NSArray*)sources sourceDir:(NSString*)sourceDir;
+ (P2UXDataBatchRequest*) requestWithIdent:(NSString*)ident andSpec:(NSDictionary*)spec sourceDir:(NSString*)sourceDir;
+ (void) clearBatchResults:(NSString*)ident;
- (void) cleanup;
- (void) fetch;
- (void) updateArgsFromEvent:(P2UXEvent*)event sender:(id)sender viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;
- (void) updateSources:(NSArray*)sources;
- (BOOL) handleDataSourceRequestComplete:(NSString*)ident request:(NSString*)request success:(BOOL)success;
@end
