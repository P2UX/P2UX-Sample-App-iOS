//
//  P2UXLabel.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 11/14/12.
//
//

#import <P2UXCore/P2UXControl.h>
#import <P2UXCore/P2UXVarLink.h>
#import <P2UXCore/P2UXLocationManagerDelegate.h>

@class P2UXElement;
@class P2UXIndicator;
@class P2UXElementInstance;

extern NSString* const P2UXLabel_Attrib_Truncation;
extern NSString* const P2UXLabel_Truncation_None;

@interface P2UXLabel : UILabel<P2UXControl, P2UXLocationManagerDelegate>
{
    P2UXIndicator*                _editIndicator;
    CGSize                      _textSize;
    float                       _offset;
    CGSize                      _originalSize;
    BOOL                        _allCaps;
    NSString*                   _vAlign;
    CGSize                      _modifiedSize;
}
@property (nonatomic) BOOL pulsing;

- (id) initWithFrame:(CGRect)frame elemInst:(P2UXElementInstance*)elemInst uipath:(NSString*)path ext:(BOOL)ext viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate index:(id)index;
- (void) updateFromState;
- (void) setEmptyText;
- (void) setText:(NSString *)text;
- (void) setLabelColor:(NSString*)labelColor;

- (BOOL) setAttribute:(id)value withName:(NSString*)name relative:(BOOL)relative animated:(id)animated itemspec:(NSDictionary *)itemspec;

#pragma mark - P2UXControl
- (void) cleanup;
- (void) setData:(NSDictionary *)data;

- (void) setFontWithName:(NSString *)font;

#pragma mark - P2UXLocationManagerDelegate
- (void) locationComplete:(NSString *)request placemark:(id)placemark;
@end
