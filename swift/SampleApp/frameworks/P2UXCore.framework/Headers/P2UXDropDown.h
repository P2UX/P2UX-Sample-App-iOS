//
//  P2UXDropDown.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 6/21/13.
//  Copyright (c) 2013 Phase 2 Industries, LLC. All rights reserved.
//

#import <P2UXCore/P2UXButton.h>

@class P2UXList;

@interface P2UXDropDown : P2UXButton<P2UXActionDelegate>
{
    NSDictionary*       _dropdownspec;
    UIView*             _dropdown;
    P2UXList*             _content;
    UIView*             _touchLayer;
    UITapGestureRecognizer* _tap;
    NSInteger           _yoffset;
}
- (id)initWithFrame:(CGRect)frame elemInst:(P2UXElementInstance*)elemInst uipath:(NSString *)path handler:(id<P2UXActionDelegate>)handler ext:(BOOL)ext viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate index:(id)index;

- (void) handleButtonClick:(id)sender;
- (NSDictionary*) dataForItemWithTag:(NSInteger)tag;
@end
