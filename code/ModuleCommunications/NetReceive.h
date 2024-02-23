/*
 * NetReceive.h
 *
 *  Created on: 15/06/2022
 *      Author: jmotp
 */

#ifndef MODULECOMMUNICATIONS_NETRECEIVE_H_
#define MODULECOMMUNICATIONS_NETRECEIVE_H_

#include <ModuleCommunications/Receive.h>
#include <Args/Types.h>
#include <queue>

typedef struct messageIncomingInfo{
    UInt16 rcvCommId;
    Boolean twoWay;
    UInt32 payloadLen;
    UInt32 cacheLen;
    UInt16 maxPayloadLen;
    UInt16 status;
} MessageIncomingInfo;

typedef struct responseIncomingInfo{
    UInt16 rcvCommId;
    UInt16 msgId;
    UInt32 payloadLen;
    UInt32 cacheLen;
    UInt16 maxPayloadLen;
    UInt16 status;
} ResponseIncomingInfo;

class NetReceive: public Receive
{
public:
    NetReceive();
    virtual ~NetReceive();

    UInt16 abort(UInt16 commId, UInt16 status);

    //Notify that a Message has arrived
    UInt16 notifyMsg( UInt16 rcvCommId, Boolean twoWay, UInt32 payloadLen,UInt32 cacheLen, UInt16 maxPayloadLen, UInt16 status);
    UInt16 notifyRsp( UInt16 rcvCommId, UInt16 msgId, UInt32 payloadLen,UInt32 cacheLen, UInt16 maxPayloadLen, UInt16 status);

    Boolean messageAvailable();
    Boolean responseAvailable();

    MessageIncomingInfo getMessageIncomingInfo();
    ResponseIncomingInfo getResponseIncomingInfo();


    private:
    std::queue<MessageIncomingInfo> messageQueue;
    std::queue<ResponseIncomingInfo> responseQueue;


};

#endif /* MODULECOMMUNICATIONS_NETRECEIVE_H_ */
