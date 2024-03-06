/*
 * Argument.cpp
 *
 *  Created on: 12/05/2022
 *      Author: jmotp
 */

#include "Args/Argument.h"
#include <cstdio>
#include <variant>

void swapByteOrder(uint16_t& us)
{
    us = (us >> 8) |
         (us << 8);
}

void swapByteOrder(uint32_t& ui)
{
    ui = (ui >> 24) |
         ((ui<<8) & 0x00FF0000) |
         ((ui>>8) & 0x0000FF00) |
         (ui << 24);
}



Argument::Argument()
{

    // TODO Auto-generated constructor stub

};


/*
enum TypeCode{
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
        } type;
*/

Argument::Argument(TypeCode _type, void* value_ref){
    init(_type,value_ref);
}

void Argument::init(TypeCode _type, void * value_ref){
    type = _type;
    switch(type){
        case UInt8_TC:
            _valueUInt8 = *(uint8_t *)value_ref;
            break;
        case UInt16_TC:
            _valueUInt16 = *(uint16_t *)value_ref;
            break;
        case UInt32_TC:
            _valueUInt32 = *(uint32_t *)value_ref;
            break;
        case Float32_TC:
            _valueFloat32 = *(Float32 *)value_ref;

               break;
        case Octet_Array_TC:

            new(&this->_valueOctetArray) string(*((string*)value_ref));
          break;
        case UInt32_Array_TC:
         new(&this->_valueUInt32Array) vector<UInt32>(*(vector<UInt32>*)value_ref);
        }
    //this->print();

}



Argument& Argument::operator= (const Argument& argument){

    this->type = argument.type;
//    \\printf("Copying Argument of type %d via =\n", type);

//    \\printf("Here?\n");
    switch(argument.type){
        case UInt8_TC:
            this->_valueUInt8 = argument._valueUInt8;
            break;
        case UInt16_TC:
            this->_valueUInt16 = argument._valueUInt16;
            break;
        case UInt32_TC:
            this->_valueUInt32 = argument._valueUInt32;
            break;
        case Float32_TC:
            this->_valueFloat32 = argument._valueFloat32;

               break;
        case Octet_Array_TC:
//            System_printf("String Pointer: %d\n", argument._valueOctetArray);
//            System_flush();
            new(&this->_valueOctetArray) string(argument._valueOctetArray);
        break;
        case UInt32_Array_TC:
         new(&this->_valueUInt32Array) vector<UInt32>(argument._valueUInt32Array);
            
        }

    return *this;
    ;
}

UInt16 Argument::print(){

    switch(this->type){
            case UInt8_TC:
               fprintf(stdout,"Argument UInt8 %u\n", this->_valueUInt8);
                break;
            case UInt16_TC:
                fprintf(stdout,"Argument UInt16 %u\n", this->_valueUInt16);
                break;
            case UInt32_TC:
                fprintf(stdout,"Argument long %u\n", this->_valueUInt32);
                break;
            case Float32_TC:
                fprintf(stdout,"Argument float %f\n", this->_valueFloat32);
                break;

            case Octet_Array_TC:
                fprintf(stdout,"Argument String %s of size%d\n", (this->_valueOctetArray).c_str(),_valueOctetArray.size());
                break;
    }
    fflush(stdout);
    return 0;

}

UInt16 Argument::toString(String& result){
    switch(this->type){
                case UInt8_TC:
                    result = this->_valueUInt8;
                    break;
                case UInt16_TC:
                    result = this->_valueUInt16;
                    break;
                case UInt32_TC:
                    result = this->_valueUInt32;
                    break;
                case Float32_TC:
                    result= this->_valueFloat32;
                   break;
                case Octet_Array_TC:
                    result = this->_valueOctetArray;
                    break;
        }
       fflush(stdout);
        return 0;

}

