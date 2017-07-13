//
//  P2UXMediaManager.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 8/28/15.
//  Copyright © 2015 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <P2UXCore/P2UXControl.h>
#import <P2UXCore/P2UXViewContainerDelegate.h>
#import <AssetsLibrary/AssetsLibrary.h>
@class P2UXEventAction;

typedef void (^P2UXMediaResultBlock)(UIImage* image);
typedef void (^P2UXMediaFailureBlock)(NSError* error);

@interface P2UXMediaManager : NSObject<P2UXControl, UIImagePickerControllerDelegate, UINavigationControllerDelegate>
@property (nonatomic, weak) UIViewController* controller;

+ (instancetype) instance;
+ (NSString*) assetURLFromLocalIdent:(NSString*)ident type:(NSString*)type;

- (BOOL) loadAssetLibraryImage:(NSString*)url size:(CGSize)size scale:(P2UXScaleType)scale result:(P2UXMediaResultBlock)resultBlock failure:(P2UXMediaFailureBlock)failureBlock;

- (void) selectMediaFromAction:(P2UXEventAction*)action viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate ;
- (void) cleanup;
- (void) setData:(NSDictionary*)data;
- (P2UXElementInstance*) elemInstance;
- (id) valueForAttribute:(NSString*)attribute;

@end
