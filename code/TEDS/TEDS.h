/*
 * TEDS.h
 *
 *  Created on: 07/07/2022
 *      Author: jmotp
 */

#ifndef TEDS_TEDS_H_
#define TEDS_TEDS_H_

#include <Args/Types.h>
#include <map>
#include <sstream>

class TEDS
{
public:
    TEDS();
    virtual ~TEDS();
    TEDS(OctetArray TEDS_OctetArray);
    UInt8 addToTEDS(UInt8 type, OctetArray value);
    OctetArray& getFromTEDS(UInt8 type);
private:
    map<int, OctetArray> TEDS_Registry;
};

#endif /* TEDS_TEDS_H_ */
