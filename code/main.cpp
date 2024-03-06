/*
 * Copyright (c) 2015, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *
 */
/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/runtime/System.h>

#define xdc__nolocalstring

#include <driverlib/sysctl.h>
#include <ModuleCommunications/Can.h>
#include <ModuleCommunications/Tcp.h>

#include "ModuleCommunications/NetReceive.h"

#include <ti/sysbios/knl/Clock.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>

#include <xdc/std.h>
#include <xdc/cfg/global.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/Memory.h>
#include <xdc/runtime/System.h>


/* TI-RTOS Header files */
// #include <ti/drivers/EMAC.h>
#include <ti/drivers/GPIO.h>
// #include <ti/drivers/I2C.h>
// #include <ti/drivers/SDSPI.h>
// #include <ti/drivers/SPI.h>
// #include <ti/drivers/UART.h>
// #include <ti/drivers/USBMSCHFatFs.h>
// #include <ti/drivers/Watchdog.h>
// #include <ti/drivers/WiFi.h>

#include "Board.h"
#include "boardDefinition/pinCfg.h"
#define TASKSTACKSIZE   512

#include "TransducerServices/TIM.h"

Can can1;
NetReceive netReceive;



Task_Struct task0Struct, readTaskStruct, canTaskStruct, timTaskStruct, tcpTaskStruct;
Char task0Stack[TASKSTACKSIZE], task1Stack[TASKSTACKSIZE], task2Stack[3056], timTaskStack[2048], tcpTaskStack[10240];

void CanTaskWrapper() {
    can1.commTask();
}



/*
 *  ======== heartBeatFxn ========
 *  Toggle the Board_LED0. The Task_sleep is determined by arg0 which
 *  is configured for the heartBeat Task instance.
 */
Void heartBeatFxn(UArg arg0, UArg arg1)
{
    while (1) {
        Task_sleep((unsigned int)arg0);
        GPIO_toggle(Board_LED0);
        int i;
        for(i=DIGITAL_OUT_1_1; i<= DIGITAL_OUT_2_4;i++){
            Task_sleep(100);
            GPIO_toggle(i);
        }
        uint32_t value = readADC();
        //can1.sendMessage(1, "Hello\0", 6);

    }
}

Void readDigitalInputs(){
    while(1){
        Task_sleep(1000);
        uint8_t read = 0;
        int i;
        for(i=DIGITAL_IN_1; i<= DIGITAL_IN_8;i++){
            read = read << 1 | GPIO_read(i);
        }
        System_printf("%d\n", read);
        System_flush();
    }
}

TIM tim;

void timTaskWrapper() {
    tim.task();
}


void clockHandler1(){


    //Task_yield();
}



/*
 *  ======== main ========
 */
int main(void){
    Task_Params taskParams, taskParams2, taskParams3, timTaskParams;
    /* Call board init functions */
    Board_initGeneral();
    Board_initEMAC();
    Board_initGPIO();
    // Board_initI2C();
    // Board_initSDSPI();
    // Board_initSPI();
    // Board_initUART();
    // Board_initUSB(Board_USBDEVICE);
    // Board_initUSBMSCHFatFs();
    // Board_initWatchdog();

    Error_Block eb;
    //PortFunctionInit();
    Error_init(&eb);


    initADC();


    Clock_Params clockParams;
    Clock_Params_init(&clockParams);
     clockParams.period = 10;/* every 10 Clock ticks */
     clockParams.startFlag = TRUE;/* start immediately */
     Clock_Handle myClk0 = Clock_create((Clock_FuncPtr)clockHandler1, 2000, &clockParams, &eb);
     if (myClk0 == NULL) {
     System_abort("Clock0 create failed");
     }
     Clock_tickStart();
    /* Construct BIOS objects */




    /* Construct heartBeat Task  thread */
    Task_Params_init(&taskParams);
    taskParams.arg0 = 1000;
    taskParams.stackSize = 512;
    taskParams.stack = &task0Stack;
    timTaskParams.priority = 2;
    //Task_construct(&task0Struct, (Task_FuncPtr)heartBeatFxn, &taskParams, NULL);

    /* Construct clock Task thread */
    Task_Params_init(&timTaskParams);
    timTaskParams.stackSize = 2048;
    timTaskParams.stack = &timTaskStack;
    timTaskParams.priority = 1;
    //Task_construct(&timTaskStruct, (Task_FuncPtr)timTaskWrapper, &timTaskParams, NULL);


    Task_Params_init(&taskParams2);
    taskParams2.stackSize = 512;
    taskParams2.stack = &task1Stack;
    timTaskParams.priority = 2;
    //Task_construct(&readTaskStruct, (Task_FuncPtr)readDigitalInputs, &taskParams2, NULL);



    GPIO_write(Board_LED0, Board_LED_ON);
    int i;
    for(i=DIGITAL_OUT_1_1; i<= DIGITAL_OUT_2_4;i++){
        GPIO_write(i,1);
    }

    System_printf("System up.");
    System_flush();

    uint32_t ui32SysClock = SysCtlClockFreqSet(SYSCTL_XTAL_25MHZ | SYSCTL_OSC_MAIN | SYSCTL_USE_PLL | SYSCTL_CFG_VCO_480, 120000000);
    System_printf("Clock: %d %d\n", ui32SysClock, SysCtlClockGet());


    can1.init();
    can1.registerNetReceive(&netReceive);


    //tcp1.init();

    Task_Params_init(&taskParams3);
    taskParams3.stackSize = 3056;
    taskParams3.stack = &task2Stack;
    taskParams3.priority = 4;

    //Task_construct(&canTaskStruct, (Task_FuncPtr)CanTaskWrapper, &taskParams3, NULL);


    /* Start BIOS */
    BIOS_start();
    //can1.sendMessage(1, "Hello\0", 6);

    //while(1);



    return (0);
}

extern "C" void startTCP(void)
    {

        Task_Params tcpTaskParams;
        Error_Block eb;
        Task_Params_init(&tcpTaskParams);
        tcpTaskParams.stackSize = 10240;
        tcpTaskParams.priority = 1;
        tcpTaskParams.arg0 = 123;
        Task_construct(&tcpTaskStruct,(Task_FuncPtr)initTCP, &tcpTaskParams, &eb);

}

