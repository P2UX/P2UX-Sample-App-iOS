//
//  P2UXContentItem.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 12/13/12.
//  Copyright (c) 2014 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString* const DownloadFileZip;
extern NSString* const ASSET;
extern NSString* const DOWNLOAD_DIR;

@interface P2UXContentItem : NSObject
{
    BOOL    _appendDownloadPath;
}
@property (nonatomic) NSString* name;
@property (nonatomic) NSString* displayName;
@property (nonatomic) NSString* path;
@property (nonatomic) NSString* type;
@property (nonatomic) int64_t total;
@property (nonatomic) int64_t progress;
@property (nonatomic) NSString* content;
@property (nonatomic) NSString* displayMessage;
@property (nonatomic) NSURL* urlPath;
@property (nonatomic) id itemData;
@property (nonatomic) id altData;
@property (nonatomic, readonly) CGFloat pctComplete;
@property (nonatomic) NSDictionary* serviceParams;

- (id) initWithName:(NSString*)itemName path:(NSString*)itemPath type:(NSString*) itemType;
- (id) initWithName:(NSString*)itemName type:(NSString*)itemType;
- (BOOL) isZip;
- (void) setServiceUrl:(NSString*)url;
- (NSString*) buildPathForType;
@end
