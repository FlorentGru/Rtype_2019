/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** client/client.hpp
*/

#ifndef _CLIENT_HPP_
#define _CLIENT_HPP_

#include <iostream>
#include <boost/thread.hpp>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include "Packet.hpp"

using boost::asio::ip::udp;

class Client
{
public:
	Client(boost::asio::io_context& io_context, const std::string& host, const std::string& port);
	~Client();
	void send(const std::string& msg);
	void handleSend(std::string message, const boost::system::error_code& error, size_t bytes_transferred);
	void receive();
	void handle_receive_from(const boost::system::error_code& error, size_t bytes_recvd);

private:
	boost::array<char, 64> recv_buf;
	boost::asio::io_context& io_context_;
	udp::socket socket_;
	udp::endpoint endpoint_;
	udp::endpoint sender_endpoint;
	boost::thread* thr;

    Protocol::Packet packet_;
};

#endif