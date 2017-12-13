//
//  JHRouter.m
//  Pods
//
//  Created by mshqiu on 2017/12/13.
//

#import "JHRouter.h"

@interface JHRouter ()

@property (nonatomic, copy)     NSString *URL;
@property (nonatomic, strong)   NSDictionary *userInfo;

@property (nonatomic, copy)     Class taskClass;

@property (nonatomic, assign)   BOOL forcePresent;
@property (nonatomic, copy)     Class navigationControllerClass;

@property (nonatomic, assign)   BOOL forcePush;
@property (nonatomic, weak)     UINavigationController *navigationController;

@property (nonatomic, weak, readonly) JHRouter *parentRouter;
@property (nonatomic, strong)   NSMutableArray *childRouters;

@property (nonatomic, readonly) NSArray *interceptors;

@end

@implementation JHRouter {
    __weak JHRouter *_parentRouter;
}

- (void)addChildRouter:(nonnull JHRouter *)router {
    [self.childRouters addObject:router];
    [router setValue:self forKeyPath:@"_parentRouter"];
}

- (void)removeChildRouter:(nonnull JHRouter *)router {
    [self.childRouters removeObject:router];
    [router setValue:nil forKeyPath:@"_parentRouter"];
}

- (void)removeFromParentRouter {
    [self.parentRouter removeChildRouter:self];
}

static JHRouter *rootRouter;
+ (instancetype)rootRouter {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        rootRouter = [self new];
    });
    return rootRouter;
}

@end
