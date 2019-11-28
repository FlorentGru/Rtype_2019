/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** server/main.cpp
*/

#include "Client.hpp"

int main(int ac, char *av[])
{
    if (ac != 3)
        return(84);
    try {
        Client client(av[1], av[2]);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return (84);
    }
    return (0);
}