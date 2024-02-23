/*
 * NetComm.cpp
 *
 *  Created on: 14/06/2022
 *      Author: jmotp
 */

#include <ModuleCommunications/NetComm.h>


NetComm::NetComm()
{

    // TODO Auto-generated constructor stub

}

NetComm::~NetComm()
{
    // TODO Auto-generated destructor stub
}

UInt16 NetComm::registerNetReceive(NetReceive *netReceive){
    this->netReceive = netReceive;
}
