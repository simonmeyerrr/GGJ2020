/*
** EPITECH PROJECT, 2019
** GGJ2020
** File description:
** BitMaskManager.cpp
*/

#include "BitMaskManager.hpp"

BitmaskManager::BitmaskManager()
{
}

BitmaskManager::~BitmaskManager()
{
    auto end = _bitMask.end();
    for (auto iter = _bitMask.begin();
        iter != end; ++iter)
        delete[] iter->second;
}

sf::Uint8 BitmaskManager::GetPixel(const sf::Uint8 *mask,
    const sf::Texture *tex, std::size_t x, std::size_t y
)
{
    if (x > tex->getSize().x || y > tex->getSize().y)
        return 0;
    return mask[x + y * tex->getSize().x];
}

sf::Uint8 *BitmaskManager::GetMask(const sf::Texture *tex)
{
    sf::Uint8 *mask;
    auto pair = _bitMask.find(
        tex);
    if (pair == _bitMask.end()) {
        sf::Image img = tex->copyToImage();
        mask = CreateMask(tex, img);
    } else
        mask = pair->second;

    return mask;
}

sf::Uint8 *BitmaskManager::CreateMask(const sf::Texture *tex,
    const sf::Image &img
)
{
    auto* mask = new sf::Uint8[tex->getSize().y*tex->getSize().x];

    for (std::size_t y = 0; y<tex->getSize().y; ++y)
    {
        for (std::size_t x = 0; x < tex->getSize().x; ++x)
            mask[x + y * tex->getSize().x] = img.getPixel(x, y).a;
    }
    _bitMask.insert(std::pair<const sf::Texture*, sf::Uint8*>(tex, mask));
    return mask;
}
