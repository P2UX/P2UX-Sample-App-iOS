//
//  P2UXTextInput.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 10/11/13.
//  Copyright (c) 2013 Phase 2 Industries, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <P2UXCore/P2UXElement.h>
#import <P2UXCore/P2UXControl.h>
#import <P2UXCore/P2UXActionDelegate.h>

@class P2UXElementInstance;

@interface P2UXTextInput : UITextField<P2UXControl, UITextFieldDelegate>
{
    id<P2UXActionDelegate>        _handler;
    CGFloat                     _cornerRadius;
    NSDictionary*               _background;
    
    UIColor*                    _borderColor;
    CGFloat                     _borderWidth;
    CGFloat                     _borderOpacity;

    NSString*                   _placeholderText;
    UIColor*                    _placeholderColor;
    
    BOOL                        _allCaps;
    CGSize                      _margins;
}
@property (nonatomic, readonly) BOOL isEditing;

- (id) initWithFrame:(CGRect)frame elemInst:(P2UXElementInstance*)elemInst uipath:(NSString*)path ext:(BOOL)ext handler:(id<P2UXActionDelegate>)handler  viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate index:(id)index;

#pragma mark - UITextFieldDelegate
- (BOOL) textFieldShouldReturn:(UITextField *)textField;
- (void) textFieldDidEndEditing:(UITextField *)textField;
- (void) textFieldDidBeginEditing:(UITextField *)textField;
@end
