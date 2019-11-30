//
// Created by tfian on 28/11/2019.
//

#include <PacketManager.hpp>
#include "ClientNetwork.hpp"
#include "SerializedEntity.hpp"

bool ClientNetwork::connect(const std::string &host, const std::string &port) {
    if (!this->udpClient->doConnect(host, port)) {
        return false;
    }

    RawData packet = this->packetManager.handshake(false, true);
    if (!this->udpClient->sendData(packet.data, packet.size)) {
        return false;
    }

    std::vector<RawData> packets = this->udpClient->receiveAll();
    if (packets.empty()) { return false; }

    packet = packets.back();
    if (!packetManager.isValid(packet.data, packet.size, Protocol::HANDSHAKE)) {
        return false;
    }
    if (!packetManager.isValidHandshake(packet.data, packet.size, true, false)) {
        return false;
    }
    return true;
}

bool ClientNetwork::sendEvents(const Events &events)
{
    RawData packet = this->packetManager.events(events);

    return this->udpClient->sendData(packet.data, packet.size);
}

std::vector<SerializedEntity> ClientNetwork::getEntities()
{
    std::vector<RawData> packets = this->udpClient->receiveAll();

    std::vector<Protocol::PacketManager::EntityPacket> entityPackets;
    for (RawData &packet : packets) {
        if (this->packetManager.isValidEntity(packet.data, packet.size)) {
            this->packetManager.setEntity(packet.data, packet.size);
            entityPackets.emplace_back(this->packetManager.getEntityPacket());
        }
    }

    std::vector<SerializedEntity> entities;
    for (const Protocol::PacketManager::EntityPacket &packet : entityPackets) {
        for (int i = 0; i < packet.data.entityNbr; i++) {
            entities.push_back(entityPacketToSerialized(packet.data.entities[i]));
        }
    }

    return entities;
}

SerializedEntity ClientNetwork::entityPacketToSerialized(const Protocol::PacketManager::Entity &packet)
{
    auto type = (IEntity::Type) packet.type;
    int id = packet.id;
    float x = packet.posX;
    float y = packet.posY;

    return SerializedEntity(type, id, x, y);
}