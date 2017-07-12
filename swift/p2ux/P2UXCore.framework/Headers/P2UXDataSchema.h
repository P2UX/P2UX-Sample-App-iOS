//
//  P2UXDataParams.h
//  P2UXCore
//
//  Created by Steve Ansell on 1/6/15.
//  Copyright (c) 2015 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
@class P2UXDataSourceFilterRequest;

typedef NS_ENUM(NSInteger, P2UXSchemaType) {
    P2UXSchemaType_Unknown,
    P2UXSchemaType_Object,
    P2UXSchemaType_Array,
    P2UXSchemaType_String,
    P2UXSchemaType_Number,
    P2UXSchemaType_Boolean,
    P2UXSchemaType_Date,
    P2UXSchemaType_ArrayOrObject
};

extern NSString* const P2UXSchemaKey_Type;
extern NSString* const P2UXSchemaKey_Item;
extern NSString* const P2UXSchemaKey_Error;
extern NSString* const P2UXSchemaKey_Message;
extern NSString* const P2UXSchemaKey_Detail;
extern NSString* const P2UXSchemaKey_Total;
extern NSString* const P2UXSchemaKey_Current;
extern NSString* const P2UXSchemaKey_Unit;

@interface P2UXDataSchema : NSObject

@property (readonly)P2UXSchemaType type;
@property (readonly)NSDictionary* spec;
@property (retain, readwrite)id success;
@property (retain, readwrite)id failure;
@property (readonly)BOOL validationPending;
@property (readonly)BOOL failureIndicated;
@property (nonatomic, weak) P2UXDataSourceFilterRequest* filterValue;

+(P2UXSchemaType)stringToType:(NSString*)typeName;
+(P2UXDataSchema*)updateSchema;
+(P2UXDataSchema*)errorSchema;

-(id)initWithSpec:(NSDictionary*)schemaSpec;
-(NSArray*)keys;
-(NSDictionary*)requiredItems;
-(NSString*)aliasForKey:(NSString*)key;
-(P2UXDataSchema*)schemaForKey:(NSString*)key;
-(P2UXDataSchema*)itemSchema;
-(NSString*)itemIndex;
-(BOOL)validateData:(id)dataValue atContext:(NSString*)context;
-(id)filterType:(id)value atContext:(NSString*)context;
-(id)filterValue:(id)value atContext:(NSString*)context;

// Protected
-(P2UXDataSchema*)createSchemaWithSpec:(NSDictionary*)spec;

@end
