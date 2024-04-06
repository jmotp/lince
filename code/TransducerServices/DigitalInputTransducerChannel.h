/*
 * ADC.h
 *
 *  Created on: 04/07/2022
 *      Author: jmotp
 */

#ifndef TRANSDUCERSERVICES_DIGITALINPUTTRANSDUCERCHANNEL_H_
#define TRANSDUCERSERVICES_DIGITALINPUTTRANSDUCERCHANNEL_H_

#include <TransducerServices/TransducerChannel.h>
#include <boardDefinition/linceBoard.h>

class DigitalInputTransducerChannel: public TransducerChannel
{
public:
     UInt16 getDataSet(Argument &dataSet);
     DigitalInputTransducerChannel(LINCE_GPIOName pin);
     UInt16 writeDataSet(Argument dataSet);
     virtual ~DigitalInputTransducerChannel();
private:
     LINCE_GPIOName pinNumber;
};

#endif
