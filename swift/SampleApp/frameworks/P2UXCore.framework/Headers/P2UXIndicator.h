//
//  P2UXIndicator.h
//  Ref P2UX
//
//  Created by Stephen Schalkhauser on 4/29/13.
//
//

#import <UIKit/UIKit.h>

@interface P2UXIndicator : UIView
{
    BOOL _display;
}
@property (nonatomic) float rate;
@property (nonatomic) float delay;
- (void) display;
- (void) stop;
@end
