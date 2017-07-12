//
//  P2UXCachedData.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 6/24/14.
//  Copyright (c) 2014 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface P2UXCachedData : NSObject
{
    NSString*               _type;
    NSString*               _id;
    NSString*               _filename;
    NSDictionary*           _data;
    BOOL                    _mutable;
    BOOL                    _subfolder;
}
@property (nonatomic, readonly) NSDictionary* rawData;
@property (nonatomic, readonly) BOOL valid;
@property (nonatomic, readonly) NSString* user;
@property (nonatomic, readonly) NSString* dataId;
@property (nonatomic, readonly) NSString* path;

- (id)   initWithId:(NSString*)dataId type:(NSString*)type;
- (id)   initUserBasedWithId:(NSString *)dataId type:(NSString *)type;
- (void) setData:(NSDictionary*)data save:(BOOL)save;
- (void) save;
- (id)   objectForKey:(NSString*)key;
- (id)   localizedValueForKey:(NSString*)key;
- (void) setObject:(id)obj forKey:(id<NSCopying>)aKey;
- (void) removeObjectWithKey:(NSString*)key;
- (BOOL) remove;
- (void) cleanup;
#pragma mark - internal
- (void) parseData;
- (void) setDefaults;
@end
