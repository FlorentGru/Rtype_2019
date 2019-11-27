/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** server/main.cpp
*/

#include "client.hpp"

int main(int ac, char *av[])
{
    try {
        boost::asio::io_context io_context;
        Client client(io_context, av[1], av[2]);
        std::string message;
        boost::thread t(boost::bind(&boost::asio::io_context::run, &io_context));
        io_context.run();
        std::cout << "azerty" << std::endl;
        t.join();
        std::cout << "azerty2" << std::endl;
        while(true)
        {
            std::cout << "azerty3" << std::endl;
            std::cin >> message;
            client.send(message);
            client.receive();
        }

        //io_context.run();
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return (84);
    }
    return (0);
}