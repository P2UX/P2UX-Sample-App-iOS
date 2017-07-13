//
//  P2UXBaseCtrl.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 2/1/13.
//
//

#import <UIKit/UIKit.h>

@interface P2UXBaseCtrl : UIControl
{
    BOOL       _showSelected;
    BOOL       _showHighlighted;
}
@property (nonatomic) BOOL showSelected;
@property (nonatomic) BOOL keepSelected;
@property (nonatomic) BOOL showHighlighted;

- (void) clear;

- (BOOL) selectNext;
- (BOOL) selectPrev;
- (void) selectLast;
- (void) selectFirst;
- (BOOL) highlightNext;
- (BOOL) highlightPrev;
- (void) highlightFirst;
- (void) highlightLast;
- (void) unselect;
- (void) clickSelected;
- (void) clickHighlighted;

- (void) setLinkCtrl:(id)ctrl;
@end
