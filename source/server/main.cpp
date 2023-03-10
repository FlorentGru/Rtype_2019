/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** server/main.cpp
*/

#include "Server.hpp"

int main(int ac, char *av[])
{
    if (ac != 2)
        return (84);
    try
    {
        Server server = Server(std::stoi(av[1]));
        server.run();
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return (84);
    }
    return (0);
}