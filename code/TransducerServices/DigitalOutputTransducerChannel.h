/*
 * ADC.h
 *
 *  Created on: 04/07/2022
 *      Author: jmotp
 */

#ifndef TRANSDUCERSERVICES_DIGITALOUTPUTTRANSDUCERCHANNEL_H_
#define TRANSDUCERSERVICES_DIGITALOUTPUTTRANSDUCERCHANNEL_H_

#include <TransducerServices/TransducerChannel.h>
#include <boardDefinition/linceBoard.h>

class DigitalOutputTransducerChannel: public TransducerChannel
{
public:
     UInt16 getDataSet(Argument &dataSet);
     UInt16 writeDataSet(Argument dataSet);
     DigitalOutputTransducerChannel(LINCE_GPIOName pin);
     virtual ~DigitalOutputTransducerChannel();
private:
     LINCE_GPIOName pinNumber;
};

#endif /* TRANSDUCERSERVICES_SPITRANSDUCERCHANNEL_H_ */
