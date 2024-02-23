/*
 * TypeCode.h
 *
 *  Created on: 12/05/2022
 *      Author: jmotp
 */

#ifndef ARGS_TYPECODE_H_
#define ARGS_TYPECODE_H_


    enum TypeCode {
     UNKNOWN_TC,
     // Simple types
     UInt8_TC, UINT16_TC, UINT32_TC,
     FLOAT32_TC, FLOAT64TC, STRING_TC,
     OCTET_TC, BOOLEAN_TC,
     TIME_INSTANCE_TC, TIME_DURATION_TC,
     QOS_PARAMS_TC,
     // Arrays of simple types. Note no QOS array
     UInt8_ARRAY_TC, UINT16_ARRAY_TC, UINT32_ARRAY_TC,
     FLOAT32_ARRAY_TC, FLOAT64_ARRAY_TC, STRING_ARRAY_TC,
     OCTET_ARRAY_TC, BOOLEAN_ARRAY_TC,
    TIME_INSTANCE_ARRAY_TC, TIME_DURATION_ARRAY_TC
    };


#endif /* ARGS_TYPECODE_H_ */
