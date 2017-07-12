//
//  P2UXScrollContainerContents.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 7/5/16.
//  Copyright © 2016 Phase 2 Industries, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
@class P2UXScrollContainer;

@interface P2UXScrollContainerContents : UIView
{
}
@property (nonatomic) UIView* lastControlHeight;
@property (nonatomic) UIView* lastControlWidth;
@property (nonatomic) CGSize measuredSize;

- (P2UXScrollContainer*) scrollContainer;
- (void) updateContents;
- (CGSize) measureContents;
@end
