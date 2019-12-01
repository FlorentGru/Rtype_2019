//
// Created by tfian on 26/11/2019.
//

#ifndef RTYPE_CLIENTMAIN_HPP
#define RTYPE_CLIENTMAIN_HPP

#include "ClientEngine.hpp"

class ClientMain
{
public:
    int main();

private:
    bool connectToServer();
    bool inGame();

    //ClientNetwork network;
    ClientEngine engine;
};


#endif //RTYPE_CLIENTMAIN_HPP
