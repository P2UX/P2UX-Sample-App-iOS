//
//  P2UXNetworkManager.h
//  P2UXCore
//
//  Created by Steve Ansell on 2/14/13.
//  Copyright (c) 2014 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

@class P2UXImageDownloader;

@interface P2UXNetworkManager : NSObject

+ (P2UXNetworkManager*) sharedManager;
+ (P2UXImageDownloader*) sharedImageDownloader;

-(NSArray *) getDevices;
-(BOOL) removeDevice:(NSString *)deviceAddress;
-(void) setConnectedDevice:(NSNumber *)handle andType:(NSNumber *)type;
-(BOOL) isReachable;
-(BOOL) isReachableViaWifi;
@end
