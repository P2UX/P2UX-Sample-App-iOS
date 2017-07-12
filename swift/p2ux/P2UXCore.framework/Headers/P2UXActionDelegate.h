//
//  P2UXActionDelegate.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 11/15/12.
//
//

#import <Foundation/Foundation.h>

@class P2UXElementInstance, P2UXView;

@protocol P2UXActionDelegate <NSObject,UIGestureRecognizerDelegate>

- (BOOL) handleButtonClick:(id)sender;
@optional
- (BOOL) handleButtonToggle:(id)sender;
- (BOOL) handleButtonRadio:(id)sender;
- (BOOL) handleButtonRadioState:(id)sender;
- (BOOL) handleButtonLongPress:(id)sender;
- (BOOL) handleRotaryChange:(id)sender;
- (BOOL) handleButtonSelectorClick:(id)sender;
- (BOOL) handleRotaryIncrement:(id)sender;
- (BOOL) handleSlideIncrement:(id)sender;
- (BOOL) handleLabelToggle:(id)sender;
- (BOOL) handleSwipe:(id)sender direction:(NSString*)direction;
- (BOOL) handlePan:(id)sender element:(P2UXElementInstance*)element events:(NSArray*)events recognizer:(UIPanGestureRecognizer*)recognizer;
- (BOOL) handleTap:(id)sender element:(P2UXElementInstance*)element events:(NSArray*)events;
- (BOOL) handleKeyboardReturn:(id)sender;
- (BOOL) handleOnMessage:(NSString*)msg data:(id)data sender:(id)sender;
- (BOOL) handleOnStateChange:(NSString*)layoutName;
- (BOOL) viewStateWillChange:(NSString*)layout;
- (void) viewStateDidChange:(NSString*)layout;
- (void) handleTextBeginEditing:(id)sender;
- (void) handleTextEndEditing:(id)sender;
- (void) handleTextChange:(id)sender;
- (void) registerPanGesture:(UIPanGestureRecognizer*)gesture direction:(NSInteger)direction;
- (P2UXView*) parentContainer;
- (UIView*) controlWithElementSystemTypeOrId:(NSString*)elId;
@end
