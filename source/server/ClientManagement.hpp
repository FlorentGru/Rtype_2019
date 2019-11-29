/*
** EPITECH PROJECT, 2019
** r_type
** File description:
** ClientManagement.cpp
*/

#ifndef _CLIENTMANAGEMENT_HPP_
#define _CLIENTMANAGEMENT_HPP_

#include "GameManagement.hpp"

class ClientManagement
{
public:
    ClientManagement();
    void task_manager(std::string);

private:
    void handshake();
    void createRoom();
    void getRooms();
    void roomConnection();
    void launchGame();
};

#endif