//
//  P2UXCoreComponents.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 9/4/13.
//  Copyright (c) 2013 Phase 2 Industries, LLC. All rights reserved.
//

#ifndef P2UXCore_UXCoreComponents_h
#define P2UXCore_UXCoreComponents_h

#import <P2UXCore/P2UXBehavior.h>
#import <P2UXCore/P2UXElement.h>
#import <P2UXCore/P2UXBtnGrpElement.h>
#import <P2UXCore/P2UXContainerElement.h>
#import <P2UXCore/P2UXGroupElement.h>
#import <P2UXCore/P2UXCoordinate.h>
#import <P2UXCore/P2UXElementInstance.h>
#import <P2UXCore/P2UXGroupElementInstance.h>
#import <P2UXCore/P2UXEvent.h>
#import <P2UXCore/P2UXEventAction.h>
#import <P2UXCore/P2UXEventHandler.h>
#import <P2UXCore/P2UXEventTransition.h>
#import <P2UXCore/P2UXMacroManager.h>
#import <P2UXCore/P2UXState.h>
#import <P2UXCore/P2UXFontManager.h>
#import <P2UXCore/P2UXElementFactory.h>
#import <P2UXCore/P2UXPaletteManager.h>
#import <P2UXCore/P2UXOrientation.h>
#import <P2UXCore/P2UXDefinition.h>
#import <P2UXCore/P2UXScreenState.h>
#import <P2UXCore/P2UXScreenOrientation.h>
#import <P2UXCore/P2UXScreenNavigation.h>

#pragma mark - Analytics
#import <P2UXCore/P2UXAnalytics.h>
#import <P2UXCore/P2UXAnalyticsManager.h>

#pragma mark - Data Source
#import <P2UXCore/P2UXBasicDataAuth.h>
#import <P2UXCore/P2UXDataAuthSubclass.h>
#import <P2UXCore/P2UXCachedData.h>
#import <P2UXCore/P2UXDataAuth.h>
#import <P2UXCore/P2UXDataManager.h>
#import <P2UXCore/P2UXDataSchema.h>
#import <P2UXCore/P2UXDataSource.h>
#import <P2UXCore/P2UXRestDataSource.h>
#import <P2UXCore/P2UXSourcedData.h>
#import <P2UXCore/P2UXStaticDataSource.h>
#import <P2UXCore/P2UXLocalDataSource.h>
#import <P2UXCore/P2UXDataIndex.h>
#import <P2UXCore/P2UXVarLink.h>
#import <P2UXCore/P2UXVarLinks.h>
#import <P2UXCore/P2UXVarLinkFactory.h>
#import <P2UXCore/P2UXDataBatchRequest.h>
#import <P2UXCore/P2UXVarDelegate.h>
#import <P2UXCore/P2UXJWSDataAuth.h>
#import <P2UXCore/P2UXLoginDataAuth.h>
#import <P2UXCore/P2UXOAuthDataAuth.h>
#import <P2UXCore/P2UXOAuthDataAuthSubclass.h>
#import <P2UXCore/P2UXCoreDataVars.h>
#import <P2UXCore/P2UXDataSourceFilter.h>
#ifdef MAP_SUPPORT
#import <P2UXCore/P2UXLocationManager.h>
#endif

#pragma mark - Multimedia
#ifdef MEDIA_SUPPORT
#import <P2UXCore/P2UXMediaManager.h>
#import <P2UXCore/P2UXAudioMediaManager.h>
#endif

#endif
