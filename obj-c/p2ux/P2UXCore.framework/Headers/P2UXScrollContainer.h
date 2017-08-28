//
//  P2UXScrollContainer2.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 11/14/13.
//  Copyright (c) 2013 Phase 2 Industries, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <P2UXCore/P2UXActionDelegate.h>
#import <P2UXCore/P2UXControl.h>
#import <P2UXCore/P2UXVarLinks.h>
#import <P2UXCore/P2UXData.h>
#import <P2UXCore/P2UXEventTransition.h>
#import <P2UXCore/P2UXScrollContainerContents.h>
#import <P2UXCore/P2UXScreenState.h>

@class P2UXApplication;
@class P2UXView;
@class P2UXContainerElement;
@class P2UXDisplayLayout;
@class P2UXElement;
@class P2UXElementInstance;
@class P2UXScreenStateDefinition;

extern NSString* const P2UXScrollContainer_Attribute_PageIndex;

@interface P2UXScrollContainer : UIScrollView<P2UXControl,
                                            UIScrollViewDelegate,
                                            P2UXData>
{
    P2UXContainerElement*             _elem;
    __weak P2UXScreenStateDefinition* _parentDef;
    __weak id<P2UXActionDelegate>     _handler;
    P2UXScrollStyle                   _scrollStyle;
    BOOL                            _paging;
    BOOL                            _bounces;
    BOOL                            _showScroll;
    BOOL                            _useConstraints;
    UIImage*                        _fillImage;
    NSArray*                        _pagingEvents;
    CGFloat                         _totalSize;
    id                              _context;
    CGFloat                          _startPadding;
    CGFloat                          _endPadding;
    CGSize                           _scrollSize;
    __weak id                        _data;
    BOOL                             _updateLinkClear;
    CGFloat                          _spacing;
    P2UXScrollContainerContents*       _contentView;
}
@property (nonatomic)           NSInteger     initialItem;
@property (nonatomic)           NSInteger     page;
@property (nonatomic)           NSInteger     pages;
@property (nonatomic)           P2UXView*       currentView;
@property (nonatomic)           NSString*     exportType;
@property (nonatomic, readonly) NSArray*      controls;

- (id) initWithFrame:(CGRect)frame elemInst:(P2UXElementInstance*)elemInst uipath:(NSString *)path ext:(BOOL)ext handler:(id<P2UXActionDelegate>)handler parentDef:(P2UXScreenStateDefinition*)parentDef viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate index:(id)index data:(id)data stateDelegate:(id<P2UXScreenStateDelegate>)stateDelegate;

- (void) scrollToView:(NSString*)ident animated:(NSNumber*)anim;
- (P2UXElementInstance*) elementInstanceWithTag:(NSInteger)tag;
- (UIView*) viewForElement:(P2UXElement*)element;
- (UIView*) containingViewForElement:(P2UXElement*)element;
- (void) setCurrentPage;
- (void) updateDisplay;
- (void) addView:(P2UXView*)view update:(BOOL)update;
- (void) scrollToPage:(NSInteger)page animated:(BOOL)animated;
- (void) incrementPage:(BOOL)animated;
- (void) decrementPage:(BOOL)animated;

#pragma mark - Internal Methods
- (void) parseContents;
- (void) sortViews;
- (void) measureContent;
- (void) updatePaging;

#pragma mark - P2UXControl
- (void) cleanup;
- (void) setData:(NSDictionary *)data;
- (void) handleActionParams:(NSDictionary*)action;
- (void) updateContents;

#pragma mark - P2UXData
- (id) valueForAttribute:(NSString*)attribute;
- (void) setValue:(id)value forAttribute:(NSString *)attribute;

#pragma mark - UIScrollViewDelegate
- (void) scrollViewDidScroll:(UIScrollView *)scrollView;

#pragma mark - P2UXScrollerDelegate
- (void) scrollUp:(NSInteger)num;
- (void) scrollDown:(NSInteger)num;

@end
