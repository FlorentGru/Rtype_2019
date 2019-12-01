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
	if ((background.x - speed) > (-1279))
		background.x = background.x - speed;
	else
		background.x = 1280;
	return (background.x);
}

void  background::background_move()
{
	vec_front.x = move_front(vec_front, 5);
	vec_frontParal.x = move_front(vec_frontParal, 5);
	vec_backgroundSpace.x = move_back(vec_backgroundSpace, 3);
	vec_backgroundSpaceParal.x = move_back(vec_backgroundSpaceParal, 3);

    spri_backgroundSpace.setPosition(vec_backgroundSpace.x, vec_backgroundSpace.y);
    spri_backgroundSpaceParal.setPosition(vec_backgroundSpaceParal.x, vec_backgroundSpaceParal.y);
    spri_front.setPosition(vec_front.x, vec_front.y);
    spri_frontParal.setPosition(vec_frontParal.x, vec_frontParal.y);

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
    
    backgroundT.setSmooth(true);
    frontT.setSmooth(true);
    spri_backgroundSpace.setTexture(backgroundT);
    spri_backgroundSpaceParal.setTexture(backgroundT);
    spri_front.setTexture(frontT);
    spri_frontParal.setTexture(frontT);

    return (0);
}

sf::Sprite background::getBackgroundSpace() const
{
    return (spri_backgroundSpace);
}

sf::Sprite background::getBackgroundSpaceParal() const
{
    return (spri_backgroundSpaceParal);
}

sf::Sprite background::getFront() const
{
    return (spri_front);
}

sf::Sprite background::getFrontParal() const
{
    return (spri_frontParal);
}