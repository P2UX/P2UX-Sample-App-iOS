//
//  NSURLComponents+P2UXURLComponents.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 3/28/17.
//  Copyright © 2017 P2UX, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSURLComponents (P2UXURL)
- (NSString *)queryItemForKey:(NSString *)key;
@end
