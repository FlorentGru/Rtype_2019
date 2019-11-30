/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** EventSystem.hpp
*/

#ifndef EVENTSYSTEM_HPP
#define EVENTSYSTEM_HPP

#include <SFML/Graphics.hpp>
#include "IEventsSystem.hpp"

class EventSystem : public IEventsSystem
{
    public:
        bool run(vector<shared_ptr<IEntity>> &entities, Events &events) override;        
    private:
        bool getEvents(Events &events);
        sf::Event _event;
};

#endif //EVENTSYSTEM_HPP