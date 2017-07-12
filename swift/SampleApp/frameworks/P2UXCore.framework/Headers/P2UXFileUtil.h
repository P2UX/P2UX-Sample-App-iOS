//
//  P2UXFileUtil.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 12/3/12.
//  Copyright (c) 2014 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

#define DATA_DIR @"data"
#define APPS_DIR @"apps"

@interface P2UXFileUtil : NSObject
+ (NSURL*)          applicationDataDirectory;
+ (NSData*)         getContentsOfFile:(NSString *)file;
+ (BOOL)            putContents:(NSData *)contents inFile:(NSString *)file withOverwrite:(BOOL)overwrite;
+ (BOOL)            deleteFile:(NSString *)file;
+ (BOOL)            deleteFileWithFullPath:(NSString*)path;
+ (NSString*)       createAppDirectory:(NSString*)name;
+ (NSURL*)          createAppDirectoryURL:(NSString*)name;
+ (NSString*)       getPathForType:(NSString*)type itemId:(NSString*)itemId;
+ (BOOL)            contentExists:(NSString*)type itemId:(NSString*)itemId;
+ (BOOL)            contentExists:(NSString*)type itemId:(NSString*)itemId ext:(NSString*)ext;

#pragma mark - data JSON methods
+ (BOOL)            saveJSONForType:(NSString*)type itemId:(NSString*)itemId data:(NSDictionary*)data;
+ (BOOL)            saveJSONForType:(NSString*)type itemId:(NSString*)itemId data:(NSDictionary*)data user:(NSString*)user;
+ (BOOL)            saveJSONForType:(NSString*)type itemId:(NSString*)itemId data:(NSDictionary*)data user:(NSString *)user dir:(NSString*)dir key:(NSString*)key;
+ (NSDictionary*)   loadJSONForType:(NSString*)type itemId:(NSString*)itemId;
+ (NSDictionary*)   loadJSONForType:(NSString*)type itemId:(NSString*)itemId dir:(NSString*)dir key:(NSString*)key;
+ (NSDictionary*)   loadJSONForType:(NSString*)type itemId:(NSString*)itemId dir:(NSString*)dir;
+ (NSDictionary*)   loadJSONForType:(NSString*)type itemId:(NSString*)itemId mutable:(BOOL)mutable dir:(NSString*)dir key:(NSString*)key;
+ (NSDictionary*)   loadJSONForType:(NSString*)type itemId:(NSString*)itemId mutable:(BOOL)mutable;
+ (NSDictionary*)   loadJSONForType:(NSString*)type itemId:(NSString*)itemId mutable:(BOOL)mutable user:(NSString*)user;
+ (NSDictionary*)   loadJSONForType:(NSString*)type itemId:(NSString*)itemId mutable:(BOOL)mutable user:(NSString*)user filename:(NSString*)filename;
+ (NSDictionary*)   loadJSONForType:(NSString*)type itemId:(NSString*)itemId mutable:(BOOL)mutable user:(NSString*)user filename:(NSString*)filename dir:(NSString*)dir key:(NSString*)key;
+ (NSDictionary*)   loadJSONFromPath:(NSString*)fullPath mutable:(BOOL) mutable key:(NSString*)key;
+ (NSDictionary*)   loadJSONDirectForType:(NSString*)type itemId:(NSString*)itemId mutable:(BOOL)mutable user:(NSString*)user;
+ (NSString*)       pathForType:(NSString*)type itemId:(NSString*)itemId user:(NSString*)user;
+ (NSArray*)        contentsForType:(NSString*)type user:(NSString*)user;
+ (BOOL) unzipArchiveFile:(NSString *)filePath toTarget:(NSString*)targetFolder;
+ (BOOL) validateArchive:(NSString*)filePath withKey:(NSString*)key;

#pragma mark - info JSON methods
+ (NSDictionary*)   infoJSONForType:(NSString*)type itemId:(NSString*)itemId;
+ (NSDictionary*)   infoJSONForType:(NSString*)type itemId:(NSString *)itemId user:(NSString*)user;
+ (NSDictionary*)   infoJSONFromBundleForType:(NSString*)type assetPath:(NSString*)assetPath;

+ (void) createInfoForType:(NSString*)type name:(NSString*)itemId;
+ (void) createInfoForType:(NSString*)type name:(NSString*)itemId user:(NSString*)user;
+ (void) createInfoForType:(NSString*)type name:(NSString*)itemId user:(NSString*)user def:(NSDictionary*)def;

+ (BOOL) deleteAllContentForType:(NSString*)type;
+ (BOOL) deleteAllContentForType:(NSString*)type user:(NSString*)user;
+ (BOOL) deleteAllContentForType:(NSString*)type user:(NSString*)user except:(NSArray*)except;
+ (BOOL) deleteContentForType:(NSString*)type name:(NSString*)itemId;
+ (BOOL) deleteContentForType:(NSString*)type name:(NSString*)itemId user:(NSString*)user;
+ (BOOL) deleteContentForType:(NSString*)type baseName:(NSString*)baseName user:(NSString*)user;
+ (BOOL) deleteContentForType:(NSString*)type baseName:(NSString*)baseName;


+ (BOOL) copyContentFromBundle:(NSBundle*)bundle withName:(NSString*)name extension:(NSString*)extension type:(NSString*)type keepExt:(BOOL)keepExt skipIfExists:(BOOL)skipIfExists;

#pragma mark - Data methods
+ (BOOL) saveData:(NSDictionary*)data withName:(NSString*)name;
+ (NSDictionary*) loadData:(NSString*)name;
@end
