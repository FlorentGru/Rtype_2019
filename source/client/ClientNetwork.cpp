//
// Created by tfian on 28/11/2019.
//

#include "ClientNetwork.hpp"

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

bool ClientNetwork::sendEvents()
{
//    RawData packet = this->packetManager.events();

//    this->udpClient->sendData(packet);
}

void ClientNetwork::getEntities()
{
    std::vector<RawData> packets = this->udpClient->receiveAll();

//    EntityPacket packet = this->packetManager.
}