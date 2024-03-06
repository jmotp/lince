/*
 * ADC.cpp
 *
 *  Created on: 04/07/2022
 *      Author: jmotp
 */

#include <TransducerServices/SPITransducerChannel.h>



SPITransducerChannel::SPITransducerChannel(UInt16 pin)
{
    this->pin = pin;
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    while(!(SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA)))
    {
    }
    GPIOPinConfigure(GPIO_PA2_SSI0CLK);
    //GPIOPinConfigure(GPIO_PA3_SSI0FSS);
    /**GPIOPinConfigure(GPIO_PA4_SSI0RX);
    GPIOPinConfigure(GPIO_PA5_SSI0TX);**/

    GPIOPinTypeSSI(GPIO_PORTA_BASE, GPIO_PIN_2| GPIO_PIN_4|GPIO_PIN_5);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_SSI0);
    GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, pin);
    GPIOPinWrite(GPIO_PORTA_BASE, pin, 1);


    SSIConfigSetExpClk(SSI0_BASE, SysCtlClockGet(), SSI_FRF_MOTO_MODE_1, SSI_MODE_MASTER, 1000000, 8);
    SSIEnable(SSI0_BASE);
    uint32_t data;
    SSIDataGetNonBlocking(SSI0_BASE, &data);


}
//    SSIIntRegister(SSI0_BASE,SPITask);
//    SSIIntEnable(SSI0_BASE,SSI_RXFF|SSI_TXFF|SSI_TXEOT);
//    IntEnable(INT_SSI0);
//    SSIEnable(SSI0_BASE);


    // TODO Auto-generated constructor stub

//}



UInt16 SPITransducerChannel::writeDataSet(Argument dataSet){
    return 0;
}


UInt16 SPITransducerChannel::getDataSet(Argument &dataSet){
    uint32_t data[4]={0,0,0,0};
    uint8_t count = 4;
//    System_printf("%x ",count);

    while(count != 0)
    {
        GPIOPinWrite(GPIO_PORTA_BASE, pin, 0);

        count--;
        SSIDataPut(SSI0_BASE, 0x00);
        // Wait for the data to be transmitted out of the SSI3 by checking on
        // the busy status from the SSI controller
        while(SSIBusy(SSI0_BASE));

        SSIDataGet(SSI0_BASE, &data[count]);

//        System_printf("%x ",data[count]);
    }
//    System_printf("\n");
    GPIOPinWrite(GPIO_PORTA_BASE, pin, 0xFF); //CS


    MAX31855Sensor.thermocouple_temp = ((((data[3]) << 8) | ((data[2]) & 0xFC))>> 2); // Retrieve 2's complement 14 MSbits (which includes 2 fractional bits)
    MAX31855Sensor.therm_fault = (data[2]) & 0x01; // D16
    MAX31855Sensor.internal_temp = (int)((((data[1]) << 8) | ((data[0]) & 0xF0))>> 4);
    MAX31855Sensor.therm_fault_details = (data[0]) & 0x07;

    if(MAX31855Sensor.thermocouple_temp >= 0)
    {
    MAX31855Sensor.sign = 1;
    }
    else
    {
    MAX31855Sensor.thermocouple_temp = ~MAX31855Sensor.thermocouple_temp + 1; // Take 2's complement
    MAX31855Sensor.sign = 0;
    }
//    System_printf("External %x\n",MAX31855Sensor.thermocouple_temp);
//    System_printf("Internal %x\n",MAX31855Sensor.internal_temp);
//    System_printf("Fault %x\n",MAX31855Sensor.therm_fault_details);
//    System_printf("Returned arg %d\n",MAX31855Sensor.thermocouple_temp);

    Float32 output_data = float(MAX31855Sensor.thermocouple_temp);
    output_data=output_data/4;
    fprintf(stdout,"%f\n",output_data);
    dataSet = Argument(Argument::Float32_TC,(void *)&output_data);
    return 0;


}



SPITransducerChannel::~SPITransducerChannel()
{
    // TODO Auto-generated destructor stub
}



