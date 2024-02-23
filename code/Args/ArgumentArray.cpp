/*
 * ArgumentArray.cpp
 *
 *  Created on: 12/05/2022
 *      Author: jmotp
 */

#include "Args/ArgumentArray.h"

#define xdc__nolocalstring
extern "C" {
#include <xdc/std.h>
#include <xdc/runtime/System.h>
}


ArgumentArray::ArgumentArray()
{
    // TODO Auto-generated constructor stub

}

ArgumentArray::~ArgumentArray()
{
}

ArgumentArray::ArgumentArray(const ArgumentArray& argumentArray){
    copy(argumentArray.argumentArray.begin(), argumentArray.argumentArray.end(), back_inserter(this->argumentArray));
}

uint16_t ArgumentArray::getByName(String name, Argument& argument){
    UInt16 index;
    stringToIndex(name, index);
    argument = get<1>(argumentArray[index]);
    return 0;
};

uint16_t ArgumentArray::getByIndex(UInt16 index, Argument& argument){

    argument = get<1>(argumentArray[index]);
    return 0;
}

uint16_t ArgumentArray::putByName(String name, Argument value){
    argumentArray.push_back(tuple<string,Argument>(name,value));
    return 0;
}

uint16_t ArgumentArray::putByIndex(UInt16 index, Argument value){

    vector<tuple<string, Argument>>::iterator it = argumentArray.begin();
    argumentArray.insert(it+index,tuple<string,Argument>("",value));

    return 0;
};

UInt16 ArgumentArray::stringToIndex( String name, UInt16& index){
    vector<tuple<string, Argument>>::iterator argumentArray_ptr = argumentArray.begin();
    for (argumentArray_ptr = argumentArray.begin(); argumentArray_ptr < argumentArray.end(); argumentArray_ptr++){
        if(get<0>(*argumentArray_ptr) == name){
            index = argumentArray_ptr - argumentArray.begin();
            return 0;
        }
    }

    return 0;
};

uint16_t ArgumentArray::getNames(StringArray& names){
    vector<tuple<string, Argument>>::iterator argumentArray_ptr;

        for (argumentArray_ptr = argumentArray.begin(); argumentArray_ptr < argumentArray.end(); argumentArray_ptr++){
           names.push_back(get<0>(*argumentArray_ptr));
        }

    return 0;
};

uint16_t ArgumentArray::getIndexes(UInt16Array& indexes){
    vector<tuple<string, Argument>>::iterator argumentArray_ptr;

    for (argumentArray_ptr = argumentArray.begin(); argumentArray_ptr < argumentArray.end(); argumentArray_ptr++){
       indexes.push_back(argumentArray_ptr - argumentArray.begin());
    }


    return 0;
};

uint16_t ArgumentArray::size(){
    return argumentArray.size();
}

uint16_t ArgumentArray::writeAsTEDS(stringstream& ss){
    UInt8 index;
    vector<tuple<string, Argument>>::iterator argumentArray_ptr = argumentArray.begin();
    for (argumentArray_ptr = argumentArray.begin(); argumentArray_ptr < argumentArray.end(); argumentArray_ptr++){
            index = argumentArray_ptr - argumentArray.begin();
            ss.write((const char *)&index,1);
            get<1>(*argumentArray_ptr).write(ss);
    }


    return 0;
}

uint16_t ArgumentArray::write(stringstream& ss){
    for(tuple<string,Argument> arg: argumentArray){
        get<1>(arg).write(ss);
    }

    return 0;
}
