//
//  P2UXFontManager.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 9/1/15.
//  Copyright (c) 2015 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface P2UXFontManager : NSObject
+ (BOOL)loadFontFullPath:(NSString *)fontPath name:(NSString*)filename;
+ (instancetype) sharedManager;
- (BOOL)loadFont:(NSString *)filename;
- (BOOL)loadFontFullPath:(NSString *)fontPath name:(NSString*)filename;
- (BOOL)loadFontURL:(NSURL *)url;
- (CGFontRef)fontWithName:(NSString *)filename __AVAILABILITY_INTERNAL_DEPRECATED;

#if TARGET_OS_OSX
- (CTFontRef)ctFontWithName:(NSString *)filename pointSize:(CGFloat)pointSize;
#else
- (OSFontClass*) uiFontWithName:(NSString*)filename pointSize:(CGFloat)pointSize;
#endif

@end
