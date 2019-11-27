/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** server/main.cpp
*/

#include "Client.hpp"

int main(int ac, char *av[])
{
    try {
        boost::asio::io_context io_context;
        Client client(io_context, av[1], av[2]);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return (84);
    }
    return (0);
}