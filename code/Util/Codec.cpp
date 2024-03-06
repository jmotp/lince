/*
 * Codec.cpp
 *
 *  Created on: 03/06/2022
 *      Author: jmotp
 */

#include "Util/Codec.h"

Codec::Codec()
{
    // TODO Auto-generated constructor stub

}

Codec::~Codec()
{
    // TODO Auto-generated destructor stub
}

UInt16 Codec::encodeCommand(UInt16 channelId, UInt8 cmdClassId, UInt8 cmdFunctionId, ArgumentArray inArgs, OctetArray& payload){

    std::stringstream sstream;
    OctetArray buffer;
    swapByteOrder(channelId);
    sstream.write((const char *)&channelId,2);
    sstream.write((const char *)&cmdClassId,1);
    sstream.write((const char *)&cmdFunctionId,1);
    argumentArray2OctetArray(inArgs,buffer);

    UInt16 len = buffer.size();
//    fprintf(stdout,"ArgumentArray %d\n",buffer.size());

    swapByteOrder(len);
    sstream.write((const char *)&len,2);
    sstream.write(buffer.c_str(),buffer.size());
    payload = sstream.str();
    return 0;
}


UInt16 Codec::encodeHandshakeMessage(UInt16 channelId, UInt8 cmdClassId, UInt8 cmdFunctionId, UInt8 random, OctetArray& payload){
    std::stringstream sstream;
    OctetArray buffer;
    swapByteOrder(channelId);
    sstream.write((const char *)&channelId,2);
    sstream.write((const char *)&cmdClassId,1);
    sstream.write((const char *)&cmdFunctionId,1);
    sstream.write((const char *)&random,1);
    payload = sstream.str();

    return 0;
}



UInt16 Codec::encodeResponse(Boolean successFlag,ArgumentArray& outArgs, OctetArray& payload){
    std::stringstream sstream;
    OctetArray buffer;
    sstream.write((const char*)&successFlag,1);
    argumentArray2OctetArray(outArgs,buffer);
//    fprintf(stdout,"Octet Array size: %d\n", buffer.size());
    UInt16 len= buffer.size();
    swapByteOrder(len);
    sstream.write((const char *)&len,2);
    sstream.write(buffer.c_str(),buffer.size());
    payload = sstream.str();

    return 0;


}



UInt16 Codec::decodeCommand(OctetArray payload, UInt16& channelId, UInt8& cmdClassId, UInt8& cmdFunctionId, ArgumentArray& inArgs){

    channelId =payload[0]*256 + payload[1];
    cmdClassId =payload[2];
    cmdFunctionId =payload[3];

    UInt16 len = 0;
    if(payload.size()<=4){
        len = 0;
    }
    else{
        len = payload[4]*256 + payload[5];

    }
//    System_printf("%x %x %d\n",payload[4],payload[5],len);



    if(len>0){
//        System_printf("Here %d\n", payload.size());
        octetArray2ArgumentArray(inArgs,payload.substr(6));
    }

    return 0;
}

UInt16 Codec::decodeResponse(OctetArray payload, Boolean& successFlag,ArgumentArray& outArgs){
////        for(char chr: payload){
//            fprintf(stdout," %x",chr);
//        }
//       fprintf(stdout,": Response\n");
//        fflush(stdout);
    successFlag =payload[0];

    UInt16 len = payload[1]*256 + payload[2];

    if(len>0){
        octetArray2ArgumentArray(outArgs,payload.substr(3));
    }

    return 0;

}

UInt16 Codec::decodeHandshakeResponse(OctetArray payload, Boolean& successFlag,UInt8& random, UInt8& Id){
    successFlag =payload[0];

    random = payload[1];
    Id = payload[2];

    return 0;
}

 UInt16 Codec::argumentArray2OctetArray(ArgumentArray& inArgs, OctetArray& payload){
//    fprintf(stdout,"argumentArray2OctetArray inArgs size %d\n", inArgs.size());
    std::stringstream sstream;
    vector<UInt16> inArgsIndexes;

    inArgs.getIndexes(inArgsIndexes);
    String result;
    Argument arg;
//    fprintf(stdout,"argumentArray2OctetArray inArgs size %d\n", inArgs.size());
    for (UInt16 index : inArgsIndexes){
        inArgs.getByIndex(index, arg);
//        arg.print();
        arg.write(sstream);
    }

    payload = sstream.str();

//    for(char chr: payload){
//        fprintf(stdout," %x",chr);
//    }
//   fprintf(stdout,"\n");
//    fflush(stdout);


    return 0;
}

 UInt16 Codec::octetArray2ArgumentArray(ArgumentArray& outArgs, OctetArray payload){
    std::stringstream sstream;
//    System_printf("Here\n");
//    System_printf("%d\n", payload.size());
    UInt8 index=0;

//    for(char chr: payload){
//        fprintf(stdout," %x",chr);
//    }
//    fprintf(stdout,"\n");
//    fflush(stdout);
//    System_flush();
    uint16_t size=payload.size();
    sstream<<payload;

    while(size>0){
        Argument arg;
        size-= arg.read(sstream);
        outArgs.putByIndex(index++, arg);
    }

    return 0;
}

 UInt16 Codec::octetArray2TEDS(ArgumentArray& TEDSArray, OctetArray payload){
    std::stringstream sstream;

    UInt8 index=0;

    uint16_t size=payload.size();
    sstream<<payload;

    while(size>0){
        Argument arg;
        size-= arg.read(sstream);
        UInt8 TEDScode;
        sstream.read((char *)&TEDScode, 1);
        TEDSArray.putByIndex(TEDScode, arg);
    }

    return 0;
}

 UInt16 Codec::TEDS2OctetArray(ArgumentArray& TEDSArray, OctetArray& payload){
//    fprintf(stdout,"argumentArray2OctetArray inArgs size %d\n", inArgs.size());
    std::stringstream sstream;
    TEDSArray.writeAsTEDS(sstream);
    payload = sstream.str();



    return 0;
}

