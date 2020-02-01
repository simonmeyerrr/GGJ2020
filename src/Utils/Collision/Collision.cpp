/*
** EPITECH PROJECT, 2019
** GGJ2020
** File description:
** Collision.cpp
*/

#include "Collision.hpp"

bool collisionTest(const sf::Sprite &sprite1, const sf::Sprite &sprite2)
{
    return sprite1.getGlobalBounds().intersects(sprite2.getGlobalBounds());
}