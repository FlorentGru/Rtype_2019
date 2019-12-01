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

    /**
     * Initialise the connection by calling the abstract network class
     */
    ClientNetwork();

    /**
     * Connection to the server
     * @param host is the server address
     * @param port is the opened server port
     * @return true
     * @return false
     */
    bool connect(const std::string &host, const std::string &port);

    /**
     * Client disconnection
     * @return true
     * @return false
     */
    bool disconnect();

    /**
     * send Events to the server
     * @param events is a binary packet filled by events
     * @return true
     * return false
     */
    bool sendEvents(const Events &events);

    /**
     * Get entities list
     * @return a list of entities to display
     */
    std::vector<SerializedEntity> getEntities();
private:

    /**
     * Convert an entity packet to a list of entities
     * @param packet is the entity packet to serialized
     * @return true
     * @return false
     */
    SerializedEntity entityPacketToSerialized(const Protocol::PacketManager::Entity &packet);
    bool findIdExist(int, std::vector<int>);

    std::shared_ptr<IUdpClient> udpClient;
    Protocol::PacketManager packetManager;
};


#endif //RTYPE_CLIENTNETWORK_HPP
