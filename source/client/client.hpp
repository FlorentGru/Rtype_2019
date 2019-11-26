/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** client/client.hpp
*/

#ifndef _CLIENT_HPP_
#define _CLIENT_HPP_

#include <iostream>
#include "background.hpp"
#include "window.hpp"

class client : public AWindow
{
    public:
        int start();
        bool initScreen(unsigned int _width, unsigned int _height, std::string name) override;
        bool close() override;
        void getInput();


    private:
        background back;
        sf::RenderWindow window;
        unsigned int _width;
        unsigned int _height;
        std::string _name;
        unsigned int _frame;
        sf::Clock clock;
	    sf::Time time;
	    float seconds;
};

#endif