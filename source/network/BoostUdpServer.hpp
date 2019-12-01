//
// Created by fabien on 29/11/2019.
//

#ifndef RTYPE_BOOSTUDPSERVER_HPP
#define RTYPE_BOOSTUDPSERVER_HPP

#include <iostream>
#include <boost/thread.hpp>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include "ClientData.hpp"
#include "IUdpServer.hpp"
#include "Session.hpp"
#include "PacketManager.hpp"

using boost::asio::ip::udp;

class BoostUdpServer : public IUdpServer
{
public:
    BoostUdpServer(short port);

    void openServer() override;

    bool send(const char *data, size_t size) override ;

    void sendAsync(const char *data, size_t size, std::string) override;

    std::vector<RawData> receiveUserPackets(std::string userAddress) override ;

private:
    Protocol::PacketManager packetManager;
    std::map<udp::endpoint, std::shared_ptr<ISession>> clientList;
    std::map<std::string, udp::endpoint> usersEndpoint;

    boost::mutex mtx;

    void doReceive();
    void handleReceive(const boost::system::error_code& error, size_t bytes_recvd);
    void handleSend();
    void removeClient(udp::endpoint);

    boost::asio::io_context ioContext_;
    udp::socket socket_;
    udp::endpoint remoteEndpoint_;
    boost::array<char, Protocol::MAX_ENTITY_LENGTH> recv_buf;
};

#endif //RTYPE_BOOSTUDPSERVER_HPP
