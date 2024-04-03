/*
 * NetRegistration.h
 *
 *  Created on: 13/03/2024
 *      Author: jmotp
 */

#ifndef MODULECOMMUNICATIONS_NETREGISTRATION_H_
#define MODULECOMMUNICATIONS_NETREGISTRATION_H_
#include <ModuleCommunications/Registration.h>
#include <Args/Types.h>
#include <ModuleCommunications/NetComm.h>

class NetRegistration : public Registration
{
public:
    NetRegistration();
    virtual ~NetRegistration();
    UInt16 registerModule(NetComm& commInterface, UInt8 technologyId, String name, UInt8& moduleId);
    UInt16 registerDestination(UInt8 moduleId, UInt16& destId);
    UInt16 unRegisterDestination(UInt8 moduleId, UInt16& destId);
    UInt16 reportDestinations(UInt8 moduleId, UInt16 maxLen, UInt16 offset, UInt16Array& destinations);
    UInt16 reportGroups(UInt8 moduleId, UInt16 maxLen, UInt16 offset, UInt16Array& groups);
};

#endif /* MODULECOMMUNICATIONS_REGISTRATION_H_ */
