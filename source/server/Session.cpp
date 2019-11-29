/*
** EPITECH PROJECT, 2019
** r_type
** File description:
** session.cpp
*/

#include "Session.hpp"

Session::Session(std::string pseudo)
{
    std::cout << "Session constructor" << std::endl;
    pseudo_ = pseudo;
}

bool Session::addEventPacket(RawData entity)
{
    this->packets.emplace_back(entity);
}

std::vector<RawData> Session::getPacketData()
{
    std::vector<RawData> copy = packets;

    packets.clear();

    return(copy);
}