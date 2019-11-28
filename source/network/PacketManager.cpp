/*
** EPITECH PROJECT, 2019
** r_type
** File description:
** packet.cpp
*/

#include <cstring>
#include "PacketManager.hpp"

using namespace Protocol;

PacketManager::PacketManager()
{
    setCommand();
    setEntity();
    setEvents();
}

RawData PacketManager::handshake(bool fromServ, bool fromClient)
{
    setCommand();

    _command.data.tag = CMD::HANDSHAKE;
    _command.data.res = true;
    _command.data._handshake.client = fromClient;
    _command.data._handshake.serv = fromServ;
    _command.data._handshake.magicNumber = PRO_SIZE::MAGIC_NBR;
    return(RawData(_command.rawData, Protocol::MAX_COMMAND_LENGTH));
}

RawData PacketManager::disconnection()
{
    setCommand();

    _command.data.tag = CMD::DISCONNECTION;
    _command.data.res = true;
    return(RawData(_command.rawData, Protocol::MAX_COMMAND_LENGTH));
}

RawData PacketManager::error(const Protocol::CMD cmd, const std::string &msg)
{
    setCommand();

    _command.data.tag = cmd;
    _command.data.res = true;
    memset(_command.data._error.msg, 0, Protocol::PRO_SIZE::MAX_MSG_ERROR);
    for (size_t i = 0; i < Protocol::PRO_SIZE::MAX_MSG_ERROR; i++)
        _command.data._error.msg[i] = msg[i];
    return(RawData(_command.rawData, Protocol::MAX_COMMAND_LENGTH));
}

RawData PacketManager::getCommand()
{
    return(RawData(_command.rawData, Protocol::MAX_COMMAND_LENGTH));
}

CMD PacketManager::getType(const char *pck, std::size_t size)
{
    BasePacket packet;

    memset(packet.rawData, 0, MIN_LENGTH);
    memcpy(packet.rawData, pck, size);

    return (packet.data.tag);
}

bool PacketManager::isSuccess(const char *pck, std::size_t size)
{
    BasePacket packet;

    memset(packet.rawData, 0, MIN_LENGTH);
    memcpy(packet.rawData, pck, size);

    return packet.data.res;
}

bool PacketManager::isValid(const char *data, std::size_t size, CMD tag)
{
    CMD type = getType(data, size);

    if (type != tag || !isSuccess(data, size)) {
        return false;
    }

    return(true);
}

void PacketManager::setCommand()
{
    memset(this->_command.rawData, 0, MAX_COMMAND_LENGTH);
}

void PacketManager::setEvents()
{
    memset(this->_events.rawData, 0, MAX_EVENT_LENGTH);
}

void PacketManager::setEntity()
{
    memset(this->_entity.rawData, 0, MAX_ENTITY_LENGTH);
}

void PacketManager::setCommand(const char *pck, std::size_t size)
{
    setCommand();

    memcpy(_command.rawData, pck, size);
}

void PacketManager::setEvents(const char *pck, std::size_t size)
{
    setEvents();

    memcpy(_events.rawData, pck, size);
}

void PacketManager::setEntity(const char *pck, std::size_t size)
{
    setEntity();

    memcpy(_entity.rawData, pck, size);
}

bool PacketManager::isValidHandshake(const char *data, std::size_t size, bool serv, bool client)
{
    setCommand(data, size);

    if (!_command.data.res) {
        return false;
    }
    if (_command.data._handshake.magicNumber != MAGIC_NBR) {
        return false;
    }
    if (_command.data._handshake.serv == serv && _command.data._handshake.client == client) {
        return true;
    }
    return false;
}

bool PacketManager::isValidDisconnection(const char *data, std::size_t size)
{
    setCommand(data, size);

    return _command.data.res;
}
