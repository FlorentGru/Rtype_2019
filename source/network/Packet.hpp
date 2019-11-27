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

namespace Protocol
{
    enum INFO : char {
        SEPARATOR = ';',
    };

    enum PRO_SIZE : int {
        MAX_MSG_ERROR = 50,
        MAX_LENGTH = 64,
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
        union packetData {
            char rawData[Protocol::MAX_LENGTH];
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
        packetData _data;

    public:
        Packet();
        ~Packet() {};

        packetData &createEmptyPacket();
        packetData &handshake(bool fromServ, bool fromClient);
        packetData &deconnection();
        packetData &error(const Protocol::CMD cmd, const std::string &msg);
        packetData &get();
        void set(const char *, std::size_t size);
        bool isValid(CMD tag);
    };
};

#endif //RTYPE_PACKET_HPP
