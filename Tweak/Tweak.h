#import <AVFoundation/AVFoundation.h> 
#ifndef SIMULATOR
#import <Cephei/HBPreferences.h>
#endif

#ifdef DEBUG
	#define DLog(fmt, ...) NSLog((fmt), ##__VA_ARGS__);
#else
	#define DLog(...)
#endif

#define PLIST_FILE @"/var/mobile/Library/Preferences/com.anthopak.pancake.plist"
#define pref_getValue(key) [[NSDictionary dictionaryWithContentsOfFile:PLIST_FILE] valueForKey:key]
#define pref_getBool(key) [pref_getValue(key) boolValue]


@interface _UINavigationInteractiveTransitionBase : NSObject

@property (assign,nonatomic) UIPanGestureRecognizer * gestureRecognizer;

-(void)handleNavigationTransition:(UIPanGestureRecognizer*)arg1 ;
-(void)startInteractiveTransition;

@end


@interface _UINavigationInteractiveTransition : _UINavigationInteractiveTransitionBase

@end


@interface UINavigationController (Custom)<UIGestureRecognizerDelegate>

@property (strong, nonatomic) _UINavigationInteractiveTransition * _cachedInteractionController;
+ (UIViewController*) topMostController;
- (BOOL)gestureRecognizerShouldBegin:(UIPanGestureRecognizer *)panGestureRecognizer;

@end



@interface CKTranscriptCollectionView : UICollectionView
@end