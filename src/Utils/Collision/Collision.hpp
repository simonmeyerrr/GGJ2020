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
#include <SFML/Graphics/RectangleShape.hpp>
#include "../../Object/GameObject/IGameObject.hpp"
#include "../../Object/UIObject/Sprite.hpp"


sf::Uint8 *createMask(const sf::Texture &tex, const sf::Image &img);
sf::Uint8 getPixel(const sf::Uint8 *mask, const sf::Texture &tex, std::size_t x,
    std::size_t y);

bool pixelPerfectTest(const IGameObject &, const IGameObject &,
    sf::Uint8 AlphaLimit = 0);


#endif /* GGJ2020_COLLISION_HPP */
