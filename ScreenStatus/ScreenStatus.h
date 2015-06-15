//
//  ScreenStatus.h
//  Created by Mitsuharu Emoto on 2010/07/05.
//

// 2010/07/05 （リリース）
// ・加速度センサーを使って端末の向きを検出する
// ・画面ロック中でも検出可能

// 2011/11/03
// ・ARC対応化に関して修正
// ・クラスメソッドを追加．傾き変化を検出したいときはimport元でdelegateを設定して，accelerationを調べる

// 2015/06/08 masashi mizuno
// CoreMotionに移行

#import <CoreMotion/CoreMotion.h>

typedef struct FORCE {
	float x;
	float y;
	float z;
} FORCE;

@interface ScreenStatus : NSObject {
	FORCE force_;
}

- (void)start;
- (void)stop;
- (BOOL)isScreenLock;
- (BOOL)isPortrait;
- (BOOL)isLandscape;
- (UIDeviceOrientation)physicalOrientation;

+ (UIDeviceOrientation)orientation:(CMAccelerometerData *)accelerometerData;
+ (BOOL)orientationIsPortrait:(CMMotionManager *)motionManager;
+ (BOOL)orientationIsLandscape:(CMMotionManager *)motionManager;

@property (getter=isScreenLock, readonly) BOOL isScreenLock;
@property (getter=isPortrait, readonly) BOOL isPortrait;
@property (getter=isLandscape, readonly) BOOL isLandscape;
@property (getter=physicalOrientation, readonly) UIDeviceOrientation physicalOrientation;

@end
