//
//  P2UXBehavior.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 12/5/12.
//  Copyright (c) 2013 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <P2UXCore/P2UXView.h>
#import <P2UXCore/P2UXActionDelegate.h>
#import <P2UXCore/P2UXHelperDelegate.h>

@class P2UXDataSource;

@protocol P2UXNativeDialogHandlerDelegate;

@interface P2UXBehavior : NSObject<P2UXViewInteractionDelegate, P2UXHelperDelegate>
{
    NSMutableDictionary*    _dataStore;
}
@property (nonatomic, weak) P2UXView* currentView;
@property (nonatomic) NSMutableDictionary* overlays;
@property (nonatomic) NSMutableDictionary* hotkeyMap;
@property (nonatomic, weak) id<P2UXViewContainerDelegate> viewDelegate;
@property (nonatomic, copy) NSString* path;
@property (nonatomic) BOOL external;

- (void) cleanup;
- (void) uninitialize;
- (BOOL) isModal;
- (void) handleNativeFocusChange:(NSString*)type;
- (void) shutdown;
- (void) cacheState:(BOOL)shutdown;
- (void) restoreState;

- (id)   dataValueForKey:(NSString*)key;
- (void) setDataValue:(id)value forKey:(NSString*)key;

- (void) setHotkeys:(NSDictionary*)hotkeys;

#pragma mark - Data Source methods
- (P2UXDataSource*) createDataSourceWithId:(NSString*)sourceId type:(NSString*)sourceType andSpec:(NSDictionary*)dataSourceSpec;

#pragma mark - P2UXHelperControl methods
- (OSViewClass*) createControlWithType:(NSString*)type elementInstance:(P2UXElementInstance*)elementInstance frame:(CGRect)frame viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate index:(id)index data:(id)data parent:(UIView*)parent;

#pragma mark - Button Event Handlers
- (BOOL) handleButtonClick:(id)sender element:(P2UXElementInstance *)element;
- (BOOL) handleButtonToggle:(id)sender element:(P2UXElementInstance *)element;
- (BOOL) handleButtonRadio:(id)sender element:(P2UXElementInstance*)element;
- (BOOL) handleButtonLongPress:(id)sender element:(P2UXElementInstance*)element;
- (BOOL) handleSlideIncrement:(id)sender element:(P2UXElementInstance*)element;
- (void) handleExternalKeyboardKeyPress:(NSString*)text;
- (BOOL) handleKeyboardReturn:(id)sender element:(P2UXElementInstance*)element;
- (BOOL) handleRotaryChange:(id)sender element:(P2UXElementInstance*)element;
- (BOOL) handleRotaryIncrement:(id)sender element:(P2UXElementInstance*)element inc:(BOOL)inc;

#pragma mark - P2UXViewInteractionDelegate
- (void) pageChange:(NSInteger)page pages:(NSInteger)pages;

@end
