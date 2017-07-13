#import "AppDelegate.h"
#import "SampleBehavior.h"

@interface AppDelegate ()

@end

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    // This is the key generated from Builder for the application. This needs to be provided
    // to the createApplicationWithKey method to intialize the P2UX rendering framework
    NSString* appKey = @"0006.f1027db06fb6a28b48dce4d1118941b21e5c99ad7dd5a55757435102a6fdc5d7"; //Adopt A Pet app
    NSDictionary* opts = @{P2UXAppCreator_Opt_Env: P2UXAppCreator_Opt_Env_Prototype, P2UXAppCreator_Opt_LogLevel:[NSNumber numberWithInteger:P2UXCoreLogLevelVerbose]};
    self.window = [P2UXAppCreator createApplicationWithKey:appKey opts:opts resources:nil delegate:self];
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
