//
// Created by tfian on 28/11/2019.
//

#ifndef RTYPE_CLIENT_HPP
#define RTYPE_CLIENT_HPP

#include "ClientNetwork.hpp"
#include "ClientEngine.hpp"

 /**
  * Class Client who is the called by the main, make the connection with the server
  */

class Client
{
public:
    /** The function run do the connect with the server and set the scene like GAME or MENU and send the events
         * 
         * @Param host : the ip adrdress of the server
         * @Param port: the port of the server
         * 
         * @return a bool to check if the server disconnect or not and if an error arrivec 
         */
    bool run(const std::string &host, const std::string &port);
private:
    ClientNetwork network;
    ClientEngine engine;
};


#endif //RTYPE_CLIENT_HPP
