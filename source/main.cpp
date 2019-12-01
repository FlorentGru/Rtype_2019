/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** main.cpp
*/

#include "ClientEngine.hpp"

int main(int ac, char **av)
{
    ClientEngine client;
    Events events;
    vector<SerializedEntity> entitie;
    SerializedEntity player(IEntity::PLAYER, 1, 0, 500);
    SerializedEntity fire(IEntity::FIRE, 2, 500, 600);
    entitie.push_back(player);
    entitie.push_back(fire);

    client.setScene(Client_engine::GAME);

    while (1) {
        if (client.run(entitie, events) == false)
            return (false);
        events.resetEvent();
    }
}