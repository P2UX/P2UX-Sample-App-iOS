//
//  P2UXApp.h
//  P2UXApp
//
//  Created by Stephen Schalkhauser on 9/25/15.
//  Copyright © 2015 Phase 2 Industries, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for P2UXApp.
FOUNDATION_EXPORT double P2UXAppVersionNumber;

//! Project version string for P2UXApp.
FOUNDATION_EXPORT const unsigned char P2UXAppVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <P2UXApp/PublicHeader.h>

#import <P2UXCore/P2UXCore.h>
#import <P2UXApp/P2UXAppOS.h>
#import <P2UXApp/P2UXAppTypes.h>
#import <P2UXApp/P2UXAppLoader.h>
#import <P2UXApp/P2UXViewController.h>
#import <P2UXApp/P2UXScreen.h>
#import <P2UXApp/P2UXAppBehavior.h>
#import <P2UXApp/P2UXAppController.h>
#import <P2UXApp/P2UXAppDefinition.h>
#import <P2UXApp/P2UXAppUpdateContentManager.h>
#import <P2UXApp/P2UXAppLoadingViewController.h>
#import <P2UXApp/P2UXAppErrorViewController.h>
#import <P2UXApp/P2UXAppCreator.h>
#import <P2UXApp/P2UXPanelController.h>
#import <P2UXApp/P2UXNativeDialogHandler.h>
#import <P2UXApp/UIViewController+P2UXViewController.h>
#define NOTIFICATION_TOKEN @"NOTIFICATION_DEVICE_TOKEN"
#define NOTIFICATION_PAYLOAD @"NOTIFICATION_PAYLOAD_DATA"
#define NotificationToken_Key @"DeviceToken"

