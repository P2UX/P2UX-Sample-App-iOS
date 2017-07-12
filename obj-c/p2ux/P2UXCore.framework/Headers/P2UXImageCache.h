//
//  P2UXImageCache.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 8/4/14.
//  Copyright (c) 2014 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface P2UXImageCache : NSObject
{
    NSCache*                _images;
    NSCache*                _svgImages;
}
+(NSString*) newUniqueID;

+ (instancetype) instance;
+ (NSString*) keyFromPath:(NSString*)path andRef:(NSString*)ref colorize:(id)colorize;

- (UIImage*) imageForRef:(NSString*)ref path:(NSString*)path external:(BOOL)external type:(NSInteger)type state:(NSInteger)state;
- (UIImage*) imageForRef:(NSString*)ref path:(NSString*)path external:(BOOL)external type:(NSInteger)type state:(NSInteger)state size:(CGSize)size colorize:(id)colorize viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;
- (UIImage*) imageForRef:(NSString*)ref path:(NSString*)path external:(BOOL)external colorize:(id)colorize viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;
- (UIImage*) imageForRef:(NSString*)ref path:(NSString*)path external:(BOOL)external size:(CGSize)size colorize:(id)colorize viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;
- (void) releaseImageForPath:(NSString*)path andRef:(NSString*)ref colorize:(id)colorize;
- (void) releaseImageForKey:(NSString*)key;
- (void) clearCache;
@end
