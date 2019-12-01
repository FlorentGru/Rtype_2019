/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** background.hpp
*/

#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include <SFML/Graphics.hpp>

class background
{
    public:
        float move_front(sf::Vector2f front, int speed);
        float move_back(sf::Vector2f front, int speed);
        void background_move();
        void set_position();
        int create_sprite();
        sf::Sprite getBackgroundSpace() const;
        sf::Sprite getFront() const;
        sf::Sprite getBackgroundSpaceParal() const;
        sf::Sprite getFrontParal() const;

    private:
        sf::Vector2f vec_backgroundSpace;
        sf::Vector2f vec_front;
        sf::Vector2f vec_backgroundSpaceParal;
        sf::Vector2f vec_frontParal;
        sf::Texture backgroundT;
	    sf::Texture	frontT;
        sf::Sprite	spri_backgroundSpace;
	    sf::Sprite	spri_front;
        sf::Sprite	spri_backgroundSpaceParal;
	    sf::Sprite	spri_frontParal;

};

#endif //BACKGROUND_HPP