/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** client/ClientDataManagement.hpp
*/

#ifndef _CLIENTDATA_HPP_
#define _CLIENTDATA_HPP_

#include <string>
#include "PacketManager.hpp"

 /**
  * Class ClientData create and do everythin with the parcket between client adn server
  */

class ClientData
{
public:
/**
 *  The constructor ClientData just set the disconnection at false
 */
    ClientData();
    /** 
    * The function run do the connect with the server and set the scene like GAME or MENU and send the events
    * 
    * @Param string : the request for the handskae
    */
    void createRequest(std::string);
    /** 
    * The getPackData is a getter for the packet
    * 
    * @return a char* who return the rawData for the packet
    */
    char *getPacketData();
    /** 
    * The getPackData is a getter for the packet
    * 
    * @Param data : the command in string who are send
    */
    void manageReceivedData(std::string request);
    /**
     * Getter of the bool Disconnection
     * 
     * @return bool because disconnection is a bool      
     */
    bool inDisconnection();
private:
    Protocol::PacketManager packet;

    bool disconnection;
};

#endif