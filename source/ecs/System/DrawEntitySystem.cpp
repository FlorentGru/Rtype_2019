/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** DrawEntitySystem.cpp
*/

#include "DrawEntitySystem.hpp"

bool DrawEntitySystem::run(vector<shared_ptr<IEntity>> &entities, Events &events)
{
    if (!_window.isOpen() && _isSucceed) {
        createWindow();
    }
    initBackground();
    if (!_isSucceed)
        return _isSucceed;
    _window.clear();
    setBackground();

    for(auto &entity: entities)
        draw(std::dynamic_pointer_cast<IRenderEntity> (entity));
    _window.display();

    getEvents(events);
    return (_isSucceed);
}

DrawEntitySystem::DrawEntitySystem()
{
    _isSucceed = true;
    sf::Vector2u windowSize(1280, 920);
    _windowSize = windowSize;
    frame = 32;
    _timer.create_clock("background");
}

void DrawEntitySystem::createWindow()
{
    _window.create(sf::VideoMode(_windowSize.x, _windowSize.y, frame), "R-Type");
}

void DrawEntitySystem::initBackground()
{
    
    sf::Texture text;
    sf::Sprite sprite;
    sf::Vector2f back(0, 0);
    sf::Vector2f front(0, 0);
    
    if (!text.loadFromFile("../../Resources/backgroundSpace.png")) {
        _isSucceed = false;
        return;
    }
    _backText.emplace("back", text);
    if (!text.loadFromFile("../../Resources/front.png")) {
        _isSucceed = false;
        return;
    }
    _backText.emplace("front", text);

    sprite.setTexture(_backText["back"]);
    _backSprite.emplace("back1", sprite);
    sprite.setTexture(_backText["back"]);
    _backSprite.emplace("back2", sprite);
    sprite.setTexture(_backText["front"]);
    _backSprite.emplace("front1", sprite);
    sprite.setTexture(_backText["front"]);
    _backSprite.emplace("front2", sprite);

    _backVector.emplace("back", back);
    _backVector.emplace("front", front);
}

void DrawEntitySystem::move(sf::Vector2f &front, float speed)
{
	if ((front.x - speed) > (-1279))
		front.x = front.x - speed;
	else
		front.x = 0;
}

void DrawEntitySystem::setBackground()
{
    if (_timer.restart("background", 0.02)) {
        move(_backVector["front"], 5);
        move(_backVector["back"], 3);
    }
    _backSprite["back1"].setPosition(_backVector["back"].x, _backVector["back"].y);
    _backSprite["back2"].setPosition(_backVector["back"].x + _windowSize.x, _backVector["back"].y);
    _backSprite["front1"].setPosition(_backVector["front"].x , _backVector["front"].y);
    _backSprite["front2"].setPosition(_backVector["front"].x + _windowSize.x, _backVector["front"].y);
    _window.draw(_backSprite["back1"]);
    _window.draw(_backSprite["back2"]);
    _window.draw(_backSprite["front1"]);
    _window.draw(_backSprite["front2"]);
}

bool DrawEntitySystem::draw(std::shared_ptr<IRenderEntity> renderEntity)
{
    if (renderEntity->getType() == IEntity::PLAYER)
        drawPlayer(std::dynamic_pointer_cast<RenderPlayer> (renderEntity));

    if (renderEntity->getType() == IEntity::FIRE)
        drawFire(std::dynamic_pointer_cast<RenderFire> (renderEntity));

    if (renderEntity->getType() == IEntity::ENEMY)
        drawEnemy(std::dynamic_pointer_cast<RenderEnemy> (renderEntity));

    if (renderEntity->getType() == IEntity::DESTRUCTIBLE)
        drawDestructible(std::dynamic_pointer_cast<RenderPlayer> (renderEntity));

    return true;
}

void    DrawEntitySystem::drawPlayer(std::shared_ptr<RenderPlayer> renderPlayer)
{
    sf::Texture playerT;
    sf::Sprite playerS;

    if (!playerT.loadFromFile(renderPlayer->getTexture()))
        _isSucceed = false;
    else {
        playerS.setTexture(playerT);
        playerS.setPosition(renderPlayer->getPosition()->getX(), renderPlayer->getPosition()->getY());
        playerS.setTextureRect(sf::IntRect(0, 0, 67, 50));
        playerS.setScale(3, 3);
        _window.draw(playerS);
    }
}

