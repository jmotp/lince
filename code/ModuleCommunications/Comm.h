/*
 * Comm.h
 *
 *  Created on: 14/06/2022
 *      Author: jmotp
 */

#ifndef MODULECOMMUNICATIONS_COMM_H_
#define MODULECOMMUNICATIONS_COMM_H_

#define xdc__nolocalstring
#include <xdc/std.h>
#include <xdc/runtime/System.h>
#include "driverlib/can.h"
#include "driverlib/interrupt.h"
#include "inc/hw_can.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "inc/hw_ints.h"
#include "driverlib/uart.h"
#include <utils/uartstdio.h>
#include <cstring>
#include "Args/Types.h"
#include "Args/ArgumentArray.h"




class Comm{
    public:


    Comm();
    virtual ~Comm();

    virtual UInt16 init()=0;
    virtual UInt16 shutdown() =0;
    virtual UInt16 sleep(TimeDuration duration)=0;
    virtual UInt16 wakeup()=0;
    virtual UInt16 setLocalConfiguration(ArgumentArray params )=0;
    virtual UInt16 getLocalConfiguration( ArgumentArray& params)=0;
    virtual UInt16 sendLocalCommand(UInt8 cmdClassId, UInt8 cmdFunctionId, ArgumentArray inArgs, ArgumentArray& outArgs)=0;
    virtual UInt16 describe( UInt8& logicalType, UInt8& physicalType, String& name)=0;
};










#endif /* MODULECOMMUNICATIONS_COMM_H_ */
