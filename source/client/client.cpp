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
    player.create_sprite();
    player.set_position();
    initScreen(1280, 920, "R-Type");

    return (0);
}

bool client::initScreen(unsigned int width, unsigned int height, std::string name)
{
    window.create(sf::VideoMode(width, height, 32), name);

    while (window.isOpen())
    {
            getInput();
            time = clock.getElapsedTime();
            seconds = time.asMicroseconds() / 200000.0;
            if (seconds > 0.2) {
                back.background_move();
                //std::cout << seconds << std::endl;
                clock.restart();
            }

            window.clear();
            window.draw(back.getBackgroundSpace());
            window.draw(back.getBackgroundSpaceParal());
            window.draw(back.getFront());
            window.draw(back.getFrontParal());
            window.draw(player.getPlayer());

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
                    this->player.getEvents().setAKey(true);
                    break;
                case sf::Keyboard::B:
                    std::cout << "B" << std::endl;
                    event_input.setBKey(true);
                    break;
                case sf::Keyboard::C:
                    std::cout << "C" << std::endl;
                    event_input.setCKey(true);
                    break;
                case sf::Keyboard::D:
                    std::cout << "D" << std::endl;
                    event_input.setDKey(true);
                    break;
                case sf::Keyboard::E:
                    std::cout << "E" << std::endl;
                    event_input.setEKey(true);
                    break;
                case sf::Keyboard::F:
                    std::cout << "F" << std::endl;
                    event_input.setFKey(true);
                    break;
                case sf::Keyboard::G:
                    std::cout << "G" << std::endl;
                    event_input.setGKey(true);
                    break;
                case sf::Keyboard::H:
                    std::cout << "H" << std::endl;
                    event_input.setHKey(true);
                    break;
                case sf::Keyboard::I:
                    std::cout << "I" << std::endl;
                    event_input.setIKey(true);
                    break;
                case sf::Keyboard::J:
                    std::cout << "J" << std::endl;
                    event_input.setJKey(true);
                    break;
                case sf::Keyboard::K:
                    std::cout << "K" << std::endl;
                    event_input.setKKey(true);
                    break;
                case sf::Keyboard::L:
                    std::cout << "L" << std::endl;
                    event_input.setLKey(true);
                    break;
                case sf::Keyboard::M:
                    std::cout << "M" << std::endl;
                    event_input.setMKey(true);
                    break;
                case sf::Keyboard::N:
                    std::cout << "N" << std::endl;
                    event_input.setNKey(true);
                    break;
                case sf::Keyboard::O:
                    std::cout << "O" << std::endl;
                    event_input.setOKey(true);
                    break;
                case sf::Keyboard::P:
                    std::cout << "P" << std::endl;
                    event_input.setPKey(true);
                    break;
                case sf::Keyboard::Q:
                    std::cout << "Q" << std::endl;
                    event_input.setQKey(true);
                    break;
                case sf::Keyboard::R:
                    std::cout << "R" << std::endl;
                    event_input.setRKey(true);
                    break;
                case sf::Keyboard::S:
                    std::cout << "S" << std::endl;
                    event_input.setSKey(true);
                    break;
                case sf::Keyboard::T:
                    std::cout << "T" << std::endl;
                    event_input.setTKey(true);
                    break;
                case sf::Keyboard::U:
                    std::cout << "U" << std::endl;
                    event_input.setUKey(true);
                    break;
                case sf::Keyboard::V:
                    std::cout << "V" << std::endl;
                    event_input.setVKey(true);
                    break;
                case sf::Keyboard::W:
                    std::cout << "W" << std::endl;
                    event_input.setWKey(true);
                    break;
                case sf::Keyboard::X:
                    std::cout << "X" << std::endl;
                    event_input.setXKey(true);
                    break;
                case sf::Keyboard::Y:
                    std::cout << "Y" << std::endl;
                    event_input.setYKey(true);
                    break;
                case sf::Keyboard::Z:
                    std::cout << "Z" << std::endl;
                    this->player.getEvents().setZKey(true);
                    std::cout << player.getEvents().isZKey() << std::endl;
                    player.move_player();
                    break;
                case sf::Keyboard::Left:
                    event_input.setLeftArrow(true);
                    break;
                case sf::Keyboard::Right:
                    event_input.setRightArrow(true);
                    break;
                case sf::Keyboard::Up:
                    event_input.setUpArrow(true);
                    break;
                case sf::Keyboard::Down:
                    event_input.setDownArrow(true);
                    break;
                case sf::Keyboard::Enter:
                    event_input.setEnter(true);
                default:
                    break;
            }
        }
    }
}