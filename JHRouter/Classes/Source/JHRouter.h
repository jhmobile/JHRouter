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

#pragma mark - open URL
+ (BOOL)openURL:(NSString *)URL;
+ (BOOL)openURL:(NSString *)URL
   withUserInfo:(NSDictionary *)userInfo;

#pragma mark - push viewController mapped to URL
+ (BOOL)pushURL:(NSString *)URL;
+ (BOOL)pushURL:(NSString *)URL
           from:(UINavigationController *)navigationController;
+ (BOOL)pushURL:(NSString *)URL
   withUserInfo:(NSDictionary *)userInfo
   interceptors:(NSArray *)interceptorClasses
           from:(UINavigationController *)navigationController
     completion:(RouterCompletionCallback *)completion;
+ (BOOL)pushURL:(NSString *)URL
   withUserInfo:(NSDictionary *)userInfo
           from:(UINavigationController *)navigationController
skipAllInterceptors:(BOOL)skip
     completion:(RouterCompletionCallback *)completion;
+ (BOOL)pushURL:(NSString *)URL
   withUserInfo:(NSDictionary *)userInfo
           from:(UINavigationController *)navigationController
skipInterceptors:(NSArray *)interceptorClasses
     completion:(RouterCompletionCallback *)completion;

#pragma mark - present viewController mapped to URL
+ (BOOL)presentURL:(NSString *)URL
         wrappedIn:(Class)navigationControllerClass;
+ (BOOL)presentURL:(NSString *)URL
      withUserInfo:(NSDictionary *)userInfo
         wrappedIn:(Class)navigationControllerClass;
+ (BOOL)presentURL:(NSString *)URL
      withUserInfo:(NSDictionary *)userInfo
      interceptors:(NSArray *)interceptorClasses
         wrappedIn:(Class)navigationControllerClass
        completion:(RouterCompletionCallback *)completion;
+ (BOOL)presentURL:(NSString *)URL
      withUserInfo:(NSDictionary *)userInfo
         wrappedIn:(Class)navigationControllerClass
skipAllInterceptors:(BOOL)skip
        completion:(RouterCompletionCallback *)completion;
+ (BOOL)presentURL:(NSString *)URL
      withUserInfo:(NSDictionary *)userInfo
         wrappedIn:(Class)navigationControllerClass
skipInterceptors:(NSArray *)interceptorClasses
        completion:(RouterCompletionCallback *)completion;

#pragma mark - map things to URL
+ (void)mapBlock:(RouterBlock)block
           toURL:(NSString *)URL;

+ (void)mapController:(Class)viewControllerClass
              present:(BOOL)defaultPresent
            wrappedIn:(Class)navigationControllerClass
                toURL:(NSString *)URL
         whenMatching:(NSDictionary *)userInfo;

+ (void)mapController:(Class)viewControllerClass
            taskClass:(Class)taskClass
                toURL:(NSString *)URL
         whenMatching:(NSDictionary *)userInfo;

+ (void)mapInterceptors:(NSArray *)interceptorClasses
                  toURL:(NSString *)URL
           whenMatching:(NSDictionary *)userInfo;

@end
