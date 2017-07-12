//
//  P2UXRestDataSource.h
//  P2UXCore
//
//  Created by Steve Ansell on 6/13/14.
//  Copyright (c) 2014 Phase 2 Industries, LLC. All rights reserved.
//

#import "P2UXDataSourceSubclass.h"

@interface P2UXRestDownloadHandler : NSObject  <NSURLSessionDownloadDelegate>
-(id) initWithRequest:(NSString*)request
           serialized:(NSString*)reqWithArgs
             ofFormat:(NSString*)format
           andContent:(NSDictionary*)content
              onTasks:(NSMutableDictionary*)currTasks
         thenCallback:(P2UXCallbackResponse)callback;
@end

@interface P2UXRestDataSource : P2UXDataSource

@property (readonly) NSURL* baseURL;
@property (readonly) BOOL authRequired;
@property (readwrite) BOOL pushResponse;

-(BOOL) makeRequest:(NSString*)request
              async:(BOOL)async
           withArgs:(NSDictionary*)args
          keepAlive:(BOOL)keepAlive
        andDelegate:(id<P2UXDataSourceDelegate>)delegate;
-(void) request:(NSString*)request responsePushed:(id)response;

@end
