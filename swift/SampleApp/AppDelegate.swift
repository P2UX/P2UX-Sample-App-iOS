//
//  AppDelegate.swift
//  SampleApp
//
//  Copyright © 2017 P2UX, Inc. All rights reserved.
//

import UIKit
import P2UXApp

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate, P2UXAppCreatorDelegate {

    var window: UIWindow?


    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
        
        // Override point for customization after application launch.
        // This is the key generated from Builder for the application. This needs to be provided
        // to the createApplicationWithKey method to intialize the P2UX rendering framework
        let appKey = "0006.f058b95ac4e851b47424d19ff2cd4bf69ec70383187cb5fd0b02a2978f08d13e";
        // The createApplication method takes options which let you set how PUB resources are found and updated
        // as well as options for logging and whether or not you are testing against a "prototype" or "production"
        // version of your application PUB.

        var opts : [AnyHashable : Any];
        //If you would like to set your own resources, uncomment the following lines:
        //var resources : [Any]?;
        //var phoneResources: [AnyHashable : Any];

        opts = [
            P2UXAppCreator_Opt_Env: P2UXAppCreator_Opt_Env_Production,
            P2UXAppCreator_Opt_LogLevel: P2UXCoreLogLevel.verbose.rawValue as NSNumber
        ]
        
        //If you would like to set your own resources, edit these lines:
        /*phoneResources = [
            P2UXApp_PackageAttrib_FormFactor: 0,
            P2UXApp_PackageAttrib_Type: P2UXApp_PackageType_Static,
            P2UXApp_PackageAttrib_Package: "shellui_phone",
            P2UXApp_PackageAttrib_Update: P2UXApp_PackageUpdate_None
        ]
        
        resources = [
            phoneResources
        ]*/

        //Then change "resources" from "nil" to "resources" in the following line.
        self.window = P2UXAppCreator.createApplication(withKey: appKey, opts: opts, resources: nil, delegate: self)
        return true
    }

    func applicationWillResignActive(_ application: UIApplication) {
        // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
        // Use this method to pause ongoing tasks, disable timers, and invalidate graphics rendering callbacks. Games should use this method to pause the game.
    }

    func applicationDidEnterBackground(_ application: UIApplication) {
        // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
        // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
    }

    func applicationWillEnterForeground(_ application: UIApplication) {
        // Called as part of the transition from the background to the active state; here you can undo many of the changes made on entering the background.
    }

    func applicationDidBecomeActive(_ application: UIApplication) {
        // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
    }

    func applicationWillTerminate(_ application: UIApplication) {
        // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
    }

    // This is the method from P2UXAppCreatorDelegate
    // Here you can return an instance of your custom P2UXAppBehavior subclass, from the behavior
    // You can begin to override other parts of the application creation process
    func createBehavior(forApplication appid: String) -> P2UXAppBehavior {
        return SampleBehavior();
    }
}

