/*
 * DigitalInputTransducerChannel.cpp
 *
 *  Created on: 04/03/2024
 *      Author: jmotp
 */

#include <TransducerServices/DigitalOutputTransducerChannel.h>

UInt16 DigitalOutputTransducerChannel::writeDataSet(Argument dataSet){
    bool output_data = dataSet._valueBoolean;
    writeGPIO(this->pinNumber, output_data);
    return 0;
}

UInt16 DigitalOutputTransducerChannel::getDataSet(Argument &dataSet){
    return 0;
}

DigitalOutputTransducerChannel::DigitalOutputTransducerChannel(LINCE_GPIOName pinNumber){
    this->pinNumber = pinNumber;


}

DigitalOutputTransducerChannel::~DigitalOutputTransducerChannel(){

}
