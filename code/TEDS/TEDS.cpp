/*
 * TEDS.cpp
 *
 *  Created on: 07/07/2022
 *      Author: jmotp
 */

#include <TEDS/TEDS.h>

TEDS::TEDS()
{
    // TODO Auto-generated constructor stub

}

TEDS::TEDS(OctetArray TEDS_OctetArray)
{
    std::stringstream ss;
    ss<<TEDS_OctetArray;
    UInt32 length;
    ss.read((char *)&length,4);

}

TEDS::~TEDS()
{
    // TODO Auto-generated destructor stub
}

UInt8 TEDS::addToTEDS(UInt8 type, OctetArray value){
    TEDS_Registry.insert(std::pair<UInt8, OctetArray>(type,value));
    TEDS_Registry[type] = value;
}


OctetArray& TEDS::getFromTEDS(UInt8 type){
    return TEDS_Registry.at(type);
}

