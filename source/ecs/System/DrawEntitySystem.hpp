/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** DrawEntitySystem.hpp
*/

#ifndef DRAWENTITYSYSTEM_HPP
#define DRAWENTITYSYSTEM_HPP

#include <memory>
#include <iostream>
#include <map>
#include "RenderPlayer.hpp"
#include "RenderFire.hpp"
#include "IRenderSystem.hpp"
#include "Timer.hpp"
#include <SFML/Graphics.hpp>


class DrawEntitySystem : public IRenderSystem
{
    public:
        bool run(vector<shared_ptr<IEntity>> &entities, Events &events) override;
        DrawEntitySystem();
    
    private:
        void CreateWindow() override;
        void setBackground();
        bool draw(std::shared_ptr<IRenderEntity> renderEntity) override;
        void drawPlayer(std::shared_ptr<RenderPlayer>);
        void drawFire(std::shared_ptr<RenderFire>);
        void drawEnemy(std::shared_ptr<RenderPlayer>);
        void drawDestructible(std::shared_ptr<RenderPlayer>);
        void initBackground();
        void move(sf::Vector2f &font, float speed);
        bool getEvents(Events &events);

        bool _isSucceed;
        sf::RenderWindow _window;
        sf::Vector2u _windowSize;
        int frame;
        std::map<std::string, sf::Texture> _backText;
	    std::map<std::string, sf::Sprite> _backSprite;
        std::map<std::string, sf::Vector2f> _backVector;
        Timer _timer;
};

#endif //DRAWENTITYSYSTEM_HPP