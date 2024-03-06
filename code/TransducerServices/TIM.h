/*
 * TIM.h
 *
 *  Created on: 07/07/2022
 *      Author: jmotp
 */

#ifndef TRANSDUCERSERVICES_TIM_H_
#define TRANSDUCERSERVICES_TIM_H_

#include <TransducerServices/TransducerChannelManager.h>
#include <TransducerServices/SPITransducerChannel.h>
#include <TransducerServices/CommandCodes.h>
#include <ti/sysbios/knl/Task.h>
#include <config.h>
#include <xdc/runtime/Error.h>
#include "driverlib/timer.h"

#include "driverlib/adc.h"
#include "inc/hw_adc.h"


#include "ModuleCommunications/Comm.h"
#include "ModuleCommunications/Can.h"

#include "isotp/isotp_user.h"


#include "Util/Codec.h"

enum TIMStatus{TIM_INIT, TIM_SLEEP, TIM_ACTIVE};


class TIM
{
public:
    TIM();
    virtual ~TIM();

    UInt16 handleCommand(Uint16 channelId,UInt8 cmdClassId,UInt8 cmdFunctionId,ArgumentArray inArgs, Boolean& hasResponse,ArgumentArray& outArgs);
    void task();

    OctetArray getTEDS();
    UInt16 setTEDS(OctetArray TEDS);

    OctetArray getGeoLocTEDS();

private:
    TIMStatus timStatus = TIM_INIT;
    OctetArray TEDS;
    OctetArray GeoLocTEDS;
    Codec codec;
    TransducerChannelManager transducerChannelManager;
};

#endif /* TRANSDUCERSERVICES_TIM_H_ */
