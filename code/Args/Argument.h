/*
 * Argument.h
 *
 *  Created on: 12/05/2022
 *      Author: jmotp
 */

#ifndef ARGS_ARGUMENT_H_
#define ARGS_ARGUMENT_H_


#include "TimeDuration.h"
#include "TimeInstance.h"
#include "TimeRepresentation.h"
#include "QosParams.h"
#include "Types.h"
#include <string>
#include <sstream>
#include <variant>

#define xdc__nolocalstring
extern "C" {
    //#include <xdc/std.h>
    //#include <xdc/runtime/System.h>
}



using namespace std;


/*
IDL: union Argument switch (TypeCode) {
case UNKNOWN_TC: Boolean valueError;
case UInt8_TC: UInt8 valueInt8;
case UINT16_TC: UInt16 valueUInt16;
case UINT32_TC: UInt32 valueUInt32;
case FLOAT32_TC: Float32 valueFloat32;
case FLOAT64_TC: Float64 valueFloat64;
case STRING_TC: _String valueString;
case OCTET_TC: _Octet valueOctet;
case BOOLEAN_TC: _Boolean valueBoolean;
case TIME_INSTANCE_TC: TimeInstance valueTimeInstance;
case TIME_DURATION_TC: TimeDuration valueTimeDuration;
case QOS_PARAMS_TC: QosParams valueQosParams;
case UInt8_ARRAY_TC: UInt8Array valueInt8Array;
case UINT16_ARRAY_TC: UInt16Array valueUInt16Array;
case UINT32_ARRAY_TC: UInt32Array valueUInt32Array;
case FLOAT32_ARRAY_TC: Float32Array valueFloat32Array;
case FLOAT64_ARRAY_TC: Float64Array valueFloat64Array;
case STRING_ARRAY_TC: StringArray valueStringArray;
case OCTET_ARRAY_TC: OctetArray valueOctetArray;
case BOOLEAN_ARRAY_TC: BooleanArray valueBooleanArray;
case TIME_INSTANCE_ARRAY_TC: TimeInstanceArray
 valueTimeInstanceArray;
case TIME_DURATION_ARRAY_TC: TimeDurationArray
 valueTimeDurationArray;
};*/



class Argument{


    public:
    enum TypeCode{
             UNKNOWN_TC,
             // Simple types
             UInt8_TC, UInt16_TC, UInt32_TC,
             Float32_TC, Float64TC, String_TC,
             Octet_TC, Boolean_TC,
             Time_Instance_TC, Time_Duration_TC,
             Qos_Params_TC,
             // Arrays of simple types. Note no QOS array
             UInt8_Array_TC, UInt16_Array_TC, UInt32_Array_TC,
             Float32_Array_TC, Float64_Array_TC, String_Array_TC,
             Octet_Array_TC, Boolean_Array_TC,
            Time_Instance_Array_TC, Time_Duration_Array_TC
            } type;


    union{
           Boolean _valueError;
           UInt8 _valueUInt8;
           UInt16 _valueUInt16;
           UInt32 _valueUInt32;
           Float32 _valueFloat32;
           Float64 _valueFloat64;
           String _valueString;
           Octet _valueOctet;
           Boolean _valueBoolean;
           TimeInstance _valueTimeInstance;
           TimeDuration _valueTimeDuration;
           QosParams valueQosParams;
           UInt8Array _valueInt8Array;
           UInt16Array _valueUInt16Array;
           UInt32Array _valueUInt32Array;
           Float32Array _valueFloat32Array;
           Float64Array _valueFloat64Array;
           StringArray _valueStringArray;
           OctetArray _valueOctetArray;
           BooleanArray _valueBooleanArray;
           TimeInstanceArray _valueTimeInstanceArray;
           TimeDurationArray _valueTimeDurationArray;

       };

    private:
        void init(TypeCode _type, void * value_ref);

    public:



        Argument();
        Argument(TypeCode _type, void * value_ref);
        ~Argument();

        UInt16 toString(String& result);

        UInt16 write(stringstream& ss);
        UInt16 read(stringstream& ss);


        Argument& operator= (const Argument&);
        Argument(const Argument &);

        UInt16 print();






};

void swapByteOrder(uint16_t& us);


void reverseStr(string& str);

#endif /* ARGS_ARGUMENT_H_ */
