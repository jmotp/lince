/*
 * DigitalInputTransducerChannel.cpp
 *
 *  Created on: 04/03/2024
 *      Author: jmotp
 */

#include <TransducerServices/DigitalInputTransducerChannel.h>

UInt16 DigitalInputTransducerChannel::getDataSet(Argument &dataSet){
    bool output_data = readGPIO(this->pinNumber);
    dataSet = Argument(Argument::Boolean_TC,(void *)&output_data);
    return 0;
}

DigitalInputTransducerChannel::DigitalInputTransducerChannel(LINCE_GPIOName pinNumber){
    this->pinNumber = pinNumber;


}

DigitalInputTransducerChannel::~DigitalInputTransducerChannel(){

}
