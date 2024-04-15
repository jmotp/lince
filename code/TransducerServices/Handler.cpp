/*
 * Handler.cpp
 *
 *  Created on: 21/06/2022
 *      Author: jmotp
 */

#include "TransducerServices/Handler.h"
#include <memory>
#include <ModuleCommunications/Can.h>
Handler::Handler()
{
    vector<unsigned char> vec = {0x00,0x00,0x00,0x24,0x03,0x04,0x00,0x01,0x01,0x01,0x04,0x0a,0x82,0xc0,0xf9,0x74,0x48,0x81,0xf5,0x62,0x2e,0x78,0x0a,0x04,0x3f,0x00,0x00,0x00,0x0c,0x04,0xc0,0xa0,0x00,0x00,0x0d,0x02,0x00,0x02,0xf8,0x82};
    TEDS.append(vec.begin(),vec.end());
    // TODO Auto-generated constructor stub

}

Handler::~Handler()
{
    // TODO Auto-generated destructor stub
}

UInt16 Handler::handleCommand(UInt16 channelId,UInt8 cmdClassId,UInt8 cmdFunctionId,ArgumentArray inArgs, Boolean& hasResponse,ArgumentArray& outArgs){
    extern TransducerChannelManager transducerChannelManager;
    System_printf("Command Received %d %d\n", cmdClassId, cmdFunctionId);
    System_flush();
    if(cmdClassId == COMMON_CMD){
        if(cmdFunctionId == READ_TEDS_SEGMENT){
            hasResponse = 1;
//            System_printf("TEDS_arg type: %d\n", TEDS_arg->type);
            UInt32 offset = 0;
             //Argument TEDS_offset(Argument::UInt32_TC,(void*)&offset);
             //Argument TEDS_arg(Argument::Octet_Array_TC, (void *)&TEDS);

            outArgs.putByIndex(0, Argument(Argument::UInt32_TC,(void*)&offset));
            outArgs.putByIndex(1, Argument(Argument::Octet_Array_TC, (void *)&TEDS));

//            fprintf(stdout,"outArgs size: %d\n", outArgs.size());
//            fflush(stdout);

        }
    }else if(cmdClassId == XDCR_OPERATE){
        TransducerChannel* transducerChannel = transducerChannelManager.getTransducerChannel(channelId);
        if(cmdFunctionId == READ_TRANSDUCERCHANNEL_DATA){
            hasResponse=1;
            Argument arg;
            transducerChannel->getDataSet(arg);
            arg.print();
            UInt32 offset = 0;

            outArgs.putByIndex(0, Argument(Argument::UInt32_TC,(void*)&offset));
            outArgs.putByIndex(1, arg);
            System_printf("Handling Here\n");
        }else if(cmdFunctionId == WRITE_TRANSDUCERCHANNEL_DATA){
            hasResponse=0;
            Argument arg;
            inArgs.getByIndex(1, arg);
            System_printf("Command write DataSet\n");
            System_flush();
            transducerChannel->writeDataSet(arg);

        }
    }else if(cmdClassId == 0x80){
            if(cmdFunctionId == 0x02){
                hasResponse=1;
                extern Can can1;
                UInt8 canId= can1.getId();
                System_printf("Discovery from NCAP: sending Id %d", canId);
                outArgs.putByIndex(0, Argument(Argument::UInt8_TC,(void*)&canId));
                System_printf("Handling Here\n");
            }
        }
    return 0;
}

