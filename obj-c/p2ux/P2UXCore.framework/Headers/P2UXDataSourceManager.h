//
//  P2UXDataSourceManager.h
//  P2UXCore
//
//  Created by Steve Ansell on 6/17/14.
//  Copyright (c) 2014 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <P2UXCore/P2UXDataSource.h>
#import <P2UXCore/P2UXDataSourceFilter.h>

@class P2UXBehavior;

extern NSString* const P2UXDataSourceType_Static;
extern NSString* const P2UXDataSourceType_Local;
extern NSString* const P2UXDataSourceType_Rest;

@interface P2UXDataSourceManager : NSObject
+ (instancetype) instance;
- (P2UXDataSource*)dataSourceFromSpec:(NSDictionary*)dataSourceSpec sourceDir:(NSString*)sourceDir forProvider:(id)provider behavior:(P2UXBehavior*)behavior;
- (P2UXDataSource*)dataSourceWithIdOrType:(NSString*)sourceType;
- (void) mapType:(NSString*)inType toType:(NSString*)outType;
- (void) unMapType:(NSString*)type;
- (void) clearDataSources;
- (void) removeAllSourcesForProvider:(id)provider;
- (NSString*) mapTypeForType:(NSString*)type;
- (BOOL) addFilter:(id<P2UXDataSourceFilter>)filter;
- (id<P2UXDataSourceFilter>) filterForType:(P2UXSchemaType)type name:(NSString*)name;
@end
