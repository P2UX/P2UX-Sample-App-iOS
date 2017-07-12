//
//  P2UXResourceHandler.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 4/5/13.
//  Copyright (c) 2014 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AudioToolbox/AudioToolbox.h>
#import <AVFoundation/AVFoundation.h>

@protocol P2UXResourceDelegate <NSObject>
- (void) audioComplete:(NSString*)resource;
@end

@interface P2UXResourceHandler : NSObject<AVAudioPlayerDelegate>

+ (instancetype) instance;
- (void)        playLocalSoundAsset:(NSString*)resource delegate:(id<P2UXResourceDelegate>)delegate;
+ (UIImage*)    localImage:(NSString*)resource;
+ (NSString*)   localResourcePath:(NSString*)resource;

- (void) playSoundAsset:(NSString*)resource path:(NSString*)path ext:(BOOL)ext  delegate:(id<P2UXResourceDelegate>)delegate;


- (void) handleSoundAssetComplete:(SystemSoundID)soundId;
- (void) audioPlayerDidFinishPlaying:(AVAudioPlayer*)player successfully:(BOOL)flag;
@end
