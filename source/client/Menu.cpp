/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Menu.cpp
*/

#include "Menu.hpp"

Menu::Menu(unsigned int width, unsigned int height)
{
    if(!font.loadFromFile("../../Resources/Perfect_DOS_VGA_437.ttf")) {

    }

    text[0].setFont(font);
    text[0].setColor(sf::Color::Green);
    text[0].setString("Play");
    text[0].setPosition(sf::Vector2f(width / (MAX_ITEMS + 1) *1, height / 1.5));

    text[1].setFont(font);
    text[1].setColor(sf::Color::White);
    text[1].setString("Options");
    text[1].setPosition(sf::Vector2f(width / (MAX_ITEMS + 1) * 2, height / 1.5));
    
    text[2].setFont(font);
    text[2].setColor(sf::Color::White);
    text[2].setString("Quit");
    text[2].setPosition(sf::Vector2f(width / (MAX_ITEMS + 1) * 3, height / 1.5));

}

Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{
    for(int i = 0; i < MAX_ITEMS; i++) {
        window.draw(text[i]);
    }
}

void Menu::MoveLeft()
{
    if (selectItem - 1 >= 0) {
        text[selectItem].setColor(sf::Color::White);
        selectItem--;
        text[selectItem].setColor(sf::Color::Green);
    }
}

void Menu::MoveRight()
{
    if (selectItem + 1 < MAX_ITEMS) {
        text[selectItem].setColor(sf::Color::White);
        selectItem++;
        text[selectItem].setColor(sf::Color::Green);
    }
}