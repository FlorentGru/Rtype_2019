/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** DrawEntitySystem.hpp
*/

#ifndef DRAWENTITYSYSTEM_HPP
#define DRAWENTITYSYSTEM_HPP

#include <memory>
#include <map>
#include "RenderPlayer.hpp"
#include "RenderFire.hpp"
#include "IRenderSystem.hpp"
#include "RenderEnemy.hpp"
#include "Timer.hpp"
#include <SFML/Graphics.hpp>

/**
 *  Class who include the most bigest part of SFML who draw all the entities and the window/Background
 */

class DrawEntitySystem : public IRenderSystem
{
    public:
        /** The function run who start and create all of the graphical creation
         * 
         * @Param entities: took all the entities to call the system for draw the entities
         * @Param events: Take the events for the getEvents who fill all the events do
         * 
         * @return a bool to check if the function return true and works, 
         */
        bool run(vector<shared_ptr<IEntity>> &entities, Events &events) override;
        /** Constructor of the class, set the windowSize and the frame and create the clock for the background */
        DrawEntitySystem();
    
    private:
        void createWindow() override;
        void setBackground();
        bool draw(std::shared_ptr<IRenderEntity> renderEntity) override;
        void drawPlayer(std::shared_ptr<RenderPlayer>);
        void drawFire(std::shared_ptr<RenderFire>);
        void drawEnemy(std::shared_ptr<RenderEnemy>);
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