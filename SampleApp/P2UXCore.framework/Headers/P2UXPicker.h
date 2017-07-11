//
//  P2UXPicker.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 10/12/16.
//  Copyright © 2016 Phase 2 Industries, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface P2UXPicker : UIPickerView<UIPickerViewDelegate, UIPickerViewDataSource>
{
    NSMutableArray* _dataComponents;  // data for picker
    NSMutableArray* _dataSelection;
    UIFont*         _itemFont;
    UIColor*        _textColor;
    CGFloat         _itemSize;
}

- (id) initWithFrame:(CGRect)frame elemInst:(P2UXElementInstance *)elemInst uipath:(NSString *)path ext:(BOOL)ext viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate index:(id)index;
- (void) processData:(NSArray*)data;

#pragma mark - UIPickerViewDelegate


@end
