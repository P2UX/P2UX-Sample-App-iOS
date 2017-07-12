//
//  P2UXCoreLogging.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 9/10/15.
//  Copyright (c) 2015 Phase 2 Industries, LLC. All rights reserved.
//

#ifndef P2UXCore_P2UXCoreLogging_h
#define P2UXCore_P2UXCoreLogging_h

#ifndef DD_LEGACY_MACROS
#define DD_LEGACY_MACROS 0
#endif

#import <P2UXCore/DDLog.h>
#import <P2UXCore/P2UXCoreLogLevels.h>
extern NSInteger gP2UXCoreLogLevel;

// Define logging context for every log message coming from the XMPP framework.
// The logging context can be extracted from the DDLogMessage from within the logging framework.
// This gives loggers, formatters, and filters the ability to optionally process them differently.

#define P2UXCORE_LOG_CONTEXT 9313

/**
 * The constant/variable/method responsible for controlling the current log level.
 **/
#ifndef P2UXCORE_LOG_LEVEL_DEF
#define P2UXCORE_LOG_LEVEL_DEF gP2UXCoreLogLevel
#endif

/**
 * Whether async should be used by log messages, excluding error messages that are always sent sync.
 **/
#ifndef P2UXCORE_LOG_ASYNC_ENABLED
#define P2UXCORE_LOG_ASYNC_ENABLED YES
#endif

/**
 * This is the single macro that all other macros below compile into.
 * This big multiline macro makes all the other macros easier to read.
 **/
#define P2UXCORE_LOG_MACRO(isAsynchronous, lvl, flg, ctx, atag, fnct, frmt, ...) \
[DDLog log : isAsynchronous                                     \
level : lvl                                                \
flag : flg                                                \
context : ctx                                                \
file : __FILE__                                           \
function : fnct                                               \
line : __LINE__                                           \
tag : atag                                               \
format : (frmt), ## __VA_ARGS__]

/**
 * Define version of the macro that only execute if the log level is above the threshold.
 * The compiled versions essentially look like this:
 *
 * if (logFlagForThisLogMsg & ddLogLevel) { execute log message }
 *
 * When LOG_LEVEL_DEF is defined as ddLogLevel.
 *
 * As shown further below, Lumberjack actually uses a bitmask as opposed to primitive log levels.
 * This allows for a great amount of flexibility and some pretty advanced fine grained logging techniques.
 *
 * Note that when compiler optimizations are enabled (as they are for your release builds),
 * the log messages above your logging threshold will automatically be compiled out.
 *
 * (If the compiler sees LOG_LEVEL_DEF/ddLogLevel declared as a constant, the compiler simply checks to see
 *  if the 'if' statement would execute, and if not it strips it from the binary.)
 *
 * We also define shorthand versions for asynchronous and synchronous logging.
 **/
#define P2UXCORE_LOG_MAYBE(async, lvl, flg, ctx, tag, fnct, frmt, ...) \
do { if(lvl & flg) P2UXCORE_LOG_MACRO(async, lvl, flg, ctx, tag, fnct, frmt, ##__VA_ARGS__); } while(0)

/**
 * Ready to use log macros with no context or tag.
 **/
#define P2UXCoreLogError(frmt, ...)   P2UXCORE_LOG_MAYBE(NO,                P2UXCORE_LOG_LEVEL_DEF, (DDLogFlag)P2UXCoreLogFlagError,   0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define P2UXCoreLogWarn(frmt, ...)    P2UXCORE_LOG_MAYBE(P2UXCORE_LOG_ASYNC_ENABLED, P2UXCORE_LOG_LEVEL_DEF, (DDLogFlag)P2UXCoreLogFlagWarning, 0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define P2UXCoreLogInfo(frmt, ...)    P2UXCORE_LOG_MAYBE(P2UXCORE_LOG_ASYNC_ENABLED, P2UXCORE_LOG_LEVEL_DEF, (DDLogFlag)P2UXCoreLogFlagInfo,    0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define P2UXCoreLogDebug(frmt, ...)   P2UXCORE_LOG_MAYBE(P2UXCORE_LOG_ASYNC_ENABLED, P2UXCORE_LOG_LEVEL_DEF, (DDLogFlag)P2UXCoreLogFlagDebug,   0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define P2UXCoreLogVerbose(frmt, ...) P2UXCORE_LOG_MAYBE(P2UXCORE_LOG_ASYNC_ENABLED, P2UXCORE_LOG_LEVEL_DEF, (DDLogFlag)P2UXCoreLogFlagVerbose, 0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)


#endif
