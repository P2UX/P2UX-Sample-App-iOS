//
//  P2UXDataSourceFilter.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 4/21/17.
//  Copyright © 2017 P2UX, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <P2UXCore/P2UXDataSchema.h>

@protocol P2UXDataSourceFilter <NSObject>
- (NSString*) type;
- (P2UXSchemaType) dataType;
- (id) filterData:(id)data usingfilter:(NSDictionary*)filter itemSchema:(P2UXDataSchema*)itemSchema;
@end
