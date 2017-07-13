//
//  P2UXSettings.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 12/3/12.
//  Copyright (c) 2014 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#define Setting_Vehicle @"setting_vehicle"
#define Setting_Vehicle_Country @"setting_vehicle_country"

#define P2UXDefault_Setting_Vehicle @"chevy"
#define P2UXDefault_Setting_Vehicle_Country @"United States"

#define Setting_Username @"uname"
#define Setting_Password @"pwd"
#define Setting_AutoLogin @"setting_auto_login"
#define Setting_RemeberUser @"setting_remember_user"
#define Setting_ShowFirstHelp @"setting_first_help"

@interface P2UXSettings : NSObject
+ (void) setSettingString:(NSString*)value forKey:(NSString*)key;
+ (void) setSettingBOOL:(BOOL)value forKey:(NSString*)key;
+ (NSString*) settingStringForKey:(NSString*)key default:(NSString*)defValue;
+ (BOOL) settingBOOLForKey:(NSString*)key default:(BOOL)defValue;

@end
