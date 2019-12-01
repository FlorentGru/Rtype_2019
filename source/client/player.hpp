/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** player.hpp
*/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "Events.hpp"
#include <iostream>

class Player
{
    public:
    void set_position();
    int create_sprite();
    bool move_player();
    int move_up();
    int move_down();
    int move_left();
    int move_right();
    sf::Sprite getPlayer() const;
    Events getEvents();

    private:
        Events event;
        sf::Texture player;
        sf::Sprite  spri_player;
        sf::Vector2f vec_player;
};

#endif //PLAYER_HPP