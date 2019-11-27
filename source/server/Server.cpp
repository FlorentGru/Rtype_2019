/*
** EPITECH PROJECT, 2019
** babel_boost_test
** File description:
** test_boost.cpp
*/

#include <memory>
#include "Server.hpp"

using boost::asio::ip::udp;

Server::Server(boost::asio::io_context &io_context, short port) : ioContext_(io_context), socket_(io_context, udp::endpoint(udp::v4(), port))
{
//    thr = new boost::thread(boost::bind(&NetworkServer::doReceive, &session_));
    doReceive();
}

Server::~Server()
{
    clientList.clear();
    socket_.close();
}

void Server::doReceive()
{
    socket_.async_receive_from(boost::asio::buffer(recv_buffer), remoteEndpoint_,
        boost::bind(&Server::handleReceive, this,
        boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred));
}

void Server::handleReceive(const boost::system::error_code& error, size_t bytes_transferred)
{
    std::string _buffer;

    if (this->clientList.find(remoteEndpoint_.address()) == this->clientList.end()) {
        std::cout << "new" << std::endl;
        std::shared_ptr<ISession> session(new Session("Robert"));
        this->clientList.emplace(remoteEndpoint_.address(), session);
    }

    std::copy(recv_buffer.begin(), recv_buffer.begin()+bytes_transferred, std::back_inserter(_buffer));
    this->clientList[remoteEndpoint_.address()]->taskManager(_buffer, bytes_transferred);

    doSend();
    if (!error || error == boost::asio::error::message_size)
        doReceive();
}

void Server::doSend()
{
    socket_.async_send_to(boost::asio::buffer(this->clientList[remoteEndpoint_.address()]->getPacketData(), 64), remoteEndpoint_,
        boost::bind(&Server::handleSend, this, this->clientList[remoteEndpoint_.address()]->getPacketData(),
        boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred));
}

void Server::handleSend(std::string message, const boost::system::error_code& error, size_t bytes_transferred)
{
    std::cout << "sent" << std::endl;
}