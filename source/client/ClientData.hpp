/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** client/ClientDataManagement.hpp
*/

#ifndef _CLIENTDATA_HPP_
#define _CLIENTDATA_HPP_

#include <string>
#include "PacketManager.hpp"

class ClientData
{
public:
    ClientData();
    void createRequest(std::string);
    char *getPacketData();
    void manageReceivedData(std::string request);
    bool inDisconnection();
private:
    Protocol::PacketManager packet;

    bool disconnection;
};

#endif