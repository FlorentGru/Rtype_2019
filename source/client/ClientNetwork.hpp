//
// Created by tfian on 28/11/2019.
//

#ifndef RTYPE_CLIENTNETWORK_HPP
#define RTYPE_CLIENTNETWORK_HPP

#include <memory>
#include "IUdpClient.hpp"
#include "SerializedEntity.hpp"
#include "Events.hpp"
#include "PacketManager.hpp"

class ClientNetwork
{
public:
    ClientNetwork() = default;
    bool connect(const std::string &host, const std::string &port);

    bool sendEvents(const Events &events);
    std::vector<SerializedEntity> getEntities();
//    std::vector<SerialisedEntity> getEntities();
private:
    SerializedEntity entityPacketToSerialized(const Protocol::PacketManager::Entity &packet);

    std::shared_ptr<IUdpClient> udpClient;
    Protocol::PacketManager packetManager;
};


#endif //RTYPE_CLIENTNETWORK_HPP
