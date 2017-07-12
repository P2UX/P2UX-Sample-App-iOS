//
//  P2UXPaletteManager.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 12/29/15.
//  Copyright © 2015 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@class P2UXPalette;

@interface P2UXPaletteManager : NSObject
//+ (instancetype) instance;
@property (nonatomic, readonly) P2UXPalette* currentPalette;

- (void) setPalette:(NSString*)paletteId;
- (void) addPalettes:(NSArray*)palettes;
- (OSColorClass*) colorWithId:(NSString*)colorId;
- (NSDictionary*) gradientWithId:(NSString*)gradientId;
- (void) clear;
- (void) setPaletteWithIndex:(NSUInteger)index;
@end
