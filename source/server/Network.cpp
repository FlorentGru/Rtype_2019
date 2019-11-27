/*
** EPITECH PROJECT, 2019
** babel_boost_test
** File description:
** test_boost.cpp
*/

#include <memory>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include "Network.hpp"

using boost::asio::ip::udp;

NetworkServer::NetworkServer(boost::asio::io_context& io_context, short port) : ioContext_(io_context), socket_(io_context, udp::endpoint(udp::v4(), port))
{
    std::cout << "NetworkServer construtor" << std::endl;
}

bool NetworkServer::doReceive()
{
    std::cout << "enter doReceive" << std::endl;
    socket_.async_receive_from(boost::asio::buffer(recv_buffer), remoteEndpoint_,
        boost::bind(&NetworkServer::handleReceive, this,
        boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred));
    std::cout << "leave doReceive" << std::endl;
    return(true);
}

void NetworkServer::handleReceive(const boost::system::error_code& error, size_t bytes_transferred)
{
    std::cout << "enter handleReceive" << std::endl;
    res = std::string(recv_buffer.begin(), recv_buffer.begin()+bytes_transferred);
    std::cout << "Received: '" << std::string(recv_buffer.begin(), recv_buffer.begin()+bytes_transferred) << "'\n";

    std::cout << "leave handleReceive" << std::endl;
    if (!error || error == boost::asio::error::message_size)
        doReceive();
}

std::string NetworkServer::getMessage()
{
    return (res);
}