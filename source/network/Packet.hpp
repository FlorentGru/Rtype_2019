/*
** EPITECH PROJECT, 2019
** r_type
** File description:
** packet.hpp
*/

#ifndef _RTYPEPACKET_HPP_
#define _RTYPEPACKET_HPP_

// #ifdef __GNUC__
// #define PACK( __Declaration__ ) __Declaration__ __attribute__((__packed__))
// #endif

// #ifdef _MSC_VER
// #define PACK( __Declaration__ ) __pragma( pack(push, 1) ) __Declaration__ __pragma( pack(pop))
// #endif

#include "iostream"
#include "Events.hpp"

namespace Protocol
{
    enum INFO : char {
        SEPARATOR = ';',
    };

    enum PRO_SIZE : int {
        MAX_MSG_ERROR = 50,
        MAX_COMMAND_LENGTH = 64,
        MAX_EVENT_LENGTH = 128,
        MAX_ENTITY_LENGTH = 256,
        MAGIC_NBR = 42
    };

    enum CMD : unsigned char {
        NONE = 0,
        HANDSHAKE,
        DISCONNECTION
    };

    class Packet
    {
    public:
        struct Entity {
            int id;
            int type;
            float posX;
            float posY;
        };

        union EventsPacket {
            char rawData[MAX_EVENT_LENGTH];
            struct data {
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
            };
        };

        union EntityPacket {
            char rawData[MAX_ENTITY_LENGTH];
            struct data {
                CMD tag;
                bool res;
                int entityNbr;
                Entity entities[10];
            };
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
        Packet();
        ~Packet() {};

//        EventsPacket &events(const Events &events);

//        vector<EntityPacket> entity(const vector<SerializedEntity> &entities);

        CommandPacket &handshake(bool fromServ, bool fromClient);
        CommandPacket &disconnection();
        CommandPacket &error(Protocol::CMD cmd, const std::string &msg);
        CommandPacket &getCommand();

        void setCommand(const char *, std::size_t size);
        void setEvents(const char *, std::size_t size);
        void setEntity(const char *, std::size_t size);

        bool isValid(CMD tag);
    };
};

#endif //RTYPE_PACKET_HPP
