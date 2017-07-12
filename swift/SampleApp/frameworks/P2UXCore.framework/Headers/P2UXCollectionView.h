//
//  P2UXCollectionView.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 1/16/15.
//  Copyright (c) 2015 Phase 2 Industries, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <P2UXCore/P2UXActionDelegate.h>
#import <P2UXCore/P2UXBaseCtrl.h>
#import <P2UXCore/P2UXControl.h>

@class P2UXElementInstance, P2UXContainerElement;

typedef NS_ENUM(NSInteger, P2UXCollectionView_SelectType) {
    P2UXCollectionView_SelectType_None = 0,
    P2UXCollectionView_SelectType_Single,
    P2UXCollectionView_SelectType_Multi
};

typedef NS_ENUM(NSInteger, P2UXCollectionView_DataType) {
    P2UXCollectionView_DataType_Dynamic = 0,
    P2UXCollectionView_DataType_Static
};

@interface P2UXCollectionView : UICollectionView <P2UXControl, UICollectionViewDataSource, UICollectionViewDelegate, UICollectionViewDelegateFlowLayout>
{
    P2UXContainerElement*         _elem;

    NSInteger                   _selectedItem;
    NSInteger                   _highlightItem;
    P2UXScrollStyle               _scrollStyle;
    CGFloat                     _scrollRefreshRange;
    BOOL                        _grid;
    CGSize                      _itemSize;
}
@property (nonatomic) BOOL          keepSelected;
@property (nonatomic) NSInteger     initialItem;
@property (nonatomic) NSInteger     page;
@property (nonatomic) NSInteger     pages;
@property (nonatomic) P2UXView*       currentView;
@property (nonatomic) NSString*     state;
@property (nonatomic) NSString*     dataState;
@property (nonatomic) P2UXCollectionView_SelectType selectType;
@property (nonatomic) NSInteger     visibleItems;
@property (nonatomic) NSInteger     visibleCols;
@property (nonatomic) BOOL          refreshing;

- (id) initAsListWithFrame:(CGRect)frame elemInst:(P2UXElementInstance*)elemInst uipath:(NSString*)path ext:(BOOL)ext handler:(id<P2UXActionDelegate>)handler viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate index:(id) index;

- (id) initAsGridWithFrame:(CGRect)frame elemInst:(P2UXElementInstance*)elemInst uipath:(NSString*)path ext:(BOOL)ext handler:(id<P2UXActionDelegate>)handler viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate index:(id) index;
- (void) handleReorderItem:(UILongPressGestureRecognizer*)recognizer;
- (UICollectionViewLayout*) layoutForContents;

@end
