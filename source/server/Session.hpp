/*
** EPITECH PROJECT, 2019
** r_type
** File description:
** session.cpp
*/

#ifndef _SESSION_HPP_
#define _SESSION_HPP_

#include "ISession.hpp"

class Session : public ISession
{
public:
    Session(std::string pseudo);
    char *getPacketData() override;
    void taskManager(std::string) override;
private:
    std::string pseudo_;
};

#endif