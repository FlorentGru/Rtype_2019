/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** main.cpp
*/

#include "ClientEngine.hpp"
#include "GameEngine.hpp"

int main(int ac, char **av)
{
    ClientEngine client;
    GameEngine gameEngine;
    Events events;
    vector<SerializedEntity> entitie;
    SerializedEntity player(IEntity::PLAYER, 1, 0, 500);
    SerializedEntity fire(IEntity::FIRE, 2, 500, 600);
    entitie.push_back(player);
    entitie.push_back(fire);

    client.setScene(Client_engine::GAME);

    while (1) {
        if (!client.run(entitie, events))
            return (false);
        entitie = gameEngine.run(events);
        events.resetEvent();
    }
}