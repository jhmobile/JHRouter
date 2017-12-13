//
//  JHRouteInterceptor.h
//  JHRouter
//
//  Created by mshqiu on 2017/12/13.
//

#import <Foundation/Foundation.h>

@class JHRouteContext;

@interface JHRouteInterceptor : NSObject

@property (nonatomic, weak, readonly) JHRouteContext *context;

@end
