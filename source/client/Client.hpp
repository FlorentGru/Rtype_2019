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
#include "ClientDataManagement.hpp"

using boost::asio::ip::udp;

class Client
{
public:
	Client(const std::string& host, const std::string& port);
	~Client();
	void send();
	void handleSend();
	void receive();
	void handle_receive_from(const boost::system::error_code& error, size_t bytes_recvd);
	void inLoop();

private:
	boost::array<char, 64> recv_buf;
	boost::asio::io_context io_context_;
	udp::socket socket_;
	udp::endpoint endpoint_;
	udp::endpoint sender_endpoint;

	std::shared_ptr<IClientData> data_;
};

#endif