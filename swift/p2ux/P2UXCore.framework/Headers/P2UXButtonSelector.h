//
//  P2UXButtonSelector.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 11/15/12.
//  Copyright (c) 2013 Phase 2 Industries, LLC. All rights reserved.
//

#import "P2UXButton.h"
#import "P2UXSelectorController.h"

@interface P2UXButtonSelector : P2UXButton<P2UXSelectorDelegate, UIPopoverPresentationControllerDelegate>
{
    NSArray* _items;
    NSDictionary* _selectedItem;
    NSString* _selectedValue;
    NSMutableDictionary* _itemImages;
}
@property (nonatomic, readonly) NSString* selectedValue;
-(id) initWithFrame:(CGRect)frame elemInst:(P2UXElementInstance*)elemInst uipath:(NSString*)path ext:(BOOL)ext handler:(id<P2UXActionDelegate>)handler viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate index:(id) index;

#pragma mark - P2UXSelectorDelegate
-(void) itemSelected:(NSDictionary*)item;
@end
