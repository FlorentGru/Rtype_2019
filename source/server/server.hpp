/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** server/server.hpp
*/

#ifndef _SERVER_HPP_
#define _SERVER_HPP_

#include <ctime>
#include <iostream>
#include <string>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::udp;

class server
{
    public:
        server(boost::asio::io_context& ioContext);

    private: 
        void doReceive();
        void handleReceive(const boost::system::error_code& error, size_t bytes_transferred);

        udp::socket socket_;
        udp::endpoint remoteEndpoint_;
        boost::array<char, 1024> recv_buffer;
};

#endif