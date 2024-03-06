/*
 * TransducerChannelManager.h
 *
 *  Created on: 04/07/2022
 *      Author: jmotp
 */

#ifndef TRANSDUCERSERVICES_TRANSDUCERCHANNELMANAGER_H_
#define TRANSDUCERSERVICES_TRANSDUCERCHANNELMANAGER_H_

#include <TransducerServices/TransducerChannel.h>
#include <map>

class TransducerChannelManager
{

private:
    std::map<int, TransducerChannel*> transducerChannelArray;
    int nextChannelId=1;
public:

    UInt16 registerTransducerChannel(TransducerChannel& transducerChannel);
    TransducerChannel * getTransducerChannel(UInt16 transducerChannelID);
    TransducerChannelManager();
    virtual ~TransducerChannelManager();
};

#endif /* TRANSDUCERSERVICES_TRANSDUCERCHANNELMANAGER_H_ */
