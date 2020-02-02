/*
** EPITECH PROJECT, 2019
** GGJ2020
** File description:
** Collision.hpp
*/

#ifndef GGJ2020_COLLISION_HPP
#define GGJ2020_COLLISION_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Color.hpp>

struct Mask {
    ssize_t const x, y;
    sf::Uint8 *pix;
};

struct Obj {
    sf::Sprite &&sprite;
    std::size_t width = 0, height = 0;
    ssize_t x = 0, y = 0;
};

Mask *createMask(sf::Texture const *, sf::Image const &i);


std::size_t collideDown(Mask *hum_m, Mask *map_m, const sf::Sprite &hum, const sf::Sprite &map,
    std::size_t range
);
//bool pixelPerfectTest(const IGameObject &, const IGameObject &,
//    sf::Uint8 AlphaLimit = 0);


#endif /* GGJ2020_COLLISION_HPP */
