//
//  P2UXAppOS.h
//  P2UXApp
//
//  Created by Stephen Schalkhauser on 11/11/15.
//  Copyright © 2015 Phase 2 Industries, LLC. All rights reserved.
//

#ifndef P2UXAppOS_h
#define P2UXAppOS_h

#if TARGET_OS_IOS
#define LOCAL_NOTIFICATION_SUPPORT
#define NOTIFICATION_SUPPORT
#define MAP_SUPPORT
#endif

#if TARGET_OS_IOS
#define NOTIFICATION_SUPPORT
#endif
//#define ORIG_SCROLLCONTAINER
#endif /* P2UXAppOS_h */
