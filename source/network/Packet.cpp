/*
** EPITECH PROJECT, 2019
** r_type
** File description:
** packet.cpp
*/

#include <cstring>
#include "Packet.hpp"

using namespace Protocol;

Packet::Packet()
{
}

Packet::CommandPacket &Packet::createEmptyPacket()
{
    _data.data.tag = CMD::NONE;
    _data.data.res = true;
    return(_data);
}

Packet::CommandPacket &Packet::handshake(bool fromServ, bool fromClient)
{
    _data.data.tag = CMD::HANDSHAKE;
    _data.data.res = true;
    _data.data._handshake.client = fromClient;
    _data.data._handshake.serv = fromServ;
    _data.data._handshake.magicNumber = 125728;
    return(_data);
}

Packet::CommandPacket &Packet::disconnection()
{
    _data.data.tag = CMD::DISCONNECTION;
    _data.data.res = true;
    return(_data);
}

Packet::CommandPacket &Packet::error(const Protocol::CMD cmd, const std::string &msg)
{
    _data.data.tag = cmd;
    _data.data.res = true;
    memset(_data.data._error.msg, 0, Protocol::PRO_SIZE::MAX_MSG_ERROR);
    for (size_t i = 0; i < Protocol::PRO_SIZE::MAX_MSG_ERROR; i++)
        _data.data._error.msg[i] = msg[i];
    return(_data);
}

Packet::CommandPacket &Packet::getCommand()
{
    return(_data);
}

void Packet::set(const char *pck, std::size_t size)
{
    memset(_data.rawData, 0, 64);
    for (size_t i = 0; i < size; i++)
        _data.rawData[i] = pck[i];
}

bool Packet::isValid(CMD tag)
{
    if (tag == CMD::NONE)
        return(false);
    return(true);
}