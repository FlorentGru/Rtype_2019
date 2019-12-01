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
    /**
     * Initialise the server connection
     * @param port is the opened port of the server
     */
    Server(short port);
    /**
     * Launch the server connection
     * @return true
     * @return false
     */
    bool run();

private:
    ServerNetwork network;
    GameEngine engine;
};

#endif