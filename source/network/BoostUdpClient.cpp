//
// Created by tfian on 28/11/2019.
//

#include "BoostUdpClient.hpp"
#include "Client.hpp"

BoostUdpClient::BoostUdpClient() : io_context_(), socket_(io_context_, udp::endpoint(udp::v4(), 0))
{
}

bool BoostUdpClient::doConnect(const std::string &host, const std::string &port)
{
    udp::resolver resolver(io_context_);
    udp::resolver::query query(udp::v4(), host, port);
    udp::resolver::iterator iter = resolver.resolve(query);
    endpoint_ = *iter;

    return true;
}

void BoostUdpClient::startListening()
{
    doReceive();
    boost::thread t(boost::bind(&boost::asio::io_context::run, boost::ref(io_context_)));
}


bool BoostUdpClient::sendData(const char *data, size_t size)
{
    socket_.async_send_to(boost::asio::buffer(data, size), endpoint_,
                          boost::bind(&BoostUdpClient::handle_send, this));
    std::cout << "sendData" << std::endl;
    return true;
}

bool BoostUdpClient::sendAndReceiveNext(const char *data, size_t size)
{
    socket_.send_to(boost::asio::buffer(data, size), endpoint_);
    size_t recvd = socket_.receive_from(boost::asio::buffer(cmd_recv_buf), sender_endpoint);
    handle_receive_sync(recvd);
    std::cout << "blocking receive" << std::endl;
    return true;
}

void BoostUdpClient::handle_send()
{
}

std::vector<RawData> BoostUdpClient::receiveAll()
{
    mtx.lock();
    std::vector<RawData> copy = this->packets;
    this->packets.clear();
    mtx.unlock();

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

void BoostUdpClient::handle_receive_from(const boost::system::error_code &error, size_t bytes_recvd) {
    RawData data = RawData();

    std::cout << "received packet async of " << bytes_recvd << "bytes" << std::endl;

    if (!error || error == boost::asio::error::message_size) {
        if (bytes_recvd <= Protocol::MAX_ENTITY_LENGTH) {
            memcpy(data.data, recv_buf.data(), recv_buf.size());
            data.size = bytes_recvd;
            mtx.lock();
            this->packets.emplace_back(data);
            mtx.unlock();
        }
        doReceive();
    }
}

void BoostUdpClient::handle_receive_sync(size_t bytes_recvd)
{
    RawData data = RawData();

    std::cout << "received packet sync" << std::endl;

    if (bytes_recvd <= Protocol::MAX_ENTITY_LENGTH) {
        memcpy(data.data, cmd_recv_buf.data(), bytes_recvd);
        data.size = bytes_recvd;
        mtx.lock();
        this->packets.emplace_back(data);
        mtx.unlock();
    }
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