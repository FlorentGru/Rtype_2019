//
// Created by tfian on 20/11/2019.
//

#ifndef RTYPE_PACKET_HPP
#define RTYPE_PACKET_HPP

#ifndef BABELPACKET_HPP__
#define BABELPACKET_HPP__

#ifdef __GNUC__
#define PACK( __Declaration__ ) __Declaration__ __attribute__((__packed__))
#endif

#ifdef _MSC_VER
#define PACK( __Declaration__ ) __pragma( pack(push, 1) ) __Declaration__ __pragma( pack(pop))
#endif

namespace Protocol {
    enum INFO : char {
        SEPARATOR = ';',
    };

    enum PRO_SIZE : int {
        MAX_INPUT_BABEL = 30,
        MAX_MSG_ERROR = 50,
        MAX_LENGTH = 64,
        MAGIC_NBR = 42
    };

    enum CMD : unsigned char {
        NONE = 0,
        HANDSHAKE,
        SIGNIN,
        DECONNECTION,
        LOGIN,
        EXIT
    };

    class Packet
    {
    public:
        union packetData {
            char rawData[protocol::MAX_LENGTH];
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
                    struct {
                        char login[MAX_INPUT_BABEL];
                        char pass[MAX_INPUT_BABEL];
                    } _login;
                    struct
                    {
                        char login[MAX_INPUT_BABEL];
                        char pass[MAX_INPUT_BABEL];
                    } _signIn;
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
        ~Packet();

        packetData &createEmptyPacket();
        packetData &handshake(bool fromServ, bool fromClient);
        packetData &loginPacket(const std::string &name, const std::string &pass);
        packetData &signIn(const std::string &name, const std::string &pass);
        packetData &deconnection();
        //packetData &exit();
        packetData &error(const protocol::CMD cmd, const std::string &msg);
        packetData &get();
        void set(const char *, size_t size);
        bool isValid(CMD tag);
    };
};
#endif //PACKET_HPP__

#endif //RTYPE_PACKET_HPP
