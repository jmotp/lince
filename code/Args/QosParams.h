/*
 * Argument.h
 *
 *  Created on: 03/06/2022
 *      Author: jmotp
 */

#ifndef ARGS_QOSPARAMS_H_
#define ARGS_QOSPARAMS_H_

#include "Types.h"
#include "TimeDuration.h"

typedef struct QosParams_ {
    Boolean Service;
    TimeDuration Period;
    UInt32 transmitSize;
    UInt32 replySize;
    TimeDuration accessLatency;
    TimeDuration transmitLatency;
	
} QosParams; 

#endif

