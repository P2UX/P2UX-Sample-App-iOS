//
//  P2UXNativeDialogHandler.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 3/12/15.
//  Copyright (c) 2015 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <P2UXCore/P2UXViewContainerDelegate.h>
@class P2UXEventAction;
@class P2UXAlertController;

@protocol P2UXNativeDialogHandlerDelegate <NSObject>
- (void) dialogComplete:(NSInteger)btnClicked ident:(NSString*)ident;
@end

@interface P2UXNativeDialogHandler : NSObject
{
    P2UXAlertController*      _alert;
    P2UXEventAction*          _action;
    NSMutableDictionary*    _btnActionMap;
    BOOL                    _animated;
    NSString*               _ident;
}
@property (nonatomic) id<P2UXNativeDialogHandlerDelegate> delegate;
@property (nonatomic, weak) id<P2UXViewContainerDelegate> viewDelegate;

+ (instancetype) instance;
- (void) showDialogFromAction:(P2UXEventAction*)action viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;
- (void) showDialogWithId:(NSString*)ident withData:(NSDictionary*)data viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;
- (void) showDialogWithSpec:(NSDictionary*)spec withData:(NSDictionary*)data viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate;
@end
