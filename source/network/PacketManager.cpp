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


std::vector<RawData> PacketManager::entity(const std::vector<SerializedEntity> &entities)
{
    std::vector<RawData> result;

    int numberEntities = entities.size();

    int numberRawData = (numberEntities / 10) + 1;
    int numbers = numberEntities % 10;
    int size = 10;
    int count = 0;

    for (int i = 0; i != numberRawData; i++) {
        if (i == (numberRawData - 1))
            size = numbers;
        setEntity();
        _entity.data.tag = CMD::ENTITY;
        _entity.data.res = true;
        _entity.data.entityNbr = size;
        for (int j = 0; j != size; j++) {
            _entity.data.entities[j].id = entities.at(count).getId();
            _entity.data.entities[j].type = entities.at(count).getType();
            _entity.data.entities[j].posX = entities.at(count).getX();
            _entity.data.entities[j].posY = entities.at(count).getY();
            count += 1;
        }
        result.emplace_back(RawData(_entity.rawData, Protocol::MAX_ENTITY_LENGTH));
    }
    return(result);
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
    if (msg.size() < Protocol::MAX_MSG_ERROR) {
        memcpy(_command.data._error.msg, msg.c_str(), msg.size());
    }
    return(RawData(_command.rawData, Protocol::MAX_COMMAND_LENGTH));
}

CMD PacketManager::getType(const char *pck, std::size_t size)
{
    BasePacket packet;

    memset(packet.rawData, 0, MIN_LENGTH);
    memcpy(packet.rawData, pck, MIN_LENGTH);

    return (packet.data.tag);
}

bool PacketManager::isSuccess(const char *pck, std::size_t size)
{
    BasePacket packet;

    memset(packet.rawData, 0, MIN_LENGTH);
    memcpy(packet.rawData, pck, MIN_LENGTH);

    return packet.data.res;
}

bool PacketManager::isValid(const char *data, std::size_t size, CMD tag)
{
    CMD type = getType(data, size);

    if (!isSuccess(data, size)) {
        std::cout << "success" << std::endl;
        return false;
    }

    if (type != tag) {
        std::cout << "CMD" << std::endl;
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

bool PacketManager::isValidEvents(const char *data, std::size_t size)
{
    if (!isValid(data, size, Protocol::EVENTS)) {
        return false;
    }
    if (size != MAX_EVENT_LENGTH)
        return false;

    setEvents(data, size);

    return _events.data.res;
}


RawData PacketManager::getCommand() const {
    return RawData(_command.rawData, Protocol::MAX_COMMAND_LENGTH);
}

RawData PacketManager::getEvents() const {
    return RawData(_events.rawData, Protocol::MAX_EVENT_LENGTH);
}

RawData PacketManager::getEntity() const {
    return RawData(_entity.rawData, Protocol::MAX_ENTITY_LENGTH);
}

RawData PacketManager::events(const Events &events) {
    setEvents();

    _events.data.tag = Protocol::EVENTS;
    _events.data.res = true;

    _events.data.aKey = events.isAKey();
    _events.data.zKey = events.isZKey();
    _events.data.qKey = events.isQKey();
    _events.data.sKey = events.isSKey();
    _events.data.dKey = events.isDKey();
    _events.data.eKey = events.isEKey();
    _events.data.enter = events.isEnter();
    return (RawData(_events.rawData, MAX_EVENT_LENGTH));
}

const PacketManager::EntityPacket &PacketManager::getEntityPacket() const {
    return this->_entity;
}

const PacketManager::CommandPacket &PacketManager::getCommandPacket() const {
    return this->_command;
}

const PacketManager::EventsPacket &PacketManager::getEventPacket() const {
    return this->_events;
}

bool PacketManager::isValidEntity(const char *data, std::size_t size) {
    if (!isValid(data, size, Protocol::ENTITY)) {
        return false;
    }

    setEntity(data, size);
    if (_entity.data.entityNbr > 10 || _entity.data.entityNbr < 0) {
        return false;
    }
    return true;
}