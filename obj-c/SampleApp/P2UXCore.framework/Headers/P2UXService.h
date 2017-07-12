//
//  P2UXService.h
//  P2UXCore
//
//  Created by Stephen Schalkhauser on 12/27/12.
//
//

#ifndef P2UX_Service_h
#define P2UX_Service_h

#define CONTENT_SERVICE_LIVE @"https://builder.p2ux.com/"
#define CONTENT_SERVICE_DEV @"https://beta.p2ux.com/"
#define CONTENT_SERVICE_STAGE @"https://beta.p2ux.com/"

#define DEFAULT_ANON_USER @"anonuser"
#define DEFAULT_ANON_PWD @"anonuser.infoX"

#define CLOUDLINK_LIVE_SERVER @"cloud.phase2i.com"
#define CLOUDLINK_TEST_SERVER @"cloud.phase2i.com"
#define CLOUDLINK_LIVE_PORT 80
#define CLOUDLINK_TEST_PORT 8080
#define CONTENT_VIN_GENERATOR @"https://sfs.oboservices.mobi/json/api/vin?"

#define CONTENT_SERVICE_LOGIN @"login/app"
#define CONTENT_SERVICE_KEYLOGIN @"login/key"
#define CONTENT_SERVICE_VEHICLES @"build/vehicles"
#define CONTENT_SERVICE_DISPLAY @"build/display/%@"
#define CONTENT_SERVICE_THEME @"build/theme/%@"
#define CONTENT_SERVICE_TRANSMISSION @"build/transmission/%@"
#define CONTENT_SERVICE_ASSET @"asset/%@"
#define CONTENT_SERVICE_HMI @"build/hmi/%@"
#define CONTENT_SERVICE_VEHICLE @"build/vehicle/%@"
#define CONTENT_SERVICE_THEME_DOWNLOAD @"download/theme/%@/%@"
#define CONTENT_SERVICE_SIMULATOR @"build/simulator/%@"
#define CONTENT_SERVICE_MOBILEAPP @"build/%@"
#define CONTENT_SERVICE_LICENSE @"licenses/"
#endif
