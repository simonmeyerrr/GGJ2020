/*
** EPITECH PROJECT, 2019
** GGJ2020
** File description:
** Collision.cpp
*/

#include "Collision.hpp"

sf::Uint8 getPixel(const sf::Uint8 *mask, const sf::Texture &tex, std::size_t x,
    std::size_t y
)
{
    if (x > tex.getSize().x || y > tex.getSize().y)
        return 0;

    return mask[x + y * tex.getSize().x];
}

sf::Uint8 *createMask(const sf::Texture &tex, const sf::Image &img)
{
    auto *mask = new sf::Uint8[tex.getSize().y * tex.getSize().x];

    for (std::size_t y = 0; y < tex.getSize().y; ++y) {
        for (std::size_t x = 0; x < tex.getSize().x; ++x)
            mask[x + y * tex.getSize().x] = img.getPixel(x, y).a;
    }
    return mask;
}

bool pixelPerfectTest(const Sprite &Object1, const Sprite &Object2,
    sf::Uint8 AlphaLimit
)
{
    sf::FloatRect intersection;
    if (Object1.getGlobalBounds().intersects(Object2.getGlobalBounds(),
        intersection)) {
        sf::IntRect O1SubRect = Object1.getTextureRect();
        sf::IntRect O2SubRect = Object2.getTextureRect();

        sf::Uint8 *mask1 = Object1.getMask();
        sf::Uint8 *mask2 = Object2.getMask();

        // Loop through our pixels
        for (int i = intersection.left;
            (float)i < intersection.left + intersection.width; ++i) {
            for (int j = intersection.top;
                (float)j < intersection.top + intersection.height; ++j) {

                sf::Vector2f o1v = Object1.getSprite().getInverseTransform().transformPoint(
                    (float)i, (float)j);
                sf::Vector2f o2v = Object2.getSprite().getInverseTransform().transformPoint(
                    (float)i, (float)j);

                // Make sure pixels fall within the sprite's subrect
                if (o1v.x > 0 && o1v.y > 0 && o2v.x > 0 && o2v.y > 0 &&
                    o1v.x < O1SubRect.width && o1v.y < O1SubRect.height &&
                    o2v.x < O2SubRect.width && o2v.y < O2SubRect.height) {

                    if (getPixel(mask1, Object1.getTexture(),
                        (int)(o1v.x) + O1SubRect.left,
                        (int)(o1v.y) + O1SubRect.top) > AlphaLimit &&
                        getPixel(mask2, Object2.getTexture(),
                            (int)(o2v.x) + O2SubRect.left,
                            (int)(o2v.y) + O2SubRect.top) > AlphaLimit)
                        return true;
                }
            }
        }
    }
    return false;
}

bool pixelPerfectTest(const sf::RectangleShape &Object1, const sf::RectangleShape &Object2)
{
    return Object1.getGlobalBounds().intersects(Object2.getGlobalBounds());
}