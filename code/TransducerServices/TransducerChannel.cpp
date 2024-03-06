/*
 * TransducerChannel.cpp
 *
 *  Created on: 04/07/2022
 *      Author: jmotp
 */

#include <TransducerServices/TransducerChannel.h>

Codec codec0;

void TransducerChannel::TransducerChannelTask(){

}

OctetArray TransducerChannel::getTransducerChannelTEDS(){
    OctetArray outputTEDS;
    //codec0.TEDS2OctetArray(TransducerChannelTEDS, outputTEDS);

    return TransducerChannelTEDS;
}


UInt16 TransducerChannel::setTransducerChannelTEDS(OctetArray TEDS){
    TransducerChannelTEDS = TEDS;
    return 0;
}

TransducerChannel::TransducerChannel()
{
    vector<UInt8> TEDS_vec = {0x00,0x00,0x00,0x5f,0x03,0x04,0x00,0x03,0x01,0x01,0x0a,0x01,0x01,0x0b,0x01,0x00,0x0c,0x06,0x32,0x01,0x00,0x39,0x01,0x82,0x0d,0x04,0x43,0x69,0x00,0x00,0x0e,0x04,0x43,0xb0,0x80,0x00,0x0f,0x04,0x40,0x00,0x00,0x00,0x10,0x01,0x01,0x12,0x09,0x28,0x01,0x00,0x29,0x01,0x02,0x2a,0x01,0x0c,0x14,0x04,0x3d,0xcc,0xcc,0xcd,0x16,0x04,0x37,0xd1,0xb7,0x17,0x17,0x04,0x3d,0xcc,0xcc,0xcd,0x18,0x04,0x41,0xf0,0x00,0x00,0x19,0x04,0x37,0xd1,0xb7,0x17,0x1a,0x04,0x40,0xa0,0x00,0x00,0x1f,0x03,0x30,0x01,0x02,0xef,0x2c};
    TransducerChannelTEDS.append(TEDS_vec.begin(),TEDS_vec.end());
    //codec0.octetArray2TEDS(TransducerChannelTEDS,TransducerChannelTEDSstr);
    // TODO Auto-generated constructor stub

}

TransducerChannel::~TransducerChannel()
{
    // TODO Auto-generated destructor stub
}

TransducerChannelStatus TransducerChannel::getStatus(){
    return transducerChannelStatus;
}

