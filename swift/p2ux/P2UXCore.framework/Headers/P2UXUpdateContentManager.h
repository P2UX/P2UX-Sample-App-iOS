//
//  P2UXUpdateContentManager.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 1/18/13.
//  Copyright (c) 2014 Phase 2 Industries, LLC. All rights reserved.
//

#import <P2UXCore/P2UXContentManager.h>

@protocol P2UXUpdateContentManagerDelegate <P2UXContentManagerDelegate>
- (void) upgradeStart;
- (void) upgradeComplete:(BOOL)success manual:(BOOL)manual;
- (void) upgradeSessionError;
@end

@interface P2UXUpdateContentManager : P2UXContentManager
{
    BOOL                 _upgrade;
    BOOL                 _upgraded;
    BOOL                 _manual;
}
+ (instancetype) sharedManager;
@property (nonatomic) BOOL groups;

- (P2UXContentItem*) addDownloadRequest:(NSString*)downloadId forType:(NSString*)type displayName:(NSString*)displayName;
- (ContentManagerError) contentItemComplete:(P2UXContentItem *)item toTarget:(NSString *)targetFolder;
- (NSString*) serviceURL:(NSString*)itemType;

- (NSDictionary*) infoForType:(NSString*)type rid:(NSString*)rid;

- (void) checkForUpgrades:(NSDictionary*)items delegate:(id<P2UXUpdateContentManagerDelegate>)delegate manual:(BOOL)manual;
- (BOOL) processUpgrade:(NSDictionary*)result type:(NSString*)type rid:(NSString*)rid;
- (NSString*) updateStringForType:(NSString*)type;
- (NSString*) processFullPath:(NSString*)path withType:(NSString*)type usingData:(NSDictionary*)data;
- (void) createDataFromItem:(P2UXContentItem*)item withFolder:(NSString*)folder;
- (void) createInfoForType:(NSString*)type name:(NSString*)itemId;
@end
