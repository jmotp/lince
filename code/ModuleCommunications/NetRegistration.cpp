/*
 * NetRegistration.cpp
 *
 *  Created on: 13/03/2024
 *      Author: jmotp
 */

#include <ModuleCommunications/NetRegistration.h>

NetRegistration::NetRegistration()
{
    // TODO Auto-generated constructor stub

}

NetRegistration::~NetRegistration()
{
    // TODO Auto-generated destructor stub
}

UInt16 NetRegistration::registerModule(NetComm& commInterface, UInt8 technologyId, String name, UInt8& moduleId){
    return 0;
}

UInt16 NetRegistration::registerDestination(UInt8 moduleId, UInt16& destId){
    return 0;
}

UInt16 NetRegistration::unRegisterDestination(UInt8 moduleId, UInt16& destId){
    return 0;
}

UInt16 NetRegistration::reportDestinations(UInt8 moduleId, UInt16 maxLen, UInt16 offset, UInt16Array& destinations){
    return 0;

}
UInt16 NetRegistration::reportGroups(UInt8 moduleId, UInt16 maxLen, UInt16 offset, UInt16Array& groups){
    return 0;

}
