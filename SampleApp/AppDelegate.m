#import "AppDelegate.h"
#import "SampleBehavior.h"

@interface AppDelegate ()

@end

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    NSString* appKey;
    appKey = @"0006.f058b95ac4e851b47424d19ff2cd4bf69ec70383187cb5fd0b02a2978f08d13e"; //Adopt A Pet app
    NSDictionary* opts = @{AppCreator_Opt_Env: AppCreator_Opt_Env_Stage, AppCreator_Opt_LogLevel:[NSNumber numberWithInteger:P2UXCoreLogLevelVerbose]};
    self.window = [P2UXAppCreator createApplicationWithKey:appKey opts:opts resources:nil delegate:self];
    return YES;
}

- (P2UXAppBehavior*) createBehaviorForApplication:(NSString *)appid
{
    return [[SampleBehavior alloc] init];
}

@end
