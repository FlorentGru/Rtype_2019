/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** window.hpp
*/

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "AWindow.hpp"
#include "initWindow.hpp"
#include "background.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <map>
#include <functional>

class Window : public AWindow
{
    public:
        
        sf::RenderWindow getWindow();

    private:
        
};

#endif //WINDOW_HPP