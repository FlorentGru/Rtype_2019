/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** server/main.cpp
*/

#include "Server.hpp"

int main(int ac, char *av[])
{
    try
    {
        boost::asio::io_context ioContext;
//        std::unique_ptr<AServer> s(new server(io_context, std::stoi(argv[1])));
        Server server(ioContext, std::stoi(av[1]));
        ioContext.run();
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return (84);
    }
    return (0);
}