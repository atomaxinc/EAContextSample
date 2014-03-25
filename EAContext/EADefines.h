//
//  EADefines.h
//  EAContext
//
//  Created by Ryan on 13/11/27.
//  Copyright (c) 2013年 Atomax. All rights reserved.
//

#ifndef EAContext_EADefines_h
#define EAContext_EADefines_h


#ifdef __cplusplus
#define EA_EXTERN extern "C" __attribute__((visibility ("default")))
#else
#define EA_EXTERN extern __attribute__((visibility ("default")))
#endif


union _AMXVector3
{
    struct { float x, y, z; };
    float v[3];
};
typedef union _AMXVector3 AMXVector3;

AMXVector3 AMXVector3Make(float x, float y, float z);


union _AMXVector2
{
    struct { float x, y; };
    float v[2];
};
typedef union _AMXVector2 AMXVector2;

long long getTimeMicro();




#endif
