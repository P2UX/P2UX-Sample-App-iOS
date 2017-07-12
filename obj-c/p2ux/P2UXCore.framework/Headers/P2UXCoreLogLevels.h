//
//  Header.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 9/10/15.
//  Copyright (c) 2015 Phase 2 Industries, LLC. All rights reserved.
//

#ifndef P2UXCoreLogLevels_h
#define P2UXCoreLogLevels_h


// Configure log levels.
typedef NS_OPTIONS(NSUInteger, P2UXCoreLogFlag) {
    P2UXCoreLogFlagError      = (1 << 0), // 0...00001
    P2UXCoreLogFlagWarning    = (1 << 1), // 0...00010
    P2UXCoreLogFlagInfo       = (1 << 2), // 0...00100
    P2UXCoreLogFlagDebug      = (1 << 3), // 0...01000
    P2UXCoreLogFlagVerbose    = (1 << 4)  // 0...10000
};

typedef NS_ENUM(NSUInteger, P2UXCoreLogLevel) {
    P2UXCoreLogLevelOff       = 0,
    P2UXCoreLogLevelError     = (P2UXCoreLogFlagError),                       // 0...00001
    P2UXCoreLogLevelWarning   = (P2UXCoreLogLevelError   | P2UXCoreLogFlagWarning), // 0...00011
    P2UXCoreLogLevelInfo      = (P2UXCoreLogLevelWarning | P2UXCoreLogFlagInfo),    // 0...00111
    P2UXCoreLogLevelDebug     = (P2UXCoreLogLevelInfo    | P2UXCoreLogFlagDebug),   // 0...01111
    P2UXCoreLogLevelVerbose   = (P2UXCoreLogLevelDebug   | P2UXCoreLogFlagVerbose), // 0...11111
    P2UXCoreLogLevelAll       = NSUIntegerMax                           // 1111....11111 (DDLogLevelVerbose plus any other flags)
};

#endif
