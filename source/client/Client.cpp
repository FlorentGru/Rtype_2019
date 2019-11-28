/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** client/client.cpp
*/

#include "Client.hpp"

using boost::asio::ip::udp;

Client::Client(boost::asio::io_context& io_context, const std::string& host, const std::string& port
) : io_context_(io_context), socket_(io_context, udp::endpoint(udp::v4(), 0))
{
	udp::resolver resolver(io_context_);
	udp::resolver::query query(udp::v4(), host, port);
	udp::resolver::iterator iter = resolver.resolve(query);
	endpoint_ = *iter;
	std::shared_ptr<IClientData> clientData(new ClientData());
	this->data_ = clientData;

	receive();
	boost::thread t(boost::bind(&Client::inLoop, this));
	io_context_.run();
	t.join();
}

Client::~Client()
{
	socket_.close();
}

void Client::send()
{
    socket_.async_send_to(boost::asio::buffer(this->data_->getPacketData(), 64), endpoint_,
        boost::bind(&Client::handleSend, this));
}

void Client::handleSend()
{
}

void Client::receive()
{
	socket_.async_receive_from(
            boost::asio::buffer(recv_buf), sender_endpoint,
            boost::bind(&Client::handle_receive_from, this,
            boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred));
}

void Client::handle_receive_from(const boost::system::error_code& error, size_t bytes_recvd)
{
	std::string _buffer;

	std::copy(recv_buf.begin(), recv_buf.begin()+bytes_recvd, std::back_inserter(_buffer));
    this->data_->manageReceivedData(_buffer);

	if (this->data_->inDisconnection() == true) {
		socket_.close();
		return;
	}

	if (!error || error == boost::asio::error::message_size)
        receive();
}

void Client::inLoop()
{
	std::string message;
	while(true)
	{
		std::cin >> message;
		this->data_->createRequest(message);
		send();
	}
}
