/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** client/ClientDataManagement.hpp
*/

#ifndef _CLIENTDATA_HPP_
#define _CLIENTDATA_HPP_

#include "IClientDataManagement.hpp"

class ClientData : public IClientData
{
public:
    ClientData();
    void createRequest(std::string) override;
    char *getPacketData() override;
    void manageReceivedData(std::string request, size_t size) override;
    bool inDisconnection() override;
private:
};

#endif