//
//  JHRouteContext.h
//  JHRouter
//
//  Created by mshqiu on 2017/12/13.
//

#import <Foundation/Foundation.h>

@class JHRouteInterceptor;

@interface JHRouteContext : NSObject

@property (nonatomic, strong) NSArray *interceptors;

@property (nonatomic, readonly) JHRouteContext *parentContext;
@property (nonatomic, strong) NSArray<JHRouteContext *> *childContexts;

- (void)addChildContext:(JHRouteContext *)context;
- (void)removeFromParentContext;

@end
