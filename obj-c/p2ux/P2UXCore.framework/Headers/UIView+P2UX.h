//
//  UIView+P2UX.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 3/16/15.
//  Copyright (c) 2015 Phase 2 Industries, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <P2UXCore/P2UXViewContainerDelegate.h>
#import <P2UXCore/P2UXActionDelegate.h>

@class P2UXVarLinks, P2UXSourcedData, P2UXVarLink, P2UXElement;

void dispatch_uisafe(dispatch_block_t block);

@interface UIView (P2UX)

+ (void)animateWithDurationUsingAnimations:(void (^)(void))animations completion:(void (^)(BOOL finished))completion animSpec:(id)animSpec;

- (id) initWithFrame:(CGRect)frame elemInst:(P2UXElementInstance *)elemInst viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate index:(id)index;
- (id) initWithFrame:(CGRect)frame elemInst:(P2UXElementInstance *)elemInst uipath:(NSString *)path ext:(BOOL)ext viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate index:(id)index;

- (void) setIgnored:(NSNumber*)ignored;
- (NSNumber*) ignored;
- (void) setIgnoreInView:(P2UXElementLayoutDim)ignore;
//- (BOOL) handleVarUpdate:(NSNotification*)notification links:(P2UXVarLinks*)links;
- (NSDictionary*) handleProgressUpdate:(NSNotification*)notification links:(P2UXVarLinks*)links;
- (void) initializeControl;
- (void) initializeControls;
- (void) parseSpec:(NSDictionary*)spec;

- (BOOL) setAttribute:(id)value withName:(NSString*)name relative:(BOOL)relative animated:(id)animated itemspec:(NSDictionary*)itemspec;
- (id)   valueForAttribute:(NSString*)attribute;
- (void) setAnimations:(NSDictionary*)animations;
- (NSDictionary*) animations;
- (void) setViewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;
- (id<P2UXViewContainerDelegate>) viewDelegate;
- (void) setIndexValue:(id)index;
- (id)   indexValue;
- (P2UXElementInstance*) elemInstance;
- (void) setElemInstance:(P2UXElementInstance*)elemInstance;
- (void) setLinks:(P2UXVarLinks*)links;
- (P2UXVarLinks*) links;
- (void) setPath:(NSString*)path;
- (NSString*)path;
- (void) setSpec:(NSDictionary*)spec;
- (NSDictionary*) spec;
- (NSMutableDictionary*) linksCache;
- (UIView*) constraintParent;
- (void) setConstraintParent:(UIView*)constraintParent;
- (void) setExternalData:(id)externalData;
- (id) externalData;
- (NSMutableDictionary*) controlsMap;
- (void) setControlsMap:(NSMutableDictionary*)controlsMap;
- (void) clearLinkCache;
- (void) setAlpha:(CGFloat)alpha animated:(id)animated;
- (void) setRotation:(CGFloat)degrees animated:(id)animated;
- (void) ignoreInView:(P2UXElementLayoutDim)action notify:(BOOL)notify;
- (void) hideUsingAttribute:(NSLayoutAttribute)attribute notify:(BOOL)notify;
- (void) showUsingAttribute:(NSLayoutAttribute)attribute notify:(BOOL)notify;
- (void) updateContentsFromSizeChange;
- (void) updateFrameSize:(CGFloat)size attribute:(NSLayoutAttribute)attribute notify:(BOOL)notify;
- (void) cleanup;
- (BOOL) updateIdleConstraints:(NSMutableArray*)constraints;
- (void) updateIndexValue:(id)value;
- (NSString*) getAppState;
- (NSArray*) constraintsFromRect:(NSDictionary*)rect parent:(UIView*)parent;
- (UIView*) viewFromElement:(P2UXElement*)elem;
- (UIView*) findNextFocusControlWithCurrent:(UIView*)current;
- (UIView*) findFirstResponder;
- (void) notifyAttributeChanged:(NSString*)attribute value:(id)value;
- (void) setExternal:(BOOL)external;
- (BOOL) external;
- (UIView*) controlWithElementSystemTypeOrId:(NSString*) type;
- (NSArray*) controlsWithElementType:(NSString*)type;
- (void) reapplyConstraints;
- (NSString*) systemType;
- (NSString*) elId;
- (void) linksCreated;
- (BOOL) supportsRotation;
- (CGSize) frameSize;
- (void) updateStatefulValues;
- (void) attachingToScroll;
- (void) addSubviewToScroll:(UIView*)view;

