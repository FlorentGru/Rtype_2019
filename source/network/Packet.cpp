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
    setCommand();
    setEntity();
    setEvents();
}

Packet::CommandPacket &Packet::handshake(bool fromServ, bool fromClient)
{
    setCommand();

    _command.data.tag = CMD::HANDSHAKE;
    _command.data.res = true;
    _command.data._handshake.client = fromClient;
    _command.data._handshake.serv = fromServ;
    _command.data._handshake.magicNumber = 125728;
    return(_command);
}

Packet::CommandPacket &Packet::disconnection()
{
    setCommand();

    _command.data.tag = CMD::DISCONNECTION;
    _command.data.res = true;
    return(_command);
}

Packet::CommandPacket &Packet::error(const Protocol::CMD cmd, const std::string &msg)
{
    setCommand();

    _command.data.tag = cmd;
    _command.data.res = true;
    memset(_command.data._error.msg, 0, Protocol::PRO_SIZE::MAX_MSG_ERROR);
    for (size_t i = 0; i < Protocol::PRO_SIZE::MAX_MSG_ERROR; i++)
        _command.data._error.msg[i] = msg[i];
    return(_command);
}

Packet::CommandPacket &Packet::getCommand()
{
    return(_command);
}

bool Packet::isValid(CMD tag)
{
    if (tag == CMD::NONE)
        return(false);
    return(true);
}

void Packet::setCommand()
{
    memset(this->_command.rawData, 0, MAX_COMMAND_LENGTH);
}

void Packet::setEvents()
{
    memset(this->_events.rawData, 0, MAX_EVENT_LENGTH);
}

void Packet::setEntity()
{
    memset(this->_entity.rawData, 0, MAX_ENTITY_LENGTH);
}

void Packet::setCommand(const char *pck, std::size_t size)
{
    setCommand();

    for (size_t i = 0; i < size; i++) {
        _command.rawData[i] = pck[i];
    }
}

void Packet::setEvents(const char *pck, std::size_t size)
{
    setEvents();

    for (size_t i = 0; i < size; i++) {
        _events.rawData[i] = pck[i];
    }
}

void Packet::setEntity(const char *pck, std::size_t size)
{
    setEntity();

    for (size_t i = 0; i < size; i++) {
        _entity.rawData[i] = pck[i];
    }
}
