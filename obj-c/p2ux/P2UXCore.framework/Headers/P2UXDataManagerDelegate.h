//
//  P2UXDataManagerDelegate.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 10/26/15.
//  Copyright © 2015 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol P2UXDataManagerDelegate <NSObject>
@optional
- (void) postDataSourceFetch:(NSString*)ident request:(NSString*)request args:(NSDictionary*)args data:(P2UXSourcedData*)data cached:(BOOL)cached;
- (void) postVarFetch:(NSString*)ident var:(NSString*)var value:(id)value;
@end
