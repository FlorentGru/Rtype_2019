/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** server/server.hpp
*/

#ifndef _SERVER_HPP_
#define _SERVER_HPP_

#include "ServerNetwork.hpp"
#include "GameEngine.hpp"

using boost::asio::ip::udp;

class Server
{
public:
    Server(short port);
    bool run();

private:
    ServerNetwork network;
    GameEngine engine;
};

#endif