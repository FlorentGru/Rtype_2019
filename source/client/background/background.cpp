/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** background.cpp
*/

#include "background.hpp"

float	background::move_front(sf::Vector2f front, int speed)
{
	if ((front.x - speed) > (-1279))
		front.x = front.x - speed;
	else
		front.x = 1280;
	return (front.x);
}

float	background::move_back(sf::Vector2f background, int speed)
{
	if ((background.x - speed) > -1279)
		background.x = background.x - speed;
	else
		background.x = 1280;
	return (background.x);
}

void  background::background_move()
{
	vec_front.x = move_front(vec_front, 6);
	vec_frontParal.x = move_front(vec_frontParal, 6);
	vec_backgroundSpace.x = move_back(vec_backgroundSpace, 4);
	vec_backgroundSpaceParal.x = move_back(vec_backgroundSpaceParal, 4);
}

void background::set_position()
{
    vec_front.x = 0;
	vec_front.y = 0;
	vec_backgroundSpace.x = 0;
	vec_backgroundSpace.y = 0;

	vec_frontParal.x = 1280;
	vec_frontParal.y = 0;
	vec_backgroundSpaceParal.x = 1280;
	vec_backgroundSpaceParal.y = 0;
}

int background::create_sprite()
{
    if (!backgroundT.loadFromFile("../../Resources/backgroundSpace.png"))
        return (84);
    if (!frontT.loadFromFile("../../Resources/front.png"))
        return (84);
    spri_backgroundSpace.setTexture(backgroundT);
    spri_front.setTexture(frontT);
    spri_backgroundSpaceParal.setTexture(backgroundT);
    spri_frontParal.setTexture(frontT);
}

sf::Sprite background::getBackgroundSpace() const
{
    return (spri_backgroundSpace);
}

sf::Sprite background::getFront() const
{
    return (spri_front);
}