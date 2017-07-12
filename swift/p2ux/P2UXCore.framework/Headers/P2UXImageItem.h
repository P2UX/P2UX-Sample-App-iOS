//
//  P2UXImageItem.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 8/4/14.
//  Copyright (c) 2014 Phase 2 Industries, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface P2UXImageItem : NSObject
{
    NSInteger   _ref;
}
@property (nonatomic, readonly) OSImageClass* image;
@property (nonatomic, readonly) NSInteger ref;
- (id) initWithImage:(OSImageClass*)img;
- (void) inc;
- (NSInteger) dec;
- (void) releaseAll;
@end
