//
//  P2UXSourceData.h
//  P2UXCore
//
//  Created by Steve Ansell on 6/20/14.
//  Copyright (c) 2014 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "P2UXDataSchema.h"

@class P2UXDataSourceFilterRequest;
extern NSString* const P2UXDataSchema_PathSeparator;

@interface P2UXSourcedData : NSObject
{
    id _data;
    id _filtered;
    id _dataContext;
    NSMutableDictionary* _dataCache;
    P2UXDataSchema* _schema;
    P2UXDataSchema* _schemaContext;
    NSMutableDictionary* _schemaCache; 
}
@property (readonly) NSDate* retreivedOn;
@property (nonatomic, copy) NSDate* expires;
@property (readonly) BOOL fromCache;
@property (readonly) BOOL expired;
@property (nonatomic) BOOL postFiltered;
@property (nonatomic) P2UXDataSourceFilterRequest* filterRequest;
+ (NSString*) cachePath:(NSString*)path;

-(id) initWithData:(id)data andSchema:(P2UXDataSchema*)schema cachedOn:(NSDate*)date;
-(id) initWithData:(id)data andSchema:(P2UXDataSchema*)schema;
-(id) copyWithZone:(NSZone*)zone;

-(id) valueForKeyPath:(NSString*)path;
-(P2UXDataSchema*) schemaForKeyPath:(NSString*)path;
-(BOOL) setValue:(id)value forKeyPath:(NSString *)path;

-(NSString*)indexKeyForPath:(NSString*)path;

-(NSUInteger) recordCountForPath:(NSString*)path;

-(P2UXSourcedData*) dataRecordForPath:(NSString*)path
                       andIndexValue:(id)value;

-(NSInteger) recordNumberForPath:(NSString*)path
                  andIndexValue:(id)value;

-(P2UXSourcedData*) dataRecordForPath:(NSString *)path
                     andRecordNumber:(NSUInteger)number;

-(void) filterRecordsForPath:(NSString*)path
                     onField:(NSString*)field
                    byString:(NSString*)string;
-(void) filterRecordsForPath:(NSString*)path
                    usingFilters:(NSArray*)filters;
-(void) clearFilter;

// protected
- (P2UXSourcedData*) createNewRecord:(id)data andSchema:(P2UXDataSchema*)schema;
- (BOOL) recordValue:(id)record forIndexKey:(id)indexKey withSchema:(P2UXDataSchema*)indexSchema matches:(id)value;
- (id) recordValue:(id)record withKey:(NSString*)key;
@end
