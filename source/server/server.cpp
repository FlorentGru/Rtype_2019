/*
** EPITECH PROJECT, 2019
** babel_boost_test
** File description:
** test_boost.cpp
*/

#include <memory>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include "server.hpp"

using boost::asio::ip::udp;

server::server(boost::asio::io_context& io_context) : socket_(io_context, udp::endpoint(udp::v4(), 13))
{
    doReceive();
}

void server::doReceive()
{
    socket_.async_receive_from(boost::asio::buffer(recv_buffer), remoteEndpoint_,
        boost::bind(&server::handleReceive, this,
        boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred));
}

void server::handleReceive(const boost::system::error_code& error, size_t bytes_transferred)
{
    std::cout << "ulala" << std::endl;
    std::cout << "Received: '" << std::string(recv_buffer.begin(), recv_buffer.begin()+bytes_transferred) << "'\n";

    if (!error || error == boost::asio::error::message_size)
        doReceive();
}