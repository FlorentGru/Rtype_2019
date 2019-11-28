/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** client/ClientDataManagement.cpp
*/


#include "ClientData.hpp"

ClientData::ClientData()
{
    disconnection = false;
}

void ClientData::createRequest(std::string request)
{
    if (request.compare("handshake") == 0)
		packet.handshake(false, true);
	else if (request.compare("disconnection") == 0)
		packet.disconnection();
	else
		packet.error(Protocol::CMD::NONE, "Error : Unknown data");
}

void ClientData::manageReceivedData(std::string data)
{
    packet.setCommand(data.c_str(), 64);

    if (packet.getCommand().data.tag == Protocol::CMD::HANDSHAKE) {
        std::cout << "Received :'" << packet.getCommand().data._handshake.magicNumber << "'" << std::endl;
    } else if (packet.getCommand().data.tag == Protocol::CMD::DISCONNECTION) {
        disconnection = true;
        std::cout << "Disconnection" << std::endl;
    } else if (packet.getCommand().data.tag == Protocol::CMD::NONE) {
        std::cout << "Received :'" << packet.getCommand().data._error.msg << "'" << std::endl;
    }
}

char *ClientData::getPacketData()
{
    return(this->packet.getCommand().rawData);
}

bool ClientData::inDisconnection()
{
    return (disconnection);
}