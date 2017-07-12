//
//  NSArray+P2UX.h
//  P2UX
//
//  Created by Stephen Schalkhauser on 5/3/13.
//
//

#import <Foundation/Foundation.h>

@interface NSArray (P2UX)
- (NSMutableArray*) deepMutableCopy;
- (NSArray*) shuffled;
@end
