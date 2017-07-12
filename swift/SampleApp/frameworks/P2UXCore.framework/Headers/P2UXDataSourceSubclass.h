//
//  P2UXDataSourceSubclass.h
//  P2UXCore
//
//  Created by Steve Ansell on 6/17/14.
//  Copyright (c) 2014 Phase 2 Industries, LLC. All rights reserved.
//

#import "P2UXDataSource.h"
#import "NSData+P2UX.h"

typedef void (^P2UXCallbackResponse)(P2UXDataRequestResult result, id response);

@interface P2UXDataSource()

-(void) handleRequest:(NSString*)name
           withObject:(NSDictionary*)requestObj
                 args:(NSDictionary*)args
          andCallback:(P2UXCallbackResponse)callback;

-(BOOL) partialResults:(P2UXSourcedData*)results
            forRequest:(NSString*)request
            withObject:(NSDictionary*)requestObj
                schema:(NSDictionary*)schemaSpec
               andArgs:(NSDictionary*)args
             persistIt:(BOOL)persist
           forValidity:(NSTimeInterval)validSecs
       thenCallDelgate:(id<P2UXDataSourceDelegate>)delegate
             andRepeat:(NSTimeInterval)refresh;

-(void) dispatchTimedRequest:(NSTimer*)timer;
-(BOOL) clearDataForRequest:(NSString*)reqWithArgs;
-(BOOL) clearAllData;
-(P2UXSourcedData*)persistedDataForRequest:(NSString*)request storedAt:(NSString*)itemId;

-(void) dispatch:(NSString*)request
           async:(BOOL)async
      withObject:(NSDictionary*)requestObj
          schema:(NSDictionary*)schemaSpec
         andArgs:(NSDictionary*)args
       keepAlive:(BOOL)keepAlive
       persistIt:(BOOL)persist
     forValidity:(NSTimeInterval)validSecs
 thenCallDelgate:(id<P2UXDataSourceDelegate>)delegate
       andRepeat:(NSTimeInterval)refresh;

-(void) dispatchRequest:(NSString*)request
             withObject:(NSDictionary*)requestObj
                 schema:(NSDictionary*)schemaSpec
                andArgs:(NSDictionary*)args
              keepAlive:(BOOL)keepAlive
              persistIt:(BOOL)persist
            forValidity:(NSTimeInterval)validSecs
        thenCallDelgate:(id<P2UXDataSourceDelegate>)delegate
              andRepeat:(NSTimeInterval)refresh;
@end
