//
//  NSData+P2UX.h
//  P2UXCore
//
//  Created by Steve Ansell on 9/24/14.
//  Copyright (c) 2014 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

#define DEFAULT_JWT_ALG @"HS256"

@interface NSData (P2UX)

#pragma mark - String Conversion
+ (NSData*)jwtEncode:(NSDictionary*)body withKey:(NSString*)key;
+ (NSData*)jwtDecode:(NSData*)data withKey:(NSString*)key;
- (NSData *)AES256EncryptWithKey:(NSString *)key;
- (NSData *)AES256DecryptWithKey:(NSString *)key;
- (NSString *)hexadecimalString;
+ (NSData *)dataFromHexidecimalString:(NSString*)hexidecimalString;

@end
