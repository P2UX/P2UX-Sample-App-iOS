//
//  P2UXContentManager.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 12/13/12.
//  Copyright (c) 2014 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@class P2UXContentItem, P2UXHTTPSessionManager;

typedef NS_ENUM(NSInteger, ContentManagerState) {
    kContentManager_Idle = 0,
    kContentManager_Downloading,
    kContentManager_Checking
};

typedef NS_ENUM(NSInteger, ContentManagerError) {
    ContentManagerError_None = 0,
    ContentManagerError_NotFound,
    ContentManagerError_Network,
    ContentManagerError_InvalidZip,
    ContentManagerError_CorruptedContent,
    ContentManagerError_Auth,
    ContentManagerError_License
};

@protocol P2UXContentManagerDelegate <NSObject>
@optional
- (void) contentItemProgress:(P2UXContentItem*)item value:(NSInteger)value total:(NSInteger)total;
- (void) contentItemDownloaded:(P2UXContentItem*)item result:(ContentManagerError)result;
- (void) contentItemInstalling:(P2UXContentItem*)item;
- (BOOL) willStartNextDownload:(P2UXContentItem*) item;
- (void) contentItemStart:(P2UXContentItem*)item;
- (void) contentComplete:(ContentManagerError)result;
@end


@interface P2UXContentManager : NSObject<NSURLConnectionDelegate>
{
    NSString*            _filename;
    NSMutableDictionary* _requests;
    NSMutableArray*      _pendingRequests;
    ContentManagerState  _state;
    int                  _currentItemIndex;
    NSMutableData*       _receivedData;
    NSOperationQueue*    _netQueue;
    P2UXHTTPSessionManager* _sessionMgr;
    ContentManagerError  _result;
}
@property (nonatomic) id<P2UXContentManagerDelegate> delegate;
@property (nonatomic, readonly) NSInteger count;
@property (nonatomic) BOOL locked;

- (void) addDownloadFromURL:(NSString*)downloadURL;
- (void) addDownloadRequest:(P2UXContentItem*)item;

- (void) start:(id<P2UXContentManagerDelegate>)delegate;
- (void) clear;

- (P2UXContentItem*) createContentItem:(NSString*)filename path:(NSString*)path type:(NSString*)type;
- (NSDictionary*) serviceQueryParams;

- (void) contentComplete;
- (ContentManagerError) contentItemComplete:(P2UXContentItem*)item toTarget:(NSString*)targetFolder;
- (ContentManagerError) contentItemComplete:(P2UXContentItem*)item data:(NSData*)data;
@end
