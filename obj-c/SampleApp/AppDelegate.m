//
//  AppDelegate.m
//  SampleApp
//
//  Copyright © 2017 P2UX, Inc. All rights reserved.
//


#import "AppDelegate.h"
#import "SampleBehavior.h"

@interface AppDelegate ()

@end

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    // This is the key generated from Builder for the application. This needs to be provided
    // to the createApplicationWithKey method to intialize the P2UX rendering framework
    NSString* appKey = @"0006.f058b95ac4e851b47424d19ff2cd4bf69ec70383187cb5fd0b02a2978f08d13e"; //Adopt A Pet app
    NSDictionary* opts = @{P2UXAppCreator_Opt_Env: P2UXAppCreator_Opt_Env_Prototype, P2UXAppCreator_Opt_LogLevel:[NSNumber numberWithInteger:P2UXCoreLogLevelVerbose]};
    
    //If you would like to set your own resources, edit this line:
    //_resources = @[@{P2UXApp_PackageAttrib_FormFactor:@0, P2UXApp_PackageAttrib_Type:P2UXApp_PackageType_Static, P2UXApp_PackageAttrib_Package:@"shellui_phone",P2UXApp_PackageAttrib_Update:P2UXApp_PackageUpdate_None}];
    //Then change "resources" from "nil" to "resources" in the following line.
    
    [P2UXAppCreator createApplicationWithKey:appKey opts:opts resources:nil delegate:self];
    return YES;
}

// This is the method from P2UXAppCreatorDelegate
// Here you can return an instance of your custom P2UXAppBehavior subclass, from the behavior
// You can begin to override other parts of the application creation process
- (P2UXAppBehavior*) createBehaviorForApplication:(NSString *)appid
{
    return [[SampleBehavior alloc] init];
}

@end
