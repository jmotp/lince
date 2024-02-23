/*
 * TimeInstance.h
 *
 *  Created on: 19/04/2022
 *      Author: jmotp
 */

#ifndef TIMEINSTANCE_H_
#define TIMEINSTANCE_H_
#include "TimeRepresentation.h"
#include <cstdint>

struct TimeInstance
{
    uint8_t epoch;
    TimeRepresentation timeRepresentation;
};

#endif /* TIMEINSTANCE_H_ */
