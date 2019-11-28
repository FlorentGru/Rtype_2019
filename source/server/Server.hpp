/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** server/server.hpp
*/

#ifndef _SERVER_HPP_
#define _SERVER_HPP_

#include <boost/thread.hpp>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>
#include "Session.hpp"

using boost::asio::ip::udp;

class Server
{
public:
    Server(short port);
    ~Server();

private:
    void doReceive();
    void handleReceive(const boost::system::error_code& error, size_t bytes_transferred);
    void doSend();
    void handleSend();

    boost::asio::io_context ioContext_;
    udp::socket socket_;
    udp::endpoint remoteEndpoint_;
    boost::array<char, 64> recv_buffer;

    std::map<boost::asio::ip::address, std::shared_ptr<ISession>> clientList;
};

#endif