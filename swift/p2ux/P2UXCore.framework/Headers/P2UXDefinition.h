//
//  P2UXDefinition.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 9/28/16.
//  Copyright (c) 2016 Phase 2 Industries, LLC. All rights reserved.
//
//  Version 2

#import <P2UXCore/P2UXElement.h>
#import <P2UXCore/P2UXEvent.h>


extern NSString* const TypeClass_Screen;
extern NSString* const TypeClass_Panel;
extern NSString* const TypeClass_View;

@class P2UXState, P2UXEventTransition, P2UXScreenOrientation, P2UXScreenStateDefinition, P2UXScreenNavigation;

@interface P2UXDefinition : NSObject
{
    NSDictionary*           _fonts;
    NSMutableDictionary*    _controlsMap;
    NSString*               _assetPath;
}
@property (nonatomic, readonly) P2UXScreenNavigation* navigation;
@property (nonatomic, readonly) P2UXOrientationType supportedOrientation;
@property (nonatomic, readonly) P2UXOrientationType orientationOverride;
@property (nonatomic, readonly) NSString* assetPath;
@property (nonatomic) NSMutableDictionary* controlsMap;
@property (nonatomic) NSMutableArray* controls;
@property (nonatomic, readonly, copy) NSString* type;
@property (nonatomic) BOOL external;
@property (nonatomic, readonly) NSDictionary* objects;
@property (nonatomic) BOOL sharedControlMap;
@property (nonatomic,readonly) NSDictionary* attributes;
@property (nonatomic, readonly) NSDictionary* itemspec;
@property (nonatomic, readonly) BOOL valid;
@property (nonatomic, readonly) NSString* ident;
@property (nonatomic) NSString* typeClass;
@property (nonatomic) NSString* systemType;
@property (nonatomic, readonly) P2UXState* state;
@property (nonatomic, readonly) P2UXState* defState;
@property (nonatomic, readonly) BOOL autoSizeHeight;
@property (nonatomic, readonly) BOOL autoSizeWidth;
@property (nonatomic, readonly) NSString* displayName;
@property (nonatomic, readonly) BOOL tagged;
@property (nonatomic, readonly) P2UXScreenStateDefinition* landscape;
@property (nonatomic, readonly) P2UXScreenStateDefinition* portrait;

+ (NSInteger) nextTag;
- (void) clearEvents;
- (void) clearContents;
- (void) loadDefinitionFromPath:(NSString*)path dir:(NSString*)dir supportedOrientations:(P2UXOrientationType)supportedOrientation;
- (void) loadDefinitionFromResource:(NSString*)path dir:(NSString*)dir supportedOrientations:(P2UXOrientationType)supportedOrientation;
- (void) loadDefinitionFromDictionary:(NSDictionary*) objects dir:(NSString*)dir supportedOrientations:(P2UXOrientationType)supportedOrientation;
- (void) loadFonts:(NSDictionary*)fonts;
- (NSDictionary*) background;
- (NSString*) pathForFontWithId:(NSString*)fontId;
- (P2UXElementInstance*) elementInstanceWithTag:(NSInteger)tag;
- (P2UXElement*) elementWithType:(NSString*)elemType;
- (NSArray*) elementsWithType:(NSString*)elemType;
- (NSArray*) elementsWithCtrlType:(P2UXControlType)elemType;
- (NSArray*) elements;

- (NSArray*) linkItems;

- (BOOL) boolAttributeWithName:(NSString*)name defaultValue:(BOOL)value;
- (void) cleanup;
- (BOOL) hasIdentOrSystemType:(NSString*)identOrSystemType;
//- (P2UXScreenOrientation*) changeOrientation:(P2UXOrientationType)orientationType;
//- (P2UXScreenOrientation*) orientationForType:(P2UXOrientationType)orientationType;

- (P2UXScreenStateDefinition*) currentOrientationDef;
- (instancetype) cloneWithStateSpec:(NSDictionary*)state;
- (void) replaceOrientations:(P2UXScreenStateDefinition*)statedef;
@end
