/*
 * ArgumentArray.h
 *
 *  Created on: 12/05/2022
 *      Author: jmotp
 */

#ifndef ARGS_ARGUMENTARRAY_H_
#define ARGS_ARGUMENTARRAY_H_

#include <string>
#include "Argument.h"
#include <cstdint>
#include <vector>
#include <tuple>
#include <sstream>

#define xdc__nolocalstring
#include <xdc/runtime/System.h>

using namespace std;
class ArgumentArray
{


private:
    vector<tuple<string, Argument>> argumentArray;

public:
    ArgumentArray();
    virtual ~ArgumentArray();

    ArgumentArray(const ArgumentArray& argumentArray);

    UInt16 getByName(String name, Argument& argument);

    UInt16 getByIndex(UInt16 index, Argument& argument);

    UInt16 putByName(String name, Argument value);

    UInt16 putByIndex(UInt16 index, Argument value);

    UInt16 stringToIndex( String name, UInt16& index);

    UInt16 getNames(StringArray& names);

    UInt16 getIndexes(UInt16Array& indexes);

    UInt16 size(void);

    UInt16 write(stringstream& ss);

    UInt16 writeAsTEDS(stringstream& ss);



};

#endif /* ARGS_ARGUMENTARRAY_H_ */
