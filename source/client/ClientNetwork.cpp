//
// Created by tfian on 28/11/2019.
//

#include <PacketManager.hpp>
#include "ClientNetwork.hpp"
#include "BoostUdpClient.hpp"

ClientNetwork::ClientNetwork()
{
    this->udpClient = std::make_shared<BoostUdpClient>();
}

void print_packet(RawData packet) {
    std::cout << "packet size:" << packet.size << std::endl;
    for (size_t i = 0; i < packet.size; i++) {
    }
};

bool ClientNetwork::connect(const std::string &host, const std::string &port) {
    if (!this->udpClient->doConnect(host, port)) {
        std::cout << "error 1" << std::endl;
        return false;
    }

    RawData packet = this->packetManager.handshake(false, true);
    this->udpClient->sendAndReceiveNext(packet.data, packet.size);

    std::vector<RawData> packets = this->udpClient->receiveAll();
    if (packets.empty()) {
        std::cout << "error 3" << std::endl;
        return false;
    }

    packet = packets.back();
    print_packet(packet);
    if (!packetManager.isValid(packet.data, packet.size, Protocol::HANDSHAKE)) {
        std::cout << "error 4" << std::endl;
        return false;
    }
    if (!packetManager.isValidHandshake(packet.data, packet.size, true, false)) {
        std::cout << "error 5" << std::endl;
        return false;
    }

    this->udpClient->startListening();
    return true;
}

bool ClientNetwork::sendEvents(const Events &events)
{
    RawData packet = this->packetManager.events(events);

    return this->udpClient->sendData(packet.data, packet.size);
}

bool ClientNetwork::findIdExist(int id, std::vector<int> idList)
{
    for (size_t i = 0; i != idList.size(); i++) {
        if (id == idList[i])
            return true;
    }
    return false;
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
/*    for (const Protocol::PacketManager::EntityPacket &packet : entityPackets) {
        for (int i = 0; i < packet.data.entityNbr; i++) {
            entities.push_back(entityPacketToSerialized(packet.data.entities[i]));
        }
    }*/

    std::vector<int> alreadyAdd;
    if (!entityPackets.empty() == true) {
        for (auto it = entityPackets.end(); it != entityPackets.begin(); it--) {
            for (int i = 0; i < it->data.entityNbr; i++) {
                if (!findIdExist(it->data.entities[i].id, alreadyAdd)) {
                    entities.push_back(entityPacketToSerialized(it->data.entities[i]));
                    alreadyAdd.push_back(it->data.entities[i].id);
                }
            }
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