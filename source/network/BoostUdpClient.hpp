//
// Created by tfian on 28/11/2019.
//

#ifndef RTYPE_BOOSTUDPCLIENT_HPP
#define RTYPE_BOOSTUDPCLIENT_HPP

#include <iostream>
#include <boost/thread.hpp>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include "ClientData.hpp"
#include "IUdpClient.hpp"

using boost::asio::ip::udp;

class BoostUdpClient : public IUdpClient
{
public:
    BoostUdpClient();

    bool doConnect(const std::string &address, const std::string &port) override ;

    bool sendData(const char *data, size_t size) override ;

    std::vector<RawData> receiveAll() override ;

    RawData receiveNext() override ;

    bool disconnect() override ;
private:
    void doReceive();
    void handle_receive_from(const boost::system::error_code& error, size_t bytes_recvd);

    boost::array<char, Protocol::MAX_ENTITY_LENGTH> recv_buf;
    std::vector<RawData> packets;

    boost::asio::io_context io_context_;
    udp::socket socket_;

    udp::endpoint endpoint_;
    udp::endpoint sender_endpoint;
};


#endif //RTYPE_BOOSTUDPCLIENT_HPP
