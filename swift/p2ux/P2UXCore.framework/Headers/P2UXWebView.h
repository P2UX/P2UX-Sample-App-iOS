//
//  P2P2UXWebView.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 3/15/15.
//  Copyright (c) 2015 Phase 2 Industries, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <P2UXCore/P2UXElement.h>
#import <P2UXCore/P2UXControl.h>
#import <P2UXCore/P2UXViewContainerDelegate.h>

typedef NS_ENUM(NSInteger, P2UXWebViewSourceType) {
    P2UXWebViewSourceType_URL = 0,
    P2UXWebViewSourceType_Local,
    P2UXWebViewSourceType_Datasource
};

typedef NS_ENUM(NSInteger, P2UXWebViewCachePolicy) {
    P2UXWebViewCachePolicy_Protocol = 0,
    P2UXWebViewCachePolicy_NoCache,
    P2UXWebViewCachePolicy_UseCacheAlways
};

typedef NS_ENUM(NSInteger, P2UXWebViewState) {
    P2UXWebView_State_Empty = 0,
    P2UXWebView_State_Loading,
    P2UXWebView_State_Loaded,
    P2UXWebView_State_Failed
};

extern NSString* const P2P2UXWebView_Attrib_State;

@interface P2UXWebView : UIWebView<UIWebViewDelegate>
{
    P2UXWebViewSourceType _type;
    NSString*           _sourcePath;
    NSInteger           _statusCode;
    NSTimeInterval      _timeout;
    NSURLRequestCachePolicy _cachePolicy;
    P2UXWebViewState      _state;
}

- (id) initWithFrame:(CGRect)frame elemInst:(P2UXElementInstance*)elemInst uipath:(NSString*)path ext:(BOOL)ext viewDelegate:(id<P2UXViewContainerDelegate>)viewDelegate index:(NSString*)index;


@end
