/*
 * Tcp.c
 *
 *  Created on: 29/02/2024
 *      Author: jmotp
 *
 */


#include "Tcp.h"
#define TCPPACKETSIZE 1024
#define TCPPORT 1000
#define NUMTCPWORKERS 3

    Tcp::Tcp(){

    }
    Tcp::~Tcp(){}
    void Tcp::commTask(){}
    UInt16 Tcp::setId(UInt8 selfId){}
    UInt8 Tcp::getId(void){}

    void Tcp::start(){}

    Void tcpWorker(UArg arg0, UArg arg1)
    {
        SOCKET clientfd = (SOCKET)arg0;
        Int nbytes;
        Bool flag = TRUE;
        void *buffer;
        Error_Block eb;

        fdOpenSession(TaskSelf());

        System_printf("tcpWorker: start clientfd = 0x%x\n", clientfd);
        System_flush();
        /* Make sure Error_Block is initialized */
        Error_init(&eb);

        /* Get a buffer to receive incoming packets. Use the default heap. */
        buffer = Memory_alloc(NULL, TCPPACKETSIZE, 0, &eb);
        if (buffer == NULL) {
            System_printf("tcpWorker: failed to alloc memory\n");
            Task_exit();
        }



        /* Loop while we receive data */
        while (flag) {
            nbytes = recv(clientfd, (char *)buffer, TCPPACKETSIZE, 0);
            if (nbytes > 0) {
                /* Echo the data back */
                send(clientfd, (char *)buffer, nbytes, 0 );
            }
            else {
                fdClose(clientfd);
                flag = FALSE;
            }
        }
        System_printf("tcpWorker stop clientfd = 0x%x\n", clientfd);

        /* Free the buffer back to the heap */
        Memory_free(NULL, buffer, TCPPACKETSIZE);

        fdCloseSession(TaskSelf());
        /*
         *  Since deleteTerminatedTasks is set in the cfg file,
         *  the Task will be deleted when the idle task runs.
         */
        Task_exit();
    }

    void initTCP(int arg0){

            SOCKET lSocket;
            struct sockaddr_in sLocalAddr;
            SOCKET clientfd;
            struct sockaddr_in client_addr;
            Int addrlen=sizeof(client_addr);
            Int optval;
            Int optlen = sizeof(optval);
            Int status;
            Task_Handle taskHandle;
            Task_Params taskParams;
            Error_Block eb;

            fdOpenSession(TaskSelf());

            lSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
            if (lSocket < 0) {
                System_printf("tcpHandler: socket failed\n");
                System_flush();
                Task_exit();
                return;
            }

            memset((char *)&sLocalAddr, 0, sizeof(sLocalAddr));
            sLocalAddr.sin_family = AF_INET;
            //sLocalAddr.sin_len = sizeof(sLocalAddr);
            sLocalAddr.sin_addr.s_addr = htonl(INADDR_ANY);
            sLocalAddr.sin_port = htons(123);

            status = NDK_bind(lSocket, (struct sockaddr *)&sLocalAddr, sizeof(sLocalAddr));
            if (status < 0) {
                System_printf("tcpHandler: bind failed\n");
                System_printf("%d", fdError());
                System_flush();

                //fdClose(lSocket);
                Task_exit();
                return;
            }

            if (listen(lSocket, 3) != 0){
                System_printf("tcpHandler: listen failed\n");
                System_flush();

                //fdClose(lSocket);
                Task_exit();
                return;
            }

            if (setsockopt(lSocket, SOL_SOCKET, SO_KEEPALIVE, &optval, optlen) < 0) {
                System_printf("tcpHandler: setsockopt failed\n");
                System_flush();

                //fdClose(lSocket);
                Task_exit();
                return;
            }

            while (TRUE) {
                /* Wait for incoming request */
                clientfd = accept(lSocket, (struct sockaddr*)&client_addr, &addrlen);
                System_printf("tcpHandler: Creating thread clientfd = %d\n", clientfd);
                System_flush();


                /* Init the Error_Block */
                Error_init(&eb);

                /* Initialize the defaults and set the parameters.*/
                Task_Params_init(&taskParams);
                taskParams.arg0 = (UArg)clientfd;
                taskParams.stackSize = 1024;
                taskParams.priority = 1;
                taskHandle = Task_create((Task_FuncPtr)tcpWorker, &taskParams, &eb);

                if (taskHandle == NULL) {
                    System_printf("tcpHandler: Failed to create new Task\n");
                    System_printf("%d\n", fdError());
                    System_flush();

            }

        }
    }

    UInt16 Tcp::init(){
        return;
    }
    UInt16 Tcp::shutdown() {}
    UInt16 Tcp::sleep(TimeDuration duration) {}
    UInt16 Tcp::wakeup(){}
    UInt16 Tcp::setLocalConfiguration(ArgumentArray params ){}
    UInt16 Tcp::getLocalConfiguration( ArgumentArray& params){}
    UInt16 Tcp::sendLocalCommand(UInt8 cmdClassId, UInt8 cmdFunctionId, ArgumentArray inArgs, ArgumentArray& outArgs){}
    UInt16 Tcp::describe( UInt8& logicalType, UInt8& physicalType, String& name){}
    UInt16 Tcp::sendMessage(const uint32_t arbitration_id, const uint8_t* data, const uint8_t size){}
    UInt16 Tcp::open( UInt16 destId, Boolean twoWay, UInt16& maxPayloadLen, UInt16& commId){}
    UInt16 Tcp::openQoS( UInt16 destId, Boolean twoWay, UInt16& maxPayloadLen, UInt16& commId, QosParams& qosParams){}
    UInt16 Tcp::close( UInt16 commId){}
    UInt16 Tcp::readMsg( UInt16 commId, TimeDuration timeout, UInt32& len, OctetArray& payload, Boolean& last){}
    UInt16 Tcp::readRsp(UInt16 commId, TimeDuration timeout, UInt16 msgId, UInt32 maxLen, OctetArray& payload, Boolean& last){}
    UInt16 Tcp::writeMsg(UInt16 commId, TimeDuration timeout, OctetArray payload,  Boolean last, UInt16 msgId){}
    UInt16 Tcp::writeRsp(UInt16 commId, TimeDuration timeout, OctetArray payload,  Boolean last){

    }
    UInt16 Tcp::flush( UInt16 commId){}
    UInt16 Tcp::readSize( UInt16 commId, UInt32& cacheSize){}
    UInt16 Tcp::setPayloadSize( UInt16 commId, UInt32 size){}
    UInt16 Tcp::abort(UInt16 commId){}
    UInt16 Tcp::commStatus(UInt16 commId, UInt16 msgId, UInt16& statusCode ){}
    UInt16 Tcp::discoverDestinations(){}
    UInt16 Tcp::joinGroup( UInt16 groupId, UInt16 destId){}
    UInt16 Tcp::leaveGroup( UInt16 groupId, UInt16 destId){}
    UInt16 Tcp::lookupDestId( UInt16 commId, UInt16& destId){}
    UInt16 Tcp::setRemoteConfiguration( UInt16 commId, TimeDuration timeout, ArgumentArray params){}
    UInt16 Tcp::getRemoteConfiguration( UInt16 commId, TimeDuration timeout, ArgumentArray& params){}
    UInt16 Tcp::sendRemoteCommand(UInt16 commId, TimeDuration timeout, UInt8 cmdClassId, UInt8 cmdFunctionId, ArgumentArray inArgs, ArgumentArray& outArgs){}

   // virtual UInt16 registerNetReceive(NetReceive &netReceive);

    enum {SEND_IDLE,SENDING,SENT} sendingCommState = SEND_IDLE, nextSendingCommState = SEND_IDLE;
    enum {RECEIVE_IDLE,RECEIVING,RECEIVED} receivingCommState = RECEIVE_IDLE, nextReceivingCommState = RECEIVE_IDLE;
