//
//  P2UXDataManager.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 12/15/12.
//  Copyright (c) 2014 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <P2UXCore/P2UXUser.h>
#import <P2UXCore/P2UXSourcedData.h>
#import <P2UXCore/P2UXDataSource.h>
#import <P2UXCore/P2UXDataBatchRequest.h>
#import <P2UXCore/P2UXVarDelegate.h>
#import <P2UXCore/P2UXVarLink.h>
#import <P2UXCore/P2UXDataManagerDelegate.h>
@class P2UXSourcedData, P2UXEvent;

@interface P2UXDataManager : NSObject<P2UXDataAuthDelegate, P2UXDataSourceDelegate>
{
    NSMutableDictionary* _pendingRequests;
    NSMutableDictionary* _batchRequests;
    NSMutableArray*      _varDelegates;
    NSMutableDictionary* _transientVars;
}
@property (nonatomic, weak) id<P2UXDataAuthDelegate> dataAuthenticationHandler;
@property (nonatomic, copy) NSString* sourceDir;
@property (nonatomic, weak) id<P2UXDataManagerDelegate> delegate;

+ (instancetype) instance;
+ (NSString*) generateUUID;
+ (id) valueForPath:(NSString*)path value:(id)value;
+ (id) incrementExisting:(id)existing withValue:(id)withValue itemspec:(NSDictionary*)itemspec;

// P2UXUser Methods
- (P2UXUser*) createUserWithUsername:(NSString*)username;
- (P2UXUser*) userWithUsername:(NSString*)username;

- (NSArray*) fetchList:(NSString*)type;
- (void) deleteList:(NSString*)type;

- (void) addVarDelegate:(id<P2UXVarDelegate>)delegate;
- (void) removeVarDelegate:(id<P2UXVarDelegate>)delegate;

- (id) transientVarForKey:(NSString*)key;
- (void) setTransientVar:(id)value forKey:(NSString*)key notify:(BOOL)notify itemspec:(NSDictionary*)itemspec;
- (void) clearTransientVars;

- (void) setSecureVar:(id)value forKey:(NSString*)key notify:(BOOL)notify action:(P2UXEventAction*)action;


// Data Source Methods
- (BOOL) updateData:(id)data forLink:(P2UXVarLink*)link withIndex:(id)index;
- (P2UXSourcedData*) dataForLink:(P2UXVarLink*)link;
- (id) dataForLink:(P2UXVarLink*)link withIndex:(id)index;
- (id) valueForLink:(P2UXVarLink*)link;
- (id) valueForLink:(P2UXVarLink*)link withIndex:(id)index;
- (id) valueForLink:(P2UXVarLink *)link withIndex:(id)index context:(id)context viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;
- (id) valueForLink:(P2UXVarLink *)link withIndex:(id)index fromData:(P2UXSourcedData*)data;
- (void) setVarValue:(id)value forKey:(NSString*)key usingIdent:(NSString*)ident withType:(NSInteger)type notify:(BOOL)notify;
- (void) setVarValue:(id)value forKey:(NSString*)key usingIdent:(NSString*)ident withType:(NSInteger)type notify:(BOOL)notify itemspec:(NSDictionary*)itemspec;
- (void) setValue:(id)value forLink:(P2UXVarLink *)link withIndex:(id)index;
- (id) varForKey:(NSString*)key usingIdent:(NSString*)ident withType:(NSInteger)type;
- (void) setAppState:(NSString*)appState usingIdent:(NSString *)ident;
- (NSString*) appStateForIdent:(NSString*)ident;

- (P2UXSourcedData*) fetchDataSource:(NSString*)ident request:(NSString*)request withArgs:(NSDictionary*)args policy:(P2UXDataPolicy)policy state:(NSNumber**)state errorData:(BOOL)errorData async:(BOOL)async;
- (P2UXSourcedData*) fetchBatchData:(NSString*)batchid policy:(P2UXDataPolicy)policy;
- (P2UXSourcedData*) fetchBatchDataDirect:(NSString*)batchid policy:(P2UXDataPolicy)policy viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;
- (void) removeFromDataSource:(NSString*)ident request:(NSString*)request withArgs:(NSDictionary*)args async:(BOOL)async;
- (BOOL) pendingRequest:(NSString*)request forIdent:(NSString*)ident;
- (BOOL) saveDataSource:(NSString*)ident request:(NSString*)request withArgs:(NSDictionary*)args notify:(BOOL)notify;
- (BOOL) revertDataSource:(NSString*)ident request:(NSString*)request withArgs:(NSDictionary*)args includePersisted:(BOOL)includePersisted notify:(BOOL)notify;
- (void) addBatchRequest:(NSString*)batchid sources:(NSArray*)sources;
- (void) addBatchRequest:(NSString*)batchid spec:(NSDictionary*)spec;
- (P2UXDataBatchRequest*) batchRequest:(NSString*)batchid;
- (void) clearBatchRequests;
- (id) valueFromSpec:(NSDictionary*)spec event:(P2UXEvent*)event source:(id)source  viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;
- (NSMutableDictionary*) handleArgs:(NSDictionary*)args event:(P2UXEvent*)event source:(id)source viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;
- (void) setFilters:(NSArray*)filters forDataSource:(NSString*)ident request:(NSString*)request itempath:(NSString*)itempath type:(NSString*)type notify:(BOOL)notify;
- (void) clearFilters:(NSString*)ident request:(NSString*)request itempath:(NSString*)itempath notify:(BOOL)notify;

#pragma mark - P2UXDataSourceDelegate
-(void) request:(NSString*)request withArgs:(NSDictionary*)args returnedSuccess:(BOOL)success withResults:(P2UXSourcedData*)results forSource:(P2UXDataSource*)source;
-(id<P2UXDataAuthDelegate>)dataAuthHandler;

#pragma mark - P2UXDataAuthDelegate
-(void) authType:(P2UXAuthType)type forService:(NSString*)service requires:(NSDictionary*)params viaCallback:(P2UXAuthParamResponse)callback;
-(void) authType:(P2UXAuthType)type forService:(NSString*)service returnedResult:(P2UXAuthResult)result onRequest:(NSString*)request fromSource:(id)source;

@end
