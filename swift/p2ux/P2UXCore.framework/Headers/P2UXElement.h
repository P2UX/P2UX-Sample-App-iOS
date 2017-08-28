//
//  P2UXElement.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 11/5/12.
//  Copyright (c) 2012-2014 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <P2UXCore/P2UXVarLinks.h>
#import <P2UXCore/P2UXTypes.h>

@class P2UXElementInstance;

@interface P2UXElement : NSObject
{
    NSDictionary*         _element;
    int                   _ctrlType;
    NSString*             _type;
    NSString*             _systemType;
    NSString*             _elId;
    NSString*             _altid;
    NSDictionary*         _style;
    P2UXElement*          _subElement;
    NSInteger             _focusOrder;
    BOOL                  _canFocus;
    NSInteger             _width;
    NSInteger             _height;
    NSMutableArray*       _instances;
}
@property (nonatomic, readonly) NSDictionary* spec;
@property (nonatomic, readonly) NSString* type;
@property (nonatomic, readonly) NSString* altid;
@property (nonatomic)           NSString* elId;
@property (nonatomic, readonly) int ctrlType;
@property (nonatomic)           P2UXElement* subElement;
@property (nonatomic)           NSInteger focusOrder;
@property (nonatomic, readonly) BOOL canFocus;
@property (nonatomic, readonly) NSString* name;
@property (nonatomic) NSString* systemType;
@property (nonatomic, readonly) CGFloat opacity;
@property (nonatomic, readonly) NSArray* instances;
@property (nonatomic) NSString* layoutState;
@property (nonatomic, readonly) BOOL measureableW;
@property (nonatomic, readonly) BOOL measureableH;
@property (nonatomic) P2UXElementLayoutDim ignored;
@property (nonatomic, readonly) BOOL tagged;
@property (nonatomic, readonly) BOOL overlay;
@property (nonatomic, readonly) BOOL disabled;

- (id) initWithDictionary:(NSDictionary*)dict;
- (void) parse;
- (void) reload:(NSDictionary*)data;
- (void) maskType:(NSString*)type;
- (void) cleanup;

- (P2UXElement*) getControlElement:(NSString*)elemId;
- (P2UXElementInstance*) getControlElementInstanceWithTag:(NSInteger)tag;
- (P2UXElement*) getControlElementWithType:(NSString*)type;
- (P2UXElement*) getControlElementWithSystemType:(NSString*)type;
- (P2UXElement*) getControlElementWithAltId:(NSString*)altid;
- (void) getControlElementsWithType:(NSString*)type controls:(NSMutableArray*)controls;
- (void) getControlElementsWithCtrlType:(P2UXControlType)type controls:(NSMutableArray*)controls;
- (void) getControlElements:(NSMutableArray*)controls;

- (void) setLayoutState:(NSString *)state;

- (void) addInstance:(P2UXElementInstance*)instance;
- (void) removeInstance:(P2UXElementInstance*)instance;
@end
