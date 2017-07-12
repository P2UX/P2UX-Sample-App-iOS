//
//  P2UXPageIndicator.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 1/31/13.
//  Copyright (c) 2014 Phase 2 Industries, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <P2UXCore/P2UXVarLink.h>
@class P2UXElementInstance;
@class P2UXElement;

@interface P2UXPageIndicator : UIControl
{
    UIImage*            _imageFull;
    UIImage*            _imageEmpty;
    CGSize              _imageSize;
    NSMutableArray*     _images;
    NSInteger           _offset;
    NSInteger           _indicatorType;         // vertical: 0. horizontal: 1
    NSString*           _ctrlLinkId;
}
@property (nonatomic) NSInteger pageCount;
@property (nonatomic) NSInteger currentPage;

- (id)initWithFrame:(CGRect)frame elemInst:(P2UXElementInstance*)elemInst uipath:(NSString*)path ext:(BOOL)ext viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate index:(id)index;
- (void) cleanup;
- (void) updateFromLayout;

#pragma mark - ctrllink interface
- (NSString*) ctrlLinkId;
@end
