/*
 * Types.h
 *
 *  Created on: 03/06/2022
 *      Author: jmotp
 */

#ifndef ARGS_TYPES_H_
#define ARGS_TYPES_H_

#define xdc__nolocalstring


#include<cstdint>
#include <string>
#include <vector>
#include "TimeInstance.h"
#include "TimeDuration.h"



using namespace std;
typedef uint8_t UInt8;
typedef uint16_t UInt16;
typedef uint32_t UInt32;
typedef int8_t Int8;
typedef int16_t Int16;
typedef int32_t Int32;
typedef float Float32;
typedef double Float64;
typedef string String;
typedef char Octet;
typedef bool Boolean;

typedef std::vector<int8_t> Int8Array;
typedef std::vector<int16_t> Int16Array;
typedef std::vector<int32_t> Int32Array;
typedef std::vector<uint8_t> UInt8Array;
typedef std::vector<uint16_t> UInt16Array;
typedef std::vector<uint32_t> UInt32Array;
typedef std::vector<float> Float32Array;
typedef std::vector<double> Float64Array;
typedef std::vector<string> StringArray;
typedef String OctetArray;
typedef std::vector<bool> BooleanArray;
typedef std::vector<TimeInstance> TimeInstanceArray;
typedef std::vector<TimeDuration> TimeDurationArray;

typedef struct UNITS_t{
        UInt8 interpretation; 
        UInt8 radians; 
        UInt8 steradians; 
        UInt8 meters; 
        UInt8 kilograms; 
        UInt8 seconds; 
        UInt8 amperes; 
        UInt8 kelvins; 
        UInt8 moles; 
        UInt8 candelas;
        UInt8 Units;
}UNITS; 






#endif /* ARGS_TYPES_H_ */
