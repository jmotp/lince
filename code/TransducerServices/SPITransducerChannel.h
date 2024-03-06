/*
 * ADC.h
 *
 *  Created on: 04/07/2022
 *      Author: jmotp
 */

#ifndef TRANSDUCERSERVICES_SPITRANSDUCERCHANNEL_H_
#define TRANSDUCERSERVICES_SPITRANSDUCERCHANNEL_H_

#include <TransducerServices/TransducerChannel.h>
#include <driverlib/ssi.h>
#include "inc/hw_ssi.h"
#include "inc/hw_memmap.h"
#include "inc/hw_ints.h"
#include "driverlib/sysctl.h"
#include <cstdio>
#include "driverlib/interrupt.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"

struct MAX31855 {
 volatile int16_t thermocouple_temp; // Right-justified for 14-bit result (D31..D18)
 volatile uint8_t therm_fault; //Just D16 (so 1 bit)
 volatile int16_t internal_temp; // Right-justified for 12-bit result (D15...D4)
 volatile uint8_t therm_fault_details; // 3 bits : D2...D0 (SCVcc, SCGnd, OC)
 volatile int8_t sign; // Indicate if thermocouple temperature is positive or negative
 };


class SPITransducerChannel: public TransducerChannel
{
private:
    struct MAX31855 MAX31855Sensor;
    UInt16 pin;

public:
    UInt16 getDataSet(Argument &dataSet);
    UInt16 writeDataSet(Argument dataSet);
    SPITransducerChannel(UInt16 pin);
    virtual ~SPITransducerChannel();
};

#endif /* TRANSDUCERSERVICES_SPITRANSDUCERCHANNEL_H_ */
