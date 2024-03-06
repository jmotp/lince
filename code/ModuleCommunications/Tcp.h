/*
 * Tcp.h
 *
 *  Created on: 29/02/2024
 *      Author: jmotp
 */

#ifndef MODULECOMMUNICATIONS_TCP_H_
#define MODULECOMMUNICATIONS_TCP_H_

#include <ModuleCommunications/NetComm.h>
#include <ti/sysbios/knl/Task.h>
#include <xdc/runtime/Error.h>

#include <queue>
#include <vector>
#include <isotp/isotp.h>
#include <config.h>
#include <map>

#include <ti/ndk/inc/netmain.h>
#include <ti/ndk/inc/_stack.h>

#include <xdc/runtime/Memory.h>
//#include <ti/ndk/inc/socket.h>
//#include <ti/ndk/inc/socketndk.h>

void initTCP(int arg0);

class Tcp : public NetComm
{
public:

    Tcp();
    virtual ~Tcp();
    void commTask();
    UInt16 setId(UInt8 selfId);
    UInt8 getId(void);

    void start();

    UInt16 init();
    UInt16 shutdown() ;
    UInt16 sleep(TimeDuration duration) ;
    UInt16 wakeup();
    UInt16 setLocalConfiguration(ArgumentArray params );
    UInt16 getLocalConfiguration( ArgumentArray& params);
    UInt16 sendLocalCommand(UInt8 cmdClassId, UInt8 cmdFunctionId, ArgumentArray inArgs, ArgumentArray& outArgs);
    UInt16 describe( UInt8& logicalType, UInt8& physicalType, String& name);
    UInt16 sendMessage(const uint32_t arbitration_id, const uint8_t* data, const uint8_t size);
    UInt16 open( UInt16 destId, Boolean twoWay, UInt16& maxPayloadLen, UInt16& commId);
    UInt16 openQoS( UInt16 destId, Boolean twoWay, UInt16& maxPayloadLen, UInt16& commId, QosParams& qosParams);
    UInt16 close( UInt16 commId);
    UInt16 readMsg( UInt16 commId, TimeDuration timeout, UInt32& len, OctetArray& payload, Boolean& last);
    UInt16 readRsp(UInt16 commId, TimeDuration timeout, UInt16 msgId, UInt32 maxLen, OctetArray& payload, Boolean& last);
    UInt16 writeMsg(UInt16 commId, TimeDuration timeout, OctetArray payload,  Boolean last, UInt16 msgId);
    UInt16 writeRsp(UInt16 commId, TimeDuration timeout, OctetArray payload,  Boolean last);
    UInt16 flush( UInt16 commId);
    UInt16 readSize( UInt16 commId, UInt32& cacheSize);
    UInt16 setPayloadSize( UInt16 commId, UInt32 size);
    UInt16 abort(UInt16 commId);
    UInt16 commStatus(UInt16 commId, UInt16 msgId, UInt16& statusCode );
    UInt16 discoverDestinations();
    UInt16 joinGroup( UInt16 groupId, UInt16 destId);
    UInt16 leaveGroup( UInt16 groupId, UInt16 destId);
    UInt16 lookupDestId( UInt16 commId, UInt16& destId);
    UInt16 setRemoteConfiguration( UInt16 commId, TimeDuration timeout, ArgumentArray params);
    UInt16 getRemoteConfiguration( UInt16 commId, TimeDuration timeout, ArgumentArray& params);
    UInt16 sendRemoteCommand(UInt16 commId, TimeDuration timeout, UInt8 cmdClassId, UInt8 cmdFunctionId, ArgumentArray inArgs, ArgumentArray& outArgs);

   // virtual UInt16 registerNetReceive(NetReceive &netReceive);

    enum {SEND_IDLE,SENDING,SENT} sendingCommState = SEND_IDLE, nextSendingCommState = SEND_IDLE;
    enum {RECEIVE_IDLE,RECEIVING,RECEIVED} receivingCommState = RECEIVE_IDLE, nextReceivingCommState = RECEIVE_IDLE;


};


#endif /* MODULECOMMUNICATIONS_TCP_H_ */
