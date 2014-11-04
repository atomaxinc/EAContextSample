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

/* Connection Type (Data Source) */
typedef enum
{
    EAConnectionTypeBLE = 1,
    EAConnectionTypePHONE,
    
}EAConnectionType;

/* Sport Type Code */
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

/*! Connection callback function pointer */
typedef void (^EADeviceConnectionCompletion)(NSError *error);

@class EAContext;

@protocol EAContextDelegate <NSObject>

/*!
 *  @method context:didFailToAccessWithError:
 *
 *  @param context      The EAContext object providing this information.
 *  @param error        NSError object including EAError error code.
 *
 *  @discussion         This method is invoked when error occurs while accessing data, connecting to peripheral.
 *
 */
- (void)context:(EAContext *)context didFailToAccessWithError:(NSError *)error;

/*!
 *  @method context:didUpdateCalculatedResultWithUserInfo:
 *
 *  @param context      The EAContext object providing this information.
 *  @param userinfo     A dictionary of updated data.
 *
 *  @discussion         This method returns the result when data is received/calculated from Curo sensor or iPhone sensor.
 *
 */
- (void)context:(EAContext *)context didUpdateCalculatedResultWithUserInfo:(NSDictionary *)userinfo;

@end

@interface EAContext : NSObject

/*!
 *  @property delegate
 *
 *  @discussion The delegate object that will receive sensor events.
 */
@property (assign, nonatomic) id<EAContextDelegate> delegate;

/*!
 *  @property connectionType
 *
 *  @discussion This property determines whether data source is from Curo sensor or iPhone.
 *
 *  @see EAConnectionType
 */
@property (readonly, nonatomic) EAConnectionType connectionType;

/*!
 *  @property sportType
 *
 *  @discussion The property determines which type of data will be received.
 *
 *  @see EASportType
 */
@property (readonly, nonatomic) EASportType sportType;

/* Initialize */
/*!
 *  @method initWithSport:andConnectionType:
 *
 *
 *  @discussion Initialize a EAContext object that handle the connection and data transmission, as well as providing information.
 *
 *
 */
- (id)initWithSport:(EASportType)sportType andConnectionType:(EAConnectionType)connectType;

/* Update */

/*!
 *  @method startUpdate
 *
 *
 *  @discussion         While device is connected, invoke startUpdate method to update data.
 *
 *  @see                context:didUpdateCalculatedResultWithUserInfo:
 *
 */
- (void)startUpdate;

/*!
 *  @method stopUpdate
 *
 *
 *  @discussion         While device is connected, invoke stopUpdate method to pause.
 *
 *
 */
- (void)stopUpdate;

/*!
 *  @method isUpdating
 *
 *
 *  @discussion         While device is connected, this method returns a BOOL to see whether the sensor is updating.
 *
 *
 */
- (BOOL)isUpdating;

@end

@interface EAContext (BLE)

/* Connection */

/*!
 *  @method displayBluetoothLowEnergyPickerOnViewController:WithCompletion:
 *
 *
 *  @discussion         Invoking this method will display a view controller to pick a Curo sensor. If connection succeed, view controller will dismiss automatically.
 *
 *
 */
- (void)displayBluetoothLowEnergyPickerOnViewController:(UIViewController *)viewController WithCompletion:(EADeviceConnectionCompletion)completion;

/*!
 *  @method disconnect
 *
 *
 *  @discussion         Invoking this method to disconnect from current curo sensor.
 *
 *
 */
- (void)disconnect;

/*!
 *  @method isConnected
 *
 *  @discussion Query current connection status.
 */
- (BOOL)isConnected;

@end

@interface EAContext (DeviceInfo)

/*!
 *  @property deviceName
 *
 *  @discussion Shows current connected device name.
 */
@property (nonatomic, retain) NSString *deviceName;

/*!
 *  @property batteryPercentage
 *
 *  @discussion Shows current connected device battery percentage.
 */
@property (nonatomic) CGFloat batteryPercentage;

@end

/*!
 *  @const kEASportResultAccelerometer
 *
 *  @discussion A NSString key may be contained in the parameter userinfo in context:didUpdateCalculatedResultWithUserInfo:. When the context:didUpdateCalculatedResultWithUserInfo: method is invoked, the parameter userinfo with kEASportResultAccelerometer key will bring a NSValue object containing a structure AMXVector3 representing accelerometer data sent from Curo sensor.
 *
 *  @see    context:didUpdateCalculatedResultWithUserInfo:
 */
EA_EXTERN NSString * const kEASportResultAccelerometer;

/*!
 *  @const kEASportResultGyro
 *
 *  @discussion A NSString key may be contained in the parameter userinfo in context:didUpdateCalculatedResultWithUserInfo:. When the context:didUpdateCalculatedResultWithUserInfo: method is invoked, the parameter userinfo with kEASportResultGyro key will bring a NSValue object containing a structure AMXVector3 representing gyroscope data sent from Curo sensor.
 *
 *  @see    context:didUpdateCalculatedResultWithUserInfo:
 */
EA_EXTERN NSString * const kEASportResultGyro;

/*!
 *  @const kEASportResultGravity
 *
 *  @discussion A NSString key may be contained in the parameter userinfo in context:didUpdateCalculatedResultWithUserInfo:. When the context:didUpdateCalculatedResultWithUserInfo: method is invoked, the parameter userinfo with kEASportResultGravity key will bring a NSValue object containing a structure AMXVector3 representing gravity data calculated by the algorithm we provide.
 *
 *  @see    context:didUpdateCalculatedResultWithUserInfo:
 */
EA_EXTERN NSString * const kEASportResultGravity;

/*!
 *  @const kEASportResultUserAcceleration
 *
 *  @discussion A NSString key may be contained in the parameter userinfo in context:didUpdateCalculatedResultWithUserInfo:. When the context:didUpdateCalculatedResultWithUserInfo: method is invoked, the parameter userinfo with kEASportResultUserAcceleration key will bring a NSValue object containing a structure AMXVector3 representing user accelertaion data calculated by the algorithm we provide.
 *
 *  @see    context:didUpdateCalculatedResultWithUserInfo:
 */
EA_EXTERN NSString * const kEASportResultUserAcceleration;

/* The other NSString keys can provide some kinds of information (as key's title). Beware that some of the algorithms are not well implemented*/
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