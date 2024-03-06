/*
 * ADC.h
 *
 *  Created on: 04/07/2022
 *      Author: jmotp
 */

#ifndef TRANSDUCERSERVICES_SPITRANSDUCERCHANNEL_H_
#define TRANSDUCERSERVICES_SPITRANSDUCERCHANNEL_H_

#include <TransducerServices/TransducerChannel.h>
#include <boardDefinition/linceBoard.h>

class DigitalInputTransducerChannel: public TransducerChannel
{
public:
     UInt16 getDataSet(Argument &dataSet);
     DigitalInputTransducerChannel(LINCE_GPIOName pin);
     virtual ~DigitalInputTransducerChannel();
private:
     LINCE_GPIOName pinNumber;
};

#endif /* TRANSDUCERSERVICES_SPITRANSDUCERCHANNEL_H_ */
