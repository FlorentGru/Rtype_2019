/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Menu.hpp
*/

#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

#define MAX_ITEMS 3

class Menu
{
    public:
        Menu(unsigned int width, unsigned int height);
        ~Menu();

        void draw(sf::RenderWindow &window);
        void MoveLeft();
        void MoveRight();
    private:
        int selectItem;
        sf::Font font;
        sf::Text text[MAX_ITEMS];
};

#endif //MENU_HPP