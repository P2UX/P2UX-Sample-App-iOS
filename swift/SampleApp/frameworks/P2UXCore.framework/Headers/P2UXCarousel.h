//
//  P2UXCarousel.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 1/21/16.
//  Copyright © 2016 Phase 2 Industries, LLC. All rights reserved.
//

#import <P2UXCore/iCarousel.h>

#import <P2UXCore/P2UXActionDelegate.h>
#import <P2UXCore/P2UXBaseCtrl.h>
#import <P2UXCore/P2UXControl.h>
@class P2UXElementInstance, P2UXContainerElement;

@interface P2UXCarousel : iCarousel<iCarouselDelegate, iCarouselDataSource>
{
    P2UXContainerElement*         _elem;

}
@property (nonatomic) NSArray* data;
- (id)initWithFrame:(CGRect)frame elemInst:(P2UXElementInstance*)elemInst uipath:(NSString *)path ext:(BOOL)ext handler:(id<P2UXActionDelegate>)handler viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate index:(id)index;
@end
