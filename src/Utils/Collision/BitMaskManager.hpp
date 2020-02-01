/*
** EPITECH PROJECT, 2019
** GGJ2020
** File description:
** BitMaskManager.hpp
*/

#ifndef GGJ2020_BITMASKMANAGER_HPP
#define GGJ2020_BITMASKMANAGER_HPP

#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <map>

class BitmaskManager {
public:
    BitmaskManager();
    BitmaskManager(const BitmaskManager &) = delete;
    const BitmaskManager &operator=(const BitmaskManager &) = delete;

    ~BitmaskManager();

    sf::Uint8 GetPixel(const sf::Uint8 *mask, const sf::Texture *tex,
        std::size_t x, std::size_t y
    );
    sf::Uint8 *GetMask(const sf::Texture *tex);
    sf::Uint8 *CreateMask(const sf::Texture *tex, const sf::Image &img);

private:
    std::map<const sf::Texture *, sf::Uint8 *> _bitMask;
};

#endif /* GGJ2020_BITMASKMANAGER_HPP */