#pragma mark - Subview helpers
- (P2UXView*) createSubViewFromSpec:(NSDictionary*)viewspec itemRect:(CGRect)itemRect handler:(id<P2UXActionDelegate>)handler scrollStyle:(P2UXScrollStyle)scrollStyle viewAttributes:(NSMutableDictionary*)viewAttributes;
- (P2UXView*) createSubViewFromSpec:(NSDictionary*) viewspec itemSize:(NSDictionary*)itemSize itemPos:(NSDictionary*)itemPos cacheVal:(NSNumber*)cacheVal index:(id)index handler:(id<P2UXActionDelegate>)handler itemRect:(CGRect)itemRect scrollStyle:(P2UXScrollStyle)scrollStyle viewAttributes:(NSMutableDictionary*)viewAttributes;
- (P2UXView*) createSubView:(NSString*) viewIdent itemSize:(NSDictionary*)itemSize itemPos:(NSDictionary*)itemPos cache:(NSNumber*)cacheVal index:(id)index handler:(id<P2UXActionDelegate>)handler itemRect:(CGRect)itemRect scrollStyle:(P2UXScrollStyle)scrollStyle viewAttributes:(NSMutableDictionary*)viewAttributes;
- (CGRect) itemRectForSize:(NSDictionary*)sizespec pos:(NSDictionary*)pos  attributes:(NSMutableDictionary*)attributes;
- (P2UXView*) createViewItemWithSpec:(NSDictionary*)spec rect:(CGRect)rect cache:(BOOL)cache index:(id)index data:(id)data;

#pragma mark - Link methods
- (BOOL) setupLinksAndUpdate:(BOOL)update async:(BOOL)async;
- (BOOL) setupLinksFromItems:(NSArray*)links andUpdate:(BOOL)update async:(BOOL)async;
- (void) handleUpdateForLinks;
- (void) handleUpdateWithLinks:(NSArray*)links;
- (void) handleUpdateWithLinks:(NSArray*)links progressLinks:(NSArray*)progressLinks data:(P2UXSourcedData*)data;
- (BOOL) hasLinksForAttribute:(NSString*)attribute;

#pragma mark - Link overrides for subclasses
//- (void) varUpdate:(NSNotification*)notification;
- (id)   dataForLinkAttribute:(P2UXVarLink*)link attributes:(NSArray*)attribute progressLinks:(NSArray*)progressLinks data:data;
- (void) updateLinkAttributeHandler:(P2UXVarLink*)link attribute:(NSString*)attribute value:(id)value;
- (void) updateLinkMissingAttributeHandler:(P2UXVarLink*)link attributes:(NSArray*)attributes;
- (void) updateLinkPostFilterHandler:(NSMutableDictionary*)varfilters conditionals:(NSDictionary*)conditionals varlinkvalues:(NSMutableDictionary*)varlinkvalues primaryValue:(NSString*)primaryValue;
- (BOOL) updateLinkSetVariableValueHandler:(id)value attributes:(NSArray*)attributes varlinkvalues:(NSMutableDictionary*)varlinkvalues;
- (NSString*) updateLinkDefaultValue;

- (id) objectForKey:(NSString*)key itemspec:(NSDictionary*) itemspec stylespec:(NSDictionary*)stylespec;
- (void) rotateViewWithDegrees:(float)degrees;
- (void) adjustRelativePositionX:(NSInteger) x y:(NSInteger) y;
- (CGRect) centerFrameWithSizeSpec:(NSDictionary*)sizeSpec view:(UIView*)view;
- (CGRect) centerFrameWithSize:(CGSize)size view:(UIView*)view;
- (UIImageView*) renderBackground:(NSDictionary*)background def:(P2UXDefinition*)def;
- (UIImageView*) renderBackground:(NSDictionary*)background path:(NSString*)path ext:(BOOL)ext;
- (UIImageView*) renderBackground:(NSDictionary*)background path:(NSString*)path ext:(BOOL)ext type:(NSInteger)type;
- (UIImageView*) renderBackground:(NSDictionary*)background path:(NSString*)path ext:(BOOL)ext type:(NSInteger)type  scaleType:(P2UXScaleType)scaleType;

- (void) releaseBackground:(NSDictionary*)background def:(P2UXDefinition*)def;
- (void) releaseBackground:(NSDictionary*)background path:(NSString*)path;
- (void) loadButton:(UIButton*)btn values:(NSArray*)statesObj path:(NSString*)path ext:(BOOL)ext type:(NSInteger)type;
- (void) setShadowFromSpec:(NSDictionary*)shadowSpec;
- (P2UXView*) parentContainer;
- (UIView*) keyboardScrollContainer;

- (void) animateWithSpec:(id)spec animations:(void (^)(void))animations completion:(void (^)(BOOL finished))completion;
- (UIImageView*) cloneAsImageView;
- (BOOL) hasParentScrollView;
- (CGFloat) rotation;
@end
