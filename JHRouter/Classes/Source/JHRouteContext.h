//
//  JHRouteContext.h
//  JHRouter
//
//  Created by mshqiu on 2017/12/13.
//

#import "JHRouter.h"

@class JHRouteInterceptor;

/*
 context 如何创建？
 持有一组拦截器interceptor,拦截器interceptor反向持有一个context,知道自己归属。
 context之间有child、parent关系，有add、remove动作。
 context应该有状态：等待中、进行中、已结束。
 router持有一个根context，所有进来的URL都被转换成一个context。
 next()如何区分当前拦截器，用index
 task? 不管是controller还是block都可以用task抽象？or task专用于controller的呈现
 拦截器打开的页面如何回调interceptor?在router的completion回调里面找到当前展示的页面，set一个拦截器回调。
 拦截器中断，根context如何回调？context暴露对应方法来供拦截器调用。
 context构造方法不想参数多，要引入routeRequest，最终要引入链式调用来解决这个问题。
 */

typedef NS_ENUM(NSUInteger, RouteContextState) {
    RouteContextStateWaiting,   // 等待中
    RouteContextStateUnderway,  // 进行中
    RouteContextStateFinished   // 已结束
};

@interface JHRouteContext : NSObject

@property (nonatomic, readonly) RouteType type;
@property (nonatomic, readonly) RouteContextState state;

@property (nonatomic, weak, readonly) JHRouteContext *parentContext;
@property (nonatomic, strong, readonly) NSArray<JHRouteContext *> *childContexts;

@property (nonatomic, readonly) JHRouteContext *rootContext;
@property (nonatomic, readonly) JHRouteContext *activeChildContext;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithURL:(NSString *)URL
                     config:(NSDictionary *)config
                  forcePush:(BOOL)push
               forcePresent:(BOOL)present
               wrappedClass:(Class)navigationControllerClass
                   userInfo:(NSDictionary *)userInfo
                 completion:(RouteCompletionCallback)block;

- (void)next;
- (void)interceptionInterrupted;

- (void)addChildContext:(JHRouteContext *)context;
- (void)removeFromParentContext;

@end
