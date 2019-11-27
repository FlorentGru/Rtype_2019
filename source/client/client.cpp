/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** client/client.cpp
*/

#include "client.hpp"

using boost::asio::ip::udp;

Client::Client(boost::asio::io_context& io_context, const std::string& host, const std::string& port
) : io_context_(io_context), socket_(io_context, udp::endpoint(udp::v4(), 0))
{
	udp::resolver resolver(io_context_);
	udp::resolver::query query(udp::v4(), host, port);
	udp::resolver::iterator iter = resolver.resolve(query);
	endpoint_ = *iter;
}

Client::~Client()
{
	socket_.close();
}

void Client::send(const std::string &msg)
{
	if (msg.compare("handshake") == 0)
		packet_.handshake(false, true);
	else if (msg.compare("disconnection") == 0)
		packet_.deconnection();
	else
		packet_.error(Protocol::CMD::NONE, "Error : Unknown data");
    socket_.async_send_to(boost::asio::buffer(packet_.get().rawData, 64), endpoint_,
        boost::bind(&Client::handleSend, this, packet_.get().rawData,
        boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred));
}

void Client::handleSend(std::string message, const boost::system::error_code& error, size_t bytes_transferred)
{
}

/*void Client::send(const std::string& msg)
{
	if (msg.compare("handshake") == 0)
		packet_.handshake(false, true);
	else if (msg.compare("disconnection") == 0)
		packet_.deconnection();
	else
		packet_.error(Protocol::CMD::NONE, "Error : Unknown data");
	socket_.send_to(boost::asio::buffer(packet_.get().rawData, 64), endpoint_);
}*/

void Client::receive()
{
	//socket_.receive_from(boost::asio::buffer(recv_buf), sender_endpoint);
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
	packet_.set(_buffer.c_str(), bytes_recvd);
	if (packet_.get().data.tag == Protocol::CMD::HANDSHAKE)
        std::cout << "Received :'" << packet_.get().data._handshake.magicNumber << "'" << std::endl;
	if (packet_.get().data.tag == Protocol::CMD::NONE)
        std::cout << "Received :'" << packet_.get().data._error.msg << "'" << std::endl;
	if (packet_.get().data.tag == Protocol::CMD::DISCONNECTION) {
        std::cout << "Disconnection" << std::endl;
		socket_.close();
	}
}