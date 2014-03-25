//
//  EAError.h
//  EAContext
//
//  Created by Ryan on 13/11/27.
//  Copyright (c) 2013年 Atomax. All rights reserved.
//

#import "EADefines.h"

#ifndef EAContext_EAError_h
#define EAContext_EAError_h



EA_EXTERN NSString * const EAErrorDomain;


typedef enum
{
	EAErrorLECancel = 100,
    EAErrorLENotAvailable,
    EAErrorLEDeviceAlreadyConnected,
    EAErrorLEConnectionUnknown,
    EAErrorLEConnectionInvalidParameters,
    EAErrorLEConnectionInvalidHandle,
    EAErrorLEConnectionTimeout,
    
    EAErrorLEValidation,
    EAErrorLEInvalidDevice,
    
    EAErrorLEAccess,
    
    EAErrorAcceleromterNotAvailable,
    EAErrorGyroNotAvailable,
    EAErrorDeviceMotionNotAvailable,
    
	EAErrorDeviceRequiresMovement,
	EAErrorTrueNorthNotAvailable,
	EAErrorUnknown,
	EAErrorMotionActivityNotAvailable,
	EAErrorMotionActivityNotAuthorized,
	EAErrorMotionActivityNotEntitled,
	EAErrorInvalidParameter,
    EAErrorDeviceDisconnected
    
} EAError;
/*
CMLEErrorServiceNotFound = 1000,
CMLEErrorCharateristicNotFound,
CMLEErrorDiscoverService,
CMLEErrorDiscoverCharacteristic,
*/


#endif
