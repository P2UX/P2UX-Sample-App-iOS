//
//  P2UXSelectorController.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 8/27/12.
//  Copyright (c) 2013 Phase 2 Industries, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol P2UXSelectorDelegate <NSObject>
-(void) itemSelected:(NSDictionary*)item;
@end

@interface P2UXSelectorController : UITableViewController{    
    NSArray* _items;
    NSDictionary* _itemImages;
    id<P2UXSelectorDelegate> _delegate;
    NSString *_currentLocaleID;
}
@property (nonatomic) NSArray* items;
@property (nonatomic) id<P2UXSelectorDelegate> delegate;

- (id)initWithStyle:(UITableViewStyle)style items:(NSArray*)items images:(NSDictionary*)images;

@end
