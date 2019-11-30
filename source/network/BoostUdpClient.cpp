//
// Created by tfian on 28/11/2019.
//

#include "BoostUdpClient.hpp"
#include "Client.hpp"

BoostUdpClient::BoostUdpClient() : io_context_(), socket_(io_context_, udp::endpoint(udp::v4(), 0))
{}

bool BoostUdpClient::doConnect(const std::string &host, const std::string &port)
{
    udp::resolver resolver(io_context_);
    udp::resolver::query query(udp::v4(), host, port);
    udp::resolver::iterator iter = resolver.resolve(query);
    endpoint_ = *iter;

    doReceive();
//    boost::thread t(boost::bind(&Client::run, this));
    io_context_.run();
//    t.join();
    return true;
}

bool BoostUdpClient::sendData(const char *data, size_t size)
{
    return socket_.send_to(boost::asio::buffer(data, size), endpoint_) == size;
}

std::vector<RawData> BoostUdpClient::receiveAll()
{
    std::vector<RawData> copy = this->packets;

    this->packets.clear();
    return copy;
}

void BoostUdpClient::doReceive()
{
    socket_.async_receive_from(
    boost::asio::buffer(recv_buf), sender_endpoint,
    boost::bind(&BoostUdpClient::handle_receive_from, this,
                boost::asio::placeholders::error,
                boost::asio::placeholders::bytes_transferred));
}

void BoostUdpClient::handle_receive_from(const boost::system::error_code &error, size_t bytes_recvd)
{
    RawData data = RawData();

    if (bytes_recvd <= Protocol::MAX_ENTITY_LENGTH) {
        memcpy(data.data, recv_buf.data(), bytes_recvd);
        data.size = bytes_recvd;
        this->packets.emplace_back(data);
    }

    if (!error || error == boost::asio::error::message_size)
        doReceive();
}

RawData BoostUdpClient::receiveNext()
{
    return RawData();
}

bool BoostUdpClient::disconnect()
{
    socket_.close();
    return true;
}