void    DrawEntitySystem::drawFire(std::shared_ptr<RenderFire> renderFire)
{
    sf::Texture fireT;
    sf::Sprite fireS;

    if (!fireT.loadFromFile(renderFire->getTexture()))
        _isSucceed = false;
    else {
        fireS.setTexture(fireT);
        fireS.setPosition(renderFire->getPosition()->getX(), renderFire->getPosition()->getY());
        fireS.setScale(3, 3);
        _window.draw(fireS);
    }
}

void    DrawEntitySystem::drawEnemy(std::shared_ptr<RenderEnemy> renderEnemy)
{
    sf::Texture playerT;
    sf::Sprite playerS;

    if (!playerT.loadFromFile(renderEnemy->getTexture()))
        _isSucceed = false;
    else {
        playerS.setTexture(playerT);
        playerS.setPosition(renderEnemy->getPosition()->getX(), renderEnemy->getPosition()->getY());
        playerS.setTextureRect(sf::IntRect(0, 0, 67, 40));
        playerS.setScale(-2, 2);
        _window.draw(playerS);
    }

}

void    DrawEntitySystem::drawDestructible(std::shared_ptr<RenderPlayer> renderPlayer)
{
    sf::Texture playerT;
    sf::Sprite playerS;

    if (!playerT.loadFromFile(renderPlayer->getTexture()))
        _isSucceed = false;
    else {
        playerS.setTexture(playerT);
        playerS.setPosition(renderPlayer->getPosition()->getX(), renderPlayer->getPosition()->getY());
        _window.draw(playerS);
    }
}

bool DrawEntitySystem::getEvents(Events &events)
{
    sf::Event event;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        events.setZKey(true);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        events.setQKey(true);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        events.setSKey(true);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        events.setDKey(true);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        events.setEnter(true);
    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            _window.close();
            _isSucceed = false;
        }
        if (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased) {
            switch (event.key.code) {
            case sf::Keyboard::A:
                events.setAKey(true);
                break;
            case sf::Keyboard::B:
                events.setBKey(true);
                break;
            case sf::Keyboard::C:
                events.setCKey(true);
                break;
            case sf::Keyboard::E:
                events.setEKey(true);
                break;
            case sf::Keyboard::F:
                events.setFKey(true);
                break;
            case sf::Keyboard::G:
                events.setGKey(true);
                break;
            case sf::Keyboard::H:
                events.setHKey(true);
                break;
            case sf::Keyboard::I:
                events.setIKey(true);
                break;
            case sf::Keyboard::J:
                events.setJKey(true);
                break;
            case sf::Keyboard::K:
                events.setKKey(true);
                break;
            case sf::Keyboard::L:
                events.setLKey(true);
                break;
            case sf::Keyboard::M:
                events.setMKey(true);
                break;
            case sf::Keyboard::N:
                events.setNKey(true);
                break;
            case sf::Keyboard::O:
                events.setOKey(true);
                break;
            case sf::Keyboard::P:
                events.setPKey(true);
                break;
            case sf::Keyboard::R:
                events.setRKey(true);
                break;
            case sf::Keyboard::T:
                events.setTKey(true);
                break;
            case sf::Keyboard::U:
                events.setUKey(true);
                break;
            case sf::Keyboard::V:
                events.setVKey(true);
                break;
            case sf::Keyboard::W:
                events.setWKey(true);
                break;
            case sf::Keyboard::X:
                events.setXKey(true);
                break;
            case sf::Keyboard::Y:
                events.setYKey(true);
                break;

            case sf::Keyboard::Left:
                events.setLeftArrow(true);
                break;
            case sf::Keyboard::Right:
                events.setRightArrow(true);
                break;
            case sf::Keyboard::Up:
                events.setUpArrow(true);
                break;
            case sf::Keyboard::Down:
                events.setDownArrow(true);
                break;
            default:
                break;
            }
        }
    }
    return true;
}