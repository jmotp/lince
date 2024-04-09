/*
 * Registration.h
 *
 *  Created on: 29/06/2022
 *      Author: jmotp
 */

#ifndef MODULECOMMUNICATIONS_REGISTRATION_H_
#define MODULECOMMUNICATIONS_REGISTRATION_H_

#include <Args/Types.h>
#include <ModuleCommunications/Comm.h>

class Registration
{
public:
    Registration();
    virtual ~Registration();
    UInt16 unRegisterModule(UInt8 moduleId);
    UInt16 reportModules(UInt8 maxLen, UInt8 offset, UInt8Array* moduleIds);
    UInt16 getCommModule(UInt8 moduleId, Comm* commObject, UInt8* type, UInt8* technologyId);
};

#endif /* MODULECOMMUNICATIONS_REGISTRATION_H_ */
