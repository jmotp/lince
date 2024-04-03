#ifndef __ISOTP_USER_H__
#define __ISOTP_USER_H__


#define xdc__nolocalstring
#include <xdc/std.h>
#include <xdc/runtime/System.h>
#include "driverlib/can.h"
#include "driverlib/interrupt.h"
#include "inc/hw_can.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "inc/hw_ints.h"
#include "driverlib/uart.h"
#include <utils/uartstdio.h>
#include <cstring>
#include "Args/Types.h"
#include "Args/ArgumentArray.h"
#include "isotp_user.h"
#include <ModuleCommunications/Can.h>
extern "C"{
#include "driverlib/systick.h"

}
#include "inc/hw_ints.h"
#include "inc/hw_nvic.h"
#include "inc/hw_types.h"



#include <ti/sysbios/knl/Task.h>
uint32_t millis=0;
uint32_t micros=0;

void SycTickInt(){
    //System_printf("Here\n");
    //System_flush();
    static int count = 0;
    count++;
    micros+=1;
     if(count==1000){
        count=0;
        millis++; //micros++ if period set to F_CPU/1000000
    }
}

void SysTickbegin(){
    uint32_t F_CPU = 120;
    SysTickPeriodSet(F_CPU);
    SysTickIntRegister(SycTickInt);
    SysTickIntEnable();
    SysTickEnable();

}



/* user implemented, print debug message */
void isotp_user_debug(const char* message){
    System_printf("%s\n",message);
    System_flush();
};

/* user implemented, send can message. should return ISOTP_RET_OK when success.
*/

extern Can can1;
int  isotp_user_send_can(const uint32_t arbitration_id,
                         const uint8_t* data, const uint8_t size){
//    System_printf("Message Sent to id %l\n", arbitration_id);
    can1.sendMessage(arbitration_id, data, size);
    return ISOTP_RET_OK;
}

/* user implemented, get millisecond */
uint32_t isotp_user_get_ms(void){
    int * millis_ptr = (int *)&millis;
//    System_printf("Time: %d %d\n",millis_ptr[0],millis_ptr[1] );
    return millis;
}

#endif // __ISOTP_H__

