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
    _command.data._handshake.magicNumber = PRO_SIZE::MAGIC_NBR;
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

CMD Packet::getType(const char *pck, std::size_t size)
{
    BasePacket packet;

    memset(packet.rawData, 0, MIN_LENGTH);
    memcpy(packet.rawData, pck, size);

    return (packet.data.tag);
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

    memcpy(_command.rawData, pck, size);
}

void Packet::setEvents(const char *pck, std::size_t size)
{
    setEvents();

    memcpy(_events.rawData, pck, size);
}

void Packet::setEntity(const char *pck, std::size_t size)
{
    setEntity();

    memcpy(_entity.rawData, pck, size);
}
