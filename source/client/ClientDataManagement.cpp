/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** client/ClientDataManagement.cpp
*/


#include "ClientDataManagement.hpp"

ClientData::ClientData()
{
    disconnection = false;
}

void ClientData::createRequest(std::string request)
{
    if (request.compare("handshake") == 0)
		packet_.handshake(false, true);
	else if (request.compare("disconnection") == 0)
		packet_.disconnection();
	else
		packet_.error(Protocol::CMD::NONE, "Error : Unknown data");
}

void ClientData::manageReceivedData(std::string data)
{
    packet_.setCommand(data.c_str(), 64);

    if (packet_.getCommand().data.tag == Protocol::CMD::HANDSHAKE) {
        std::cout << "Received :'" << packet_.getCommand().data._handshake.magicNumber << "'" << std::endl;
    } else if (packet_.getCommand().data.tag == Protocol::CMD::DISCONNECTION) {
        disconnection = true;
        std::cout << "Disconnection" << std::endl;
    } else if (packet_.getCommand().data.tag == Protocol::CMD::NONE) {
        std::cout << "Received :'" << packet_.getCommand().data._error.msg << "'" << std::endl;
    }
}

char *ClientData::getPacketData()
{
    return(this->packet_.getCommand().rawData);
}

bool ClientData::inDisconnection()
{
    return (disconnection);
}