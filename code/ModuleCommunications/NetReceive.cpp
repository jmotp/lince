/*
 * NetReceive.cpp
 *
 *  Created on: 15/06/2022
 *      Author: jmotp
 */

#include <ModuleCommunications/NetReceive.h>
#include <cstdio>

NetReceive::NetReceive()
{
    // TODO Auto-generated constructor stub

}

NetReceive::~NetReceive()
{
    // TODO Auto-generated destructor stub
}

//Notify that a Message has arrived
UInt16 NetReceive::notifyMsg( UInt16 rcvCommId, Boolean twoWay, UInt32 payloadLen,UInt32 cacheLen, UInt16 maxPayloadLen, UInt16 status){
    MessageIncomingInfo message = {rcvCommId,twoWay,payloadLen,cacheLen,maxPayloadLen,status};
    messageQueue.push(message);
//    printf("Added one message\n");
    //printf("Queue size: %d\n", messageQueue.size());
    return 0;
}
UInt16 NetReceive::notifyRsp(UInt16 rcvCommId, UInt16 msgId, UInt32 payloadLen,UInt32 cacheLen, UInt16 maxPayloadLen, UInt16 status){
    ResponseIncomingInfo message = {rcvCommId,msgId,payloadLen,cacheLen,maxPayloadLen,status};
    responseQueue.push(message);
//        printf("Added one response\n");
//        printf("Queue size: %d\n", responseQueue.size());
    return 0;
}

Boolean NetReceive::messageAvailable(){
    //printf("Queue size: %d\n", messageQueue.size());
    if(messageQueue.size()>0){
        return 1;
    }
    return 0;
}

Boolean NetReceive::responseAvailable(){
    //printf("Queue size: %d\n", responseQueue.size());
    if(responseQueue.size()>0){
        return 1;
    }
    return 0;
}

MessageIncomingInfo NetReceive::getMessageIncomingInfo(){
//    printf("Message Read\n");
    MessageIncomingInfo stub = messageQueue.front();
    messageQueue.pop();
    return stub;

}

ResponseIncomingInfo NetReceive::getResponseIncomingInfo(){
//    printf("Message Read\n");
    ResponseIncomingInfo stub = responseQueue.front();
    responseQueue.pop();
    return stub;

}


