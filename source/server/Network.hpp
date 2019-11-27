/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** server/server.hpp
*/

#ifndef _NETWORKSERVER_HPP_
#define _NETWORKSERVER_HPP_

#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::udp;

class NetworkServer
{
    public:
        NetworkServer(boost::asio::io_context& ioContext, short port);
        bool doReceive();
        std::string getMessage();

    private: 
        void handleReceive(const boost::system::error_code& error, size_t bytes_transferred);

        boost::asio::io_context& ioContext_;
        udp::socket socket_;
        udp::endpoint remoteEndpoint_;
        boost::array<char, 64> recv_buffer;
        std::string res;
};

#endif