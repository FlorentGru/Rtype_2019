/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** AWindow.hpp
*/

#ifndef AWINDOW_HPP
#define AWINDOW_HPP

#include "initWindow.hpp"

class AWindow
{
    public:
        virtual ~AWindow() = default;

        virtual bool initScreen(unsigned int width, unsigned int height, std::string name) = 0;
        virtual bool close() = 0;

    private:

};

#endif //AWINDOW_HPP