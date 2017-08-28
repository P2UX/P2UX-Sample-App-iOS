//
//  P2UXVarLinks.h
//  P2UXCore
//
//  Created by Phase 2 Industries, LLC on 7/9/14.
//  Copyright (c) 2014 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <P2UXCore/P2UXVarLink.h>
#import <P2UXCore/P2UXLocationManagerDelegate.h>

typedef NS_ENUM(NSInteger, P2UXExpressionType) {
    P2UXExpressionType_Math = 0,
    P2UXExpressionType_Location,
    P2UXExpressionType_Time,
    P2UXExpressionType_Function
};

extern NSString* const P2UXVarLinks_Conditional;
extern NSString* const P2UXVarLinks_Conditional_then;
extern NSString* const P2UXVarLinks_Conditional_else;
extern NSString* const P2UXVarLinks_Eval;
extern NSString* const P2UXVarLinks_String;
extern NSString* const P2UXVarLinks_VarDelimiter;
extern NSString* const P2UXVarLinks_InternalValDelimiter;
extern NSString* const P2UXVarLinks_AttribDelimiter;
extern NSString* const P2UXVarLinks_ExpressionStart;
extern NSString* const P2UXVarLinks_ExpressionEnd;
extern NSString* const P2UXVarLinks_FuncStart;
extern NSString* const P2UXVarLinks_FuncEnd;
extern NSString* const P2UXVarLinks_Var_Lat;
extern NSString* const P2UXVarLinks_Var_Lon;
extern NSString* const P2UXVarLinks_Var_Timestamp;
extern NSString* const P2UXVarLinks_VarPrefix;


@interface P2UXVarLinks : NSObject
{
    NSMutableArray*       _links;
    __weak OSViewClass*   _view;
    NSMutableDictionary*  _msgMap;
}
@property (nonatomic) NSArray* varlinks;
+ (NSCharacterSet*) encodedCharSet;
+ (BOOL) containsConditional:(NSString*)linkformat;
+ (BOOL) containsExpression:(NSString*)linkformat type:(P2UXExpressionType)type;
+ (NSString*) evaluateLinkFormat:(NSString*)linkformat conditionals:(NSDictionary*)conditionals vars:(NSDictionary*)vars delegate:(id<P2UXLocationManagerDelegate>)delegate;
#ifdef MAP_SUPPORT
+ (NSString*) evaluateLocationExpressionInFormat:(NSString*)expression vars:(NSDictionary*)vars delegate:(id<P2UXLocationManagerDelegate>)delegate;
#endif
+ (NSString*) evaluateExpressionsInFormat:(NSString*)expression;
+ (NSString*) evaluateFunction:(NSString*)func vars:(NSDictionary*)vars defaultValue:(NSString*)defaultValue;
+ (NSString*) stringFromValue:(id)value;
+ (NSString*) stringFromValue:(id)value keepPrecision:(BOOL)keepPrecision;
+ (NSString*) varValue:(NSString*)value;
+ (BOOL) isEvaluatedValue:(NSString*)value;
+ (NSString*) stripVarDelimiter:(NSString*)value;

- (id) initWithItemSpec:(NSDictionary*)itemspec index:(id)index context:(id)context viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;
- (id) initWithLinks:(NSArray*)links index:(id)index;
- (void) cleanup;
- (void) updateIndexValue:(id)value;
- (P2UXVarLink*) linkWithType:(P2UXVarLinkType)type ident:(NSString*)ident;
- (P2UXVarLink*) linkWithName:(NSString*)name;
- (P2UXVarLink*) linkWithNotification:(NSString*)notification ident:(NSString*)ident;
//- (NSArray*) linksWithNotification:(NSString*)notification ident:(NSString*)ident;
- (NSArray*) linksWithNotification:(NSString*)notification ident:(NSString*)ident request:(NSString*)request;
//- (NSArray*) linksWithItemNotification:(NSString*)notification ident:(NSString*)ident request:(NSString*)request context:(NSString*)context itemContext:(NSString*)itemContext index:(id)index;
- (NSArray*) linksWithNotification:(NSString*)notification;
- (NSArray*) linksForAttribute:(NSString*)attribute;

- (BOOL) setupNotificationsForCtrl:(id)ctrl notifyHandler:(SEL)notifyHandler;
- (void) removeNotificationsForCtrl:(id)ctrl;
- (NSArray*) dataLinksWithIndexUpdates:(NSString*)notification ident:(NSString*)ident altData:(id)altData;
- (void) updateWithAttribute:(NSString*)attribute usingValue:(id)value andIndex:(id)index;
- (NSArray*) linksWithoutAttribute:(NSString*)attribute;
@end
