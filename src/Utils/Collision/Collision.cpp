/*
** EPITECH PROJECT, 2019
** GGJ2020
** File description:
** Collision.cpp
*/

#include "Collision.hpp"
#include "BitMaskManager.hpp"

bool PixelPerfectTest(const sf::Sprite &Object1, const sf::Sprite &Object2,
    sf::Uint8 AlphaLimit
)
{
    BitmaskManager Bitmasks;
    sf::FloatRect Intersection;

    if (!(Object1.getGlobalBounds().intersects(Object2.getGlobalBounds(),
        Intersection)))
        return false;
    sf::IntRect O1SubRect = Object1.getTextureRect();
    sf::IntRect O2SubRect = Object2.getTextureRect();

    sf::Uint8 *mask1 = Bitmasks.GetMask(Object1.getTexture());
    sf::Uint8 *mask2 = Bitmasks.GetMask(Object2.getTexture());

    for (int i = Intersection.left;
        (float)i < Intersection.left + Intersection.width; ++i) {
        for (int j = Intersection.top;
            (float)j < Intersection.top + Intersection.height; ++j) {

            sf::Vector2f o1v = Object1.getInverseTransform().transformPoint(
                (float)i, (float)j);
            sf::Vector2f o2v = Object2.getInverseTransform().transformPoint(
                (float)i, (float)j);

            if (o1v.x > 0 && o1v.y > 0 && o2v.x > 0 && o2v.y > 0 &&
                o1v.x < O1SubRect.width && o1v.y < O1SubRect.height &&
                o2v.x < O2SubRect.width && o2v.y < O2SubRect.height) {

                if (Bitmasks.GetPixel(mask1, Object1.getTexture(),
                    (int)(o1v.x) + O1SubRect.left,
                    (int)(o1v.y) + O1SubRect.top) > AlphaLimit &&
                    Bitmasks.GetPixel(mask2, Object2.getTexture(),
                        (int)(o2v.x) + O2SubRect.left,
                        (int)(o2v.y) + O2SubRect.top) > AlphaLimit)
                    return true;
            }
        }
    }
    return false;
}