UInt16 Argument::write(stringstream& ss){
    uint8_t size;
    uint16_t arg_size;
    ss.write((const char*)&type,sizeof(uint8_t));
    switch(this->type){
                    case UInt8_TC:
                        arg_size = 1;
                        swapByteOrder(arg_size);
                        ss.write((const char*)(&arg_size),2);
                        ss.write((const char*)&(this->_valueUInt8),sizeof(uint8_t));
                        break;
                    case UInt16_TC:
                    {
                        uint16_t buffer_ = this->_valueUInt16;
                        swapByteOrder(buffer_);
                        size=2;
                        arg_size = 2;
                        swapByteOrder(arg_size);
                        ss.write((const char*)(&arg_size),2);
                        ss.write((const char*)&(buffer_),sizeof(uint16_t));
                        break;
                    }
                    case UInt32_TC:
                    {
                        uint32_t buffer = this->_valueUInt32;
                        swapByteOrder(buffer);
                        size=4;
                        arg_size = 4;
                        swapByteOrder(arg_size);
                        ss.write((const char*)(&arg_size),2);
                        ss.write((const char*)&(buffer),sizeof(uint32_t));
                        break;
                    }
                    case Float32_TC:
                    {
                        union {
                            float f;
                            uint32_t u;
                        } f2u = { .f = this->_valueFloat32 };


                        uint32_t buffer = f2u.u;
                        //swapByteOrder(buffer);
                        size=4;
                        arg_size = 4;
                        swapByteOrder(arg_size);
                        ss.write((const char*)(&arg_size),2);
                        ss.write((const char*)&(buffer),sizeof(uint32_t));



                        break;
                    }
                    case Octet_Array_TC:
                        size = this->_valueOctetArray.size();
//                        System_printf("Size: %d\n", size);
//                        System_flush();
                        arg_size=size;
                        swapByteOrder(arg_size);
                        ss.write((const char*)(&arg_size),2);
                        ss.write((const char*)(this->_valueOctetArray.data()),size);
                        break;
            }
            return 0;

}

UInt16 Argument::read(stringstream& ss){

    TypeCode type;
    uint16_t size;
    void* value;
    ss.read(( char*)&type,sizeof(TypeCode));
    ss.read(( char*)&size,sizeof(uint16_t));
    swapByteOrder(size);

    
//    fprintf(stdout,"Arg read %d %d\n",type,size);
//    fflush(stdout);
    value= malloc(size*sizeof(uint8_t));
    
    ss.read((char*)value,(size_t)size);
    if(size==2){
        swapByteOrder(*(uint16_t *)value);
    }else if(size==4){
        swapByteOrder(*(uint32_t *)value);

    }
    init(type,value);
    free(value);
    return 3+size;

}


Argument::Argument(const Argument & arg)
{

    this->type = arg.type;
//    \\printf("Copying Argument of type %d\n", type);
    switch(this->type){
    case UInt8_TC: this->_valueUInt8 = arg._valueUInt8;
                break;
        case UInt16_TC: this->_valueUInt16 = arg._valueUInt16;
            break;
        case UInt32_TC: this->_valueUInt32 = arg._valueUInt32;
        break;
        case Float32_TC: this->_valueFloat32 = arg._valueFloat32;
        break;
        case Octet_Array_TC: new(&this->_valueOctetArray) string(arg._valueOctetArray);
        break;
        case UInt32_Array_TC: new(&this->_valueUInt32Array) vector<UInt32>(arg._valueUInt32Array);
        break;
        case Boolean_TC: this->_valueBoolean = arg._valueBoolean;
        //printf("String pointer %p\n", _valueOctetArray);
     }
    // TODO Auto-generated constructor stub

};

Argument::~Argument()
{
//    printf("Destructing Argument of type %d\n", type);

    switch(type){
//           this->print();
           case Octet_Array_TC:
               //printf("String pointer %p\n", _valueOctetArray);
               _valueOctetArray.~string();
            break;
            case UInt32_Array_TC: 
                _valueUInt32Array.~vector<UInt32>();
        }
    // TODO Auto-generated destructor stub
};
