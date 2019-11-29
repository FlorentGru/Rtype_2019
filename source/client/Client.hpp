//
// Created by tfian on 28/11/2019.
//

#ifndef RTYPE_CLIENT_HPP
#define RTYPE_CLIENT_HPP

#include "ClientNetwork.hpp"

class Client
{
public:
    bool run(const std::string &host, const std::string &port);
private:
    ClientNetwork network;
};


#endif //RTYPE_CLIENT_HPP
