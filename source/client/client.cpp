/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** client.cpp
*/

#include "client.hpp"

int client::start()
{
    back.create_sprite();
    back.set_position();
    initScreen(1280, 920, "R-Type");
    getInput();
    

    return (0);
}

bool client::initScreen(unsigned int width, unsigned int height, std::string name)
{
    window.create(sf::VideoMode(width, height, 32), name);

    while (window.isOpen())
    {
        sf::Event event;
        if (event.type == sf::Event::Closed)
            window.close();

        window.clear();
        window.draw(back.getBackgroundSpace());
        window.draw(back.getFront());

        window.display();
    }
    return EXIT_SUCCESS;
}

bool client::close()
{
    if (window.isOpen())
        window.close();

    return (true);
}

void client::getInput()
{
    sf::Event event;

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased) {
            switch (event.key.code) {
                case sf::Keyboard::A:
                    std::cout << "A" << std::endl;
                    break;
                case sf::Keyboard::B:
                    std::cout << "B" << std::endl;
                    break;
                case sf::Keyboard::C:
                    std::cout << "C" << std::endl;
                    break;
                case sf::Keyboard::D:
                    std::cout << "D" << std::endl;
                    break;
                case sf::Keyboard::E:
                    std::cout << "E" << std::endl;
                    break;
                case sf::Keyboard::F:
                    std::cout << "F" << std::endl;
                    break;
                case sf::Keyboard::G:
                    std::cout << "G" << std::endl;
                    break;
                case sf::Keyboard::H:
                    std::cout << "H" << std::endl;
                    break;
                case sf::Keyboard::I:
                    std::cout << "I" << std::endl;
                    break;
                case sf::Keyboard::J:
                    std::cout << "J" << std::endl;
                    break;
                case sf::Keyboard::K:
                    std::cout << "K" << std::endl;
                    break;
                case sf::Keyboard::L:
                    std::cout << "L" << std::endl;
                    break;
                case sf::Keyboard::M:
                    std::cout << "M" << std::endl;
                    break;
                case sf::Keyboard::N:
                    std::cout << "N" << std::endl;
                    break;
                case sf::Keyboard::O:
                    std::cout << "O" << std::endl;
                    break;
                case sf::Keyboard::P:
                    std::cout << "P" << std::endl;
                    break;
                case sf::Keyboard::Q:
                    std::cout << "Q" << std::endl;
                    break;
                case sf::Keyboard::R:
                    std::cout << "R" << std::endl;
                    break;
                case sf::Keyboard::S:
                    std::cout << "S" << std::endl;
                    break;
                case sf::Keyboard::T:
                    std::cout << "T" << std::endl;
                    break;
                case sf::Keyboard::U:
                    std::cout << "U" << std::endl;
                    break;
                case sf::Keyboard::V:
                    std::cout << "V" << std::endl;
                    break;
                case sf::Keyboard::W:
                    std::cout << "W" << std::endl;
                    break;
                case sf::Keyboard::X:
                    std::cout << "X" << std::endl;
                    break;
                case sf::Keyboard::Y:
                    
                    break;
                case sf::Keyboard::Z:
                    
                    break;
                case sf::Keyboard::Left:

                    break;
                case sf::Keyboard::Right:

                    break;
                case sf::Keyboard::Up:

                    break;
                case sf::Keyboard::Down:

                    break;
                default:
                    break;
            }
        }
    }
}