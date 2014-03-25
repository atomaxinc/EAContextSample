//
//  EAContext.h
//  EAContext
//
//  Created by Ryan on 13/11/26.
//  Copyright (c) 2013年 Atomax. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#include "EAError.h"

#define CONNECT_PREVIOUSLY

typedef enum
{
    EAConnectionTypeBLE = 1,
    EAConnectionTypePHONE,
    
}EAConnectionType;

typedef enum
{
    EASportTypeRAWData = 1      << 1,
    EASportTypeTennis = 1       << 2,
    EASportTypeBaseballBat = 1  << 3,
    EASportTypeWalk = 1         << 4,
    EASportTypeCycling = 1      << 5,
    EASportTypeMove =   1       << 6,
    EASportTypeBadminton = 1    << 7,
}EASportType;



//#define EA_EXTERN extern

//EA_EXTERN void (^EADeviceConnectionCompletion)(NSError *error);
typedef void (^EADeviceConnectionCompletion)(NSError *error);

@class EAContext;

@protocol EAContextDelegate <NSObject>

- (void)context:(EAContext *)context didFailToAccessWithError:(NSError *)error;

- (void)context:(EAContext *)context didUpdateCalculatedResultWithUserInfo:(NSDictionary *)userinfo;

@end

@interface EAContext : NSObject

@property (assign, nonatomic) id<EAContextDelegate> delegate;
@property (readonly, nonatomic) EAConnectionType connectionType;
@property (readonly, nonatomic) EASportType sportType;

- (id)initWithSport:(EASportType)sportType andConnectionType:(EAConnectionType)connectType;

- (void)startUpdate;

- (void)stopUpdate;

- (BOOL)isUpdating;

@end

@interface EAContext (BLE)

- (void)displayBluetoothLowEnergyPickerOnViewController:(UIViewController *)viewController WithCompletion:(EADeviceConnectionCompletion)completion;

- (void)disconnect;

- (BOOL)isConnected;

@end

@interface EAContext (DeviceInfo)

@property (nonatomic, retain) NSString *deviceName;
@property (nonatomic) CGFloat batteryPercentage;

@end

EA_EXTERN NSString * const kEASportResultAccelerometer;
EA_EXTERN NSString * const kEASportResultGyro;
EA_EXTERN NSString * const kEASportResultGravity;
EA_EXTERN NSString * const kEASportResultUserAcceleration;

EA_EXTERN NSString  *kEASportResultBadmintonSwingSpeed;
EA_EXTERN NSString  *kEASportResultBadmintonFlatChopRatio;
EA_EXTERN NSString  *kEASportResultBadmintonRacketBottomPositions;
EA_EXTERN NSString  *kEASportResultBadmintonRacketTopPositions;
EA_EXTERN NSString  *kEASportResultBadmintonRacketBottomVelocities;
EA_EXTERN NSString  *kEASportResultBadmintonRacketTopVelocities;
EA_EXTERN NSString  *kEASportResultBadmintonRacketBoundryPositions;
EA_EXTERN NSString  *kEASportResultBadmintonRacketIntervals;
EA_EXTERN NSString  *kEASportResultBadmintonRacketRotationVector;
EA_EXTERN NSString  *kEASportResultBadmintonRacketRotationTheta;
EA_EXTERN NSString  *kEASportResultBadmintonRacketOriginGravity;