//
//  P2UXLocationManagerDelegate.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 11/11/15.
//  Copyright © 2015 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol P2UXLocationManagerDelegate <NSObject>
- (void) locationComplete:(NSString*) request placemark:(id)placemark;
@end
