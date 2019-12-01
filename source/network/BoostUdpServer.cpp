//
// Created by fabien on 29/11/2019.
//

#include "BoostUdpServer.hpp"
#include "Server.hpp"

BoostUdpServer::BoostUdpServer(short port) : ioContext_(), socket_(ioContext_, udp::endpoint(udp::v4(), port))
{
}

void BoostUdpServer::openServer()
{
    std::cout << "openserver" << std::endl;
    doReceive();
    boost::thread t(boost::bind(&boost::asio::io_context::run, boost::ref(this->ioContext_)));
//    t.join();
}

void BoostUdpServer::doReceive()
{
    socket_.async_receive_from(boost::asio::buffer(recv_buf), remoteEndpoint_,
           boost::bind(&BoostUdpServer::handleReceive, this,
           boost::asio::placeholders::error,
           boost::asio::placeholders::bytes_transferred));
}

void BoostUdpServer::removeClient(udp::endpoint remoteEndpoint)
{
    for (auto it = this->usersEndpoint.begin(); it != this->usersEndpoint.end(); it++) {
        if (it->second == remoteEndpoint) {
            this->usersEndpoint.erase(it->first);
            return;
        }
    }
}

void BoostUdpServer::handleReceive(const boost::system::error_code& error, size_t bytes_recvd)
{
    RawData data = RawData();

    if (bytes_recvd <= Protocol::MAX_ENTITY_LENGTH) {
        memcpy(data.data, recv_buf.data(), bytes_recvd);
        data.size = bytes_recvd;
    }

    Protocol::CMD packetType = packetManager.getType(data.data);

    if (packetType == Protocol::HANDSHAKE) {
        if (packetManager.isValidHandshake(data.data, data.size, false, true)) {
            packetManager.setCommand(data.data, data.size);
            std::cout << "Received : magic number" << std::endl;
            data = packetManager.handshake(true, false);
            send(data.data, data.size);
            if (this->clientList.find(remoteEndpoint_) == this->clientList.end()) {
                std::cout << "new" << std::endl;
                std::shared_ptr<ISession> session(new Session("Robert"));
                this->clientList.emplace(remoteEndpoint_, session);
                this->usersEndpoint.emplace("Player " + std::to_string(this->clientList.size()), remoteEndpoint_);
            }
        } else {
            data = packetManager.error(Protocol::ERROR, "Invalid Handshake");
            send(data.data, data.size);
        }
    }
    if (packetType == Protocol::DISCONNECTION) {
        if (packetManager.isValidDisconnection(data.data, data.size)) {
            data = packetManager.disconnection();
            std::cout << "Disconnect client" << std::endl;send(data.data, data.size);
            send(data.data, data.size);
            this->clientList.erase(remoteEndpoint_);
            removeClient(remoteEndpoint_);
        } else {
            data = packetManager.error(Protocol::ERROR, "Invalid Disconnection");
            send(data.data, data.size);
        }
    }

    if (packetType == Protocol::ENTITY) {
        data = packetManager.error(Protocol::ERROR, "Invalid Packet");
        send(data.data, data.size);
    } else if (packetType == Protocol::EVENTS) {
        if (this->clientList.find(remoteEndpoint_) != this->clientList.end()) {
            packetManager.setEvents(data.data, data.size);
            this->clientList[remoteEndpoint_]->addEventPacket(packetManager.getEvents());
        } else {
            data = packetManager.error(Protocol::ERROR, "User not connected");
            send(data.data, data.size);
        }
    } else {
        data = packetManager.error(Protocol::ERROR, "Unknown packet");
        send(data.data, data.size);
    }

    if (!error || error == boost::asio::error::message_size)
        doReceive();
}

bool BoostUdpServer::send(const char *data, size_t size)
{
    return socket_.send_to(boost::asio::buffer(data, size), remoteEndpoint_) == size;
}

void BoostUdpServer::sendAsync(const char *data, size_t size, std::string userId)
{
    if (this->usersEndpoint.find(userId) != this->usersEndpoint.end()) {
        socket_.async_send_to(boost::asio::buffer(data, size), this->usersEndpoint.find(userId)->second,
                              boost::bind(&BoostUdpServer::handleSend, this));
    } else {
    //    std::cout << "no connected user" << std::endl;
    }
}

void BoostUdpServer::handleSend()
{
}

std::vector<RawData> BoostUdpServer::receiveUserPackets(std::string userAddress)
{
    std::vector<RawData> packets;

    if (this->usersEndpoint.find(userAddress) != this->usersEndpoint.end()) {
        return this->clientList[this->usersEndpoint.find(userAddress)->second]->getPacketData();
    }
    return (packets);
}