/*
** EPITECH PROJECT, 2019
** r_type
** File description:
** session.cpp
*/

#include "Session.hpp"

Session::Session(std::string pseudo)
{
    std::cout << "Session constructor" << std::endl;
    pseudo_ = pseudo;
}

void Session::taskManager(std::string data, size_t size)
{
    packet_.set(data.c_str(), 64);

    if (packet_.get().data.tag == Protocol::CMD::HANDSHAKE) {
        std::cout << "Received :'" << packet_.get().data._handshake.magicNumber << "'" << std::endl;
        packet_.handshake(true, false);
    } else if (packet_.get().data.tag == Protocol::CMD::DISCONNECTION) {
        std::cout << "Disconnection" << std::endl;
        packet_.deconnection();
    } else if (packet_.get().data.tag == Protocol::CMD::NONE) {
        std::cout << "Received :'" << packet_.get().data._error.msg << "'" << std::endl;
        packet_.error(Protocol::CMD::NONE, "Error : Received unknown request");
    } else
        std::cout << "weird package" << std::endl;
}

char *Session::getPacketData()
{
    return(this->packet_.get().rawData);
}