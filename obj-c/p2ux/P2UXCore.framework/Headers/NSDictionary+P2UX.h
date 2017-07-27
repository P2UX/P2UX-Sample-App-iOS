//
//  NSDictionary+P2UX.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 3/26/13.
//  Copyright (c) 2014 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDictionary (P2UX)
- (NSMutableDictionary*) deepMutableCopy;
- (NSDictionary*) deepCopy;
- (NSString*) localizedValueForKey:(NSString*)key;
- (NSString*) localizedValue;
- (id) valueWithRef:(NSString*)ref;
- (id) objectForKeyValid:(const NSString*)key;
- (BOOL) boolValueForKey:(NSString*)key defaultValue:(BOOL)defaultValue;
- (float) floatValueForKey:(NSString*)key defaultValue:(float)defaultValue;
- (NSInteger) integerValueForKey:(NSString*)key defaultValue:(NSInteger)defaultValue;
- (id) objectForPath:(const NSString*)path;
- (BOOL) objectForKeyRemovable:(const NSString*)key obj:(id*)obj;
@end
