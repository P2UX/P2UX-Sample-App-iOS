//
//  P2UXAudioMediaManager.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 12/12/16.
//  Copyright © 2016 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString* const P2UXAudioMediaArg_SortField;
extern NSString* const P2UXAudioMediaArg_Filter;

extern NSString* const P2UXAudioMedia_Action_Play;
extern NSString* const P2UXAudioMedia_Action_Pause;
extern NSString* const P2UXAudioMedia_Action_Stop;
extern NSString* const P2UXAudioMedia_Action_Next;
extern NSString* const P2UXAudioMedia_Action_Prev;
extern NSString* const P2UXAudioMedia_Action_Load;

extern NSString* const P2UXMediaVar_Title;
extern NSString* const P2UXMediaVar_Album;
extern NSString* const P2UXMediaVar_Artist;
extern NSString* const P2UXMediaVar_Duration;
extern NSString* const P2UXMediaVar_Playtime;
extern NSString* const P2UXMediaVar_PlayIndex;
extern NSString* const P2UXMediaVar_PlayState;
extern NSString* const P2UXMediaVar_Art;
extern NSString* const P2UXMediaVar_Item;
extern NSString* const P2UXMediaVar_Volume;
extern NSString* const P2UXMediaVar_NotifyTime;
extern NSString* const P2UXMediaVar_Mute;

extern NSString* const P2UXEvent_Media_Attribute;
extern NSString* const P2UXEvent_Media_Value;
extern NSString* const P2UXEvent_Media_Attribute_PlayState;
extern NSString* const P2UXEvent_Media_Attribute_Loaded;

typedef NS_ENUM(NSInteger, P2UXAudioMediaGrouping) {
    P2UXAudioMediaGrouping_Title = 1,
    P2UXAudioMediaGrouping_Album,
    P2UXAudioMediaGrouping_Artist,
    P2UXAudioMediaGrouping_Genre
};

typedef NS_ENUM(NSInteger, P2UXAudioMediaFilterType) {
    P2UXAudioMediaFilterType_Music = 1,
    P2UXAudioMediaFilterType_AudioBook = 2,
    P2UXAudioMediaFilterType_Podcast = 4
};

typedef NS_ENUM(NSInteger, P2UXMediaPlayState) {
    P2UXMediaPlayState_Idle = -1,
    P2UXMediaPlayState_Stopped = 0,
    P2UXMediaPlayState_Playing,
    P2UXMediaPlayState_Paused
};

@protocol P2UXAudioMediaManagerDelegate <NSObject>

- (void) queryAudioComplete:(id)data requestID:requestID;

@end

@interface P2UXAudioMediaManager : NSObject
{
}
@property (nonatomic) CGFloat volume;
@property (nonatomic) BOOL mute;
@property (nonatomic) BOOL notifyTime;
+ (instancetype) instance;
+ (NSString*) formatNotification:(NSString*)fmt param1:(NSString*)param1;

- (void) clear;
- (void) setVolume:(CGFloat)volume relative:(BOOL)relative notify:(BOOL)notify;
- (id) valueForLink:(P2UXVarLink*)link withIndex:(id)index;
- (id) dataForLink:(P2UXVarLink*)link;
- (void) setVarValue:(id)value forKey:(NSString*)key notify:(BOOL)notify itemspec:(NSDictionary*)itemspec;

- (BOOL) queryAudioContentWithArgs:(NSDictionary*)args requestID:(NSString*)requestID delegate:(id<P2UXAudioMediaManagerDelegate>)delegate;

- (void) loadAudioFromLink:(P2UXVarLink*)link options:(NSDictionary*)options index:(id)index;
- (void) pause;
- (void) stop;
- (void) play;
- (void) next;
- (void) prev;
@end
