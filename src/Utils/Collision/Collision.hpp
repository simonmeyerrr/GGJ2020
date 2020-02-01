/*
** EPITECH PROJECT, 2019
** GGJ2020
** File description:
** Collision.hpp
*/

#ifndef GGJ2020_COLLISION_HPP
#define GGJ2020_COLLISION_HPP

#include <SFML/Graphics/Sprite.hpp>

bool PixelPerfectTest(const sf::Sprite &Object1, const sf::Sprite &Object2,
    sf::Uint8 AlphaLimit
);

#endif /* GGJ2020_COLLISION_HPP */
