//
//  P2UXVarDelegate.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 8/9/15.
//  Copyright © 2015 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol P2UXVarDelegate <NSObject>

- (id)   varForKey:(NSString*)key ident:(NSString*)ident withType:(NSInteger)type;
- (BOOL) setVarValue:(id)value forKey:(NSString*)key usingIdent:(NSString *)ident withType:(NSInteger)type notify:(BOOL)notify itemspec:(NSDictionary*)itemspec;
- (BOOL) setAppState:(NSString*)appState usingIdent:(NSString*) ident;
- (NSString*) appStateForIdent:(NSString*)ident;
@end
