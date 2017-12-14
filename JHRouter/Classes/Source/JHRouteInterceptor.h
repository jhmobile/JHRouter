//
//  JHRouteInterceptor.h
//  JHRouter
//
//  Created by mshqiu on 2017/12/13.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, RouteInterceptionState) {
    RouteInterceptionStateUnverified,   // 未通过
    RouteInterceptionStateVerified,     // 通过
    RouteInterceptionStatePending       // 审核中
};

@class JHRouteContext;

@interface JHRouteInterceptor : NSObject

@property (nonatomic, weak) JHRouteContext *context;

@end
