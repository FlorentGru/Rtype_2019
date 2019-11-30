/*
** EPITECH PROJECT, 2019
** r_type
** File description:
** packet.hpp
*/

#ifndef _RTYPEPACKET_HPP_
#define _RTYPEPACKET_HPP_

#include "iostream"
#include "RawData.hpp"
#include "Events.hpp"
#include "SerializedEntity.hpp"

namespace Protocol
{
    #ifdef __GNUC__
        #define PACK( __Declaration__ ) __Declaration__ __attribute__((__packed__))
    #endif

    #ifdef _MSC_VER
        #define PACK( __Declaration__ ) __pragma( pack(push, 1) ) __Declaration__ __pragma( pack(pop))
    #endif


    enum INFO : char {
        SEPARATOR = ';',
    };

    enum PRO_SIZE : int {
        MAX_MSG_ERROR = 50,
        MAX_COMMAND_LENGTH = 64,
        MAX_EVENT_LENGTH = 128,
        MAX_ENTITY_LENGTH = 256,
        MIN_LENGTH = 2,
        MAGIC_NBR = 42
    };

    enum CMD : unsigned char {
        NONE = 0,
        ERROR,
        HANDSHAKE,
        DISCONNECTION,
        EVENTS,
        ENTITY
    };

    class PacketManager
    {
    public:
        struct Entity {
            int id;
            int type;
            float posX;
            float posY;
        };

        union BasePacket {
            char rawData[MIN_LENGTH];
            struct {
                CMD tag;
                bool res;
            } data;
        };

        union EventsPacket {
            char rawData[MAX_EVENT_LENGTH];
            struct {
                CMD tag;
                bool res;

                bool enter;
                bool leftArrow;
                bool rightArrow;
                bool upArrow;
                bool downArrow;
                bool aKey;
                bool bKey;
                bool cKey;
                bool dKey;
                bool eKey;
                bool fKey;
                bool gKey;
                bool hKey;
                bool iKey;
                bool jKey;
                bool kKey;
                bool lKey;
                bool mKey;
                bool oKey;
                bool pKey;
                bool qKey;
                bool rKey;
                bool sKey;
                bool tKey;
                bool uKey;
                bool vKey;
                bool wKey;
                bool xKey;
                bool yKey;
                bool zKey;
            } data;
        };

        union EntityPacket {
            char rawData[MAX_ENTITY_LENGTH];
            struct {
                CMD tag;
                bool res;
                int entityNbr;
                Entity entities[10];
            } data;
        };

        union CommandPacket {
            char rawData[MAX_COMMAND_LENGTH];
            struct {
                CMD tag;
                bool res;
                union
                {
                    struct
                    {
                        int magicNumber;
                        bool client;
                        bool serv;
                    } _handshake;
                    struct
                    {
                        char msg[MAX_MSG_ERROR];
                    } _error;
                };
            } data;
        };

    private:
        CommandPacket _command;
        EventsPacket _events;
        EntityPacket _entity;

        void setCommand();
        void setEvents();
        void setEntity();

    public:
        PacketManager();
        ~PacketManager() {};

        RawData events(const Events &events);


        std::vector<RawData> entity(const std::vector<SerializedEntity> &entities);
        RawData handshake(bool fromServ, bool fromClient);
        RawData disconnection();
        RawData error(Protocol::CMD cmd, const std::string &msg);

        RawData getCommand() const;
        RawData getEvents() const;
        RawData getEntity() const;

        const EntityPacket &getEntityPacket() const;
        const CommandPacket &getCommandPacket() const;
        const EventsPacket &getEventPacket() const;

        void setCommand(const char *, std::size_t size);
        void setEvents(const char *, std::size_t size);
        void setEntity(const char *, std::size_t size);

        CMD getType(const char *, std::size_t size);
        bool isSuccess(const char *, std::size_t size);
        bool isValid(const char *, std::size_t, CMD tag);

        bool isValidHandshake(const char *, std::size_t, bool serv, bool client);
        bool isValidDisconnection(const char *, std::size_t);
        bool isValidEntity(const char *, std::size_t);
        bool isValidEvents(const char *, std::size_t);
    };
};

#endif //RTYPE_PACKET_HPP
