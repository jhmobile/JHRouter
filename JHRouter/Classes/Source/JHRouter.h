//
//  JHRouter.h
//  Pods
//
//  Created by mshqiu on 2017/12/13.
//

#import <UIKit/UIKit.h>

extern NSString *const RouterParameterURLKey;
extern NSString *const RouterParameterURLPatternKey;
extern NSString *const RouterParameterUserInfoKey;
extern NSString *const RouterParameterCallbackKey;

typedef id(^RouterBlock)(NSDictionary *params);
typedef void(^RouterCompletionCallback)(BOOL succeed, NSDictionary *userInfo);

typedef NS_ENUM(NSUInteger, RouteType) {
    RouteTypeNone,
    RouteTypeBlock,
    RouteTypeViewController,
};

@interface JHRouter : NSObject

+ (RouteType)canOpenURL:(NSString *)URL;

+ (BOOL)openURL:(NSString *)URL;
+ (BOOL)openURL:(NSString *)URL
   withUserInfo:(NSDictionary *)userInfo;

+ (BOOL)pushViewControllerMappedToURL:(NSString *)URL;
+ (BOOL)pushViewControllerMappedToURL:(NSString *)URL
                         withUserInfo:(NSDictionary *)userInfo;
+ (BOOL)pushViewControllerMappedToURL:(NSString *)URL
                                 from:(UINavigationController *)navigationController;
+ (BOOL)pushViewControllerMappedToURL:(NSString *)URL
                         withUserInfo:(NSDictionary *)userInfo
                                 from:(UINavigationController *)navigationController;
+ (BOOL)pushViewControllerMappedToURL:(NSString *)URL
                         withUserInfo:(NSDictionary *)userInfo
                                 from:(UINavigationController *)navigationController
                           completion:(RouterCompletionCallback *)completion;

+ (BOOL)presentViewControllerMappedToURL:(NSString *)URL;
+ (BOOL)presentViewControllerMappedToURL:(NSString *)URL
                            withUserInfo:(NSDictionary *)userInfo;
+ (BOOL)presentViewControllerMappedToURL:(NSString *)URL
                                  wrappedIn:(Class)navigationControllerClass;
+ (BOOL)presentViewControllerMappedToURL:(NSString *)URL
                                  wrappedIn:(Class)navigationControllerClass
                            withUserInfo:(NSDictionary *)userInfo;
+ (BOOL)presentViewControllerMappedToURL:(NSString *)URL
                            withUserInfo:(NSDictionary *)userInfo
                               wrappedIn:(Class)navigationControllerClass
                              completion:(RouterCompletionCallback *)completion;

+ (void)mapBlock:(RouterBlock)block
           toURL:(NSString *)URL;

+ (void)mapViewControllerClass:(Class)viewControllerClass
                         toURL:(NSString *)URL;
+ (void)mapViewControllerClass:(Class)viewControllerClass
                         toURL:(NSString *)URL
                  withUserInfo:(NSDictionary *)userInfo;

+ (void)mapViewControllerClass:(Class)viewControllerClass
                         toURL:(NSString *)URL
                       present:(BOOL)defaultPresent
                     wrappedIn:(Class)navigationControllerClass;
+ (void)mapViewControllerClass:(Class)viewControllerClass
                         toURL:(NSString *)URL
                  withUserInfo:(NSDictionary *)userInfo
                       present:(BOOL)defaultPresent
                     wrappedIn:(Class)navigationControllerClass;

+ (void)mapViewControllerClass:(Class)viewControllerClass
                         toURL:(NSString *)URL
                     taskClass:(Class)taskClass;
+ (void)mapViewControllerClass:(Class)viewControllerClass
                         toURL:(NSString *)URL
                  withUserInfo:(NSDictionary *)userInfo
                     taskClass:(Class)taskClass;

+ (void)mapInterceptors:(NSArray *)interceptorClasses
                  toURL:(NSString *)URL;
+ (void)mapInterceptors:(NSArray *)interceptorClasses
                  toURL:(NSString *)URL
           withUserInfo:(NSDictionary *)userInfo;

@end
