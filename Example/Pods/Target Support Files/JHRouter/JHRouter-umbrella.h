#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "JHRouteInterceptor.h"
#import "JHRouter.h"

FOUNDATION_EXPORT double JHRouterVersionNumber;
FOUNDATION_EXPORT const unsigned char JHRouterVersionString[];

