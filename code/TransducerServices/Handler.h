/*
 * Handler.h
 *
 *  Created on: 21/06/2022
 *      Author: jmotp
 */

#ifndef TRANSDUCERSERVICES_HANDLER_H_
#define TRANSDUCERSERVICES_HANDLER_H_

#include "../Args/Types.h"
#include "../Args/ArgumentArray.h"
#include "../Args/Argument.h"
#include "CommandCodes.h"
#include <TransducerServices/TransducerChannelManager.h>
#include <TransducerServices/TransducerChannel.h>


class Handler
{

private:
    OctetArray TEDS;

public:

    Handler();
    virtual ~Handler();

    UInt16 handleCommand(Uint16 channelId,UInt8 cmdClassId,UInt8 cmdFunctionId,ArgumentArray inArgs, Boolean& hasResponse,ArgumentArray& outArgs);


};

#endif /* TRANSDUCERSERVICES_HANDLER_H_ */
