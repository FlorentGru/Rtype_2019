/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** player.cpp
*/

#include "player.hpp"

void Player::set_position()
{
    vec_player.x = 0;
    vec_player.y = 500;
    spri_player.setPosition(vec_player.x, vec_player.y);
}

int Player::create_sprite()
{
    if (!player.loadFromFile("../../Resources/player.png"))
        return (84);
    spri_player.setTexture(player);
    spri_player.setTextureRect(sf::IntRect(0, 0, 67, 50));
    spri_player.setScale(3, 3);

    return (0);
}

bool Player::move_player()
{
    if (event.isZKey() == true) {
        std::cout << "ouis" << std::endl;
        move_up();
    }
    else if (event.isSKey() == true)
        move_down();
    else if (event.isQKey() == true)
        move_left();
    else if (event.isDKey() == true)
        move_right();
    return (true);
}

int Player::move_up()
{
    vec_player.y += 5;
    spri_player.setPosition(vec_player.x, vec_player.y);
    std::cout << "Vers le haut !!" << std::endl;
    return (0);
}

int Player::move_down()
{
    vec_player.y -= 5;
    spri_player.setPosition(vec_player.x, vec_player.y);
    std::cout << "Vers le bas !!" << std::endl;
    return (0);
}

int Player::move_left()
{
    vec_player.x -= 5;
    spri_player.setPosition(vec_player.x, vec_player.y);
    std::cout << "Vers le gauche !!" << std::endl;
    return (0);
}

int Player::move_right()
{
    vec_player.x += 5;
    spri_player.setPosition(vec_player.x, vec_player.y);
    return (0);
}

sf::Sprite Player::getPlayer() const
{
    return (spri_player);
}

Events Player::getEvents()
{
    return (event);
}