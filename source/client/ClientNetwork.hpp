//
// Created by tfian on 28/11/2019.
//

#ifndef RTYPE_CLIENTNETWORK_HPP
#define RTYPE_CLIENTNETWORK_HPP

#include <memory>
#include "IUdpClient.hpp"
#include "ClientData.hpp"

class ClientNetwork
{
public:
    ClientNetwork();
    bool connect(const std::string &host, const std::string &port);

    bool sendEvents();
    void getEntities();
//    std::vector<SerialisedEntity> getEntities();
private:
    std::shared_ptr<IUdpClient> udpClient;

    Protocol::PacketManager packetManager;
};


#endif //RTYPE_CLIENTNETWORK_HPP
