//
//  P2UXAppDefinition.h
//  P2UXApp
//
//  Created by Stephen Schalkhauser on 6/2/14.
//  Copyright (c) 2016 Phase 2 Industries, LLC. All rights reserved.
//
//  Version: 2

#import <Foundation/Foundation.h>
#import <P2UXCore/P2UXCore.h>

@class P2UXAppBehavior;
@class P2UXAppFormFactor;
@class P2UXScreen;
@class P2UXScreenNavigation;

extern NSString* const P2UXApp_Type;
extern NSString* const P2UXApp_App_Dir;

typedef NS_ENUM(NSInteger, P2UXStatusBar) {
    P2UXStatusBar_Default = -1,
    P2UXStatusBar_None = 0,
    P2UXStatusBar_Light = 1,
    P2UXStatusBar_Dark
};


@interface P2UXAppDefinition : NSObject<P2UXVarDelegate>
{
    NSDictionary*           _appData;
    
    NSMutableDictionary*    _nativeDialogs;
    
    NSString*               _appId;
    NSString*               _assetPath;
    
    P2UXAppBehavior*        _behavior;

    NSMutableDictionary*    _appVars;
    NSMutableDictionary*    _appVarLinks;
    NSMutableArray*         _events;
    
    NSMutableArray*         _activeFormFactors;
    NSString*               _startScreen;
    NSString*               _splashScreen;
}

@property (nonatomic, readonly) P2UXAppBehavior* behavior;
@property (nonatomic, readonly) P2UXOrientationType orientation;
@property (nonatomic, readonly) BOOL supportedPlatform;
@property (nonatomic, readonly) NSInteger type;
@property (nonatomic, readonly) NSString* appId;
@property (nonatomic, readonly) NSArray* languages;
@property (nonatomic, readonly) P2UXStatusBar statusBar;
@property (nonatomic, readonly) P2UXAppFormFactor* primaryFormFactor;
@property (nonatomic, readonly) NSString* assetPath;
@property (nonatomic, readonly) BOOL external;
@property (nonatomic, readonly) P2UXPaletteManager* palettes;
@property (nonatomic, readonly) P2UXScreenNavigation* navigation;

- (id)                initWithAppID:(NSString*)appId behavior:(P2UXAppBehavior*)behavior;
- (id)                initFromBundleWithAppID:(NSString *)appId dir:(NSString*)dir behavior:(P2UXAppBehavior *)behavior;
- (void)              cleanup;

- (NSDictionary*)     nativeDialogWithIdent:(NSString*)ident;

- (void)              initialize;
- (NSArray*)          eventsWithEventType:( P2UXElementEvent)eventType;

- (void)              resetEvents;

#pragma mark - Form Factor methods
- (P2UXAppFormFactor*) supplementalFormFactor:(P2UXFormFactor)type;
- (void)              removeSupplementalFormFactor:(P2UXAppFormFactor*)ff;

#pragma mark - Variable methods
- (id)                varForKey:(NSString*)key ident:(NSString*)ident withType:(NSInteger)type;
- (BOOL)              setVarValue:(id)value forKey:(NSString*)key itemspec:(NSDictionary*)itemspec;
- (BOOL)              setVarValue:(id)value forKey:(NSString*)key usingIdent:(NSString *)ident withType:(NSInteger)type notify:(BOOL)notify itemspec:(NSDictionary*)itemspec;
- (NSDictionary*)     cacheState;
- (void)              restoreState:(NSDictionary*)state;

@end
