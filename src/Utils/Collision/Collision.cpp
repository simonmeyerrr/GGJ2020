/*
** EPITECH PROJECT, 2019
** GGJ2020
** File description:
** Collision.cpp
*/

#include "Collision.hpp"

Mask *createMask(sf::Texture const *t, sf::Image const &i)
{
    Mask *mask = new Mask{t->getSize().x, t->getSize().y,
        new sf::Uint8[t->getSize().x * t->getSize().y]};
    for (std::size_t y = 0; y < t->getSize().y; ++y)
        for (std::size_t x = 0; x < t->getSize().x; ++x)
            (x + y * t->getSize().x)[mask->pix] = i.getPixel(x, y).a;
    return mask;
}

enum Mov {
    jmp = -1,
    no,
    fall,
    left = -1,
    g,
    right,
    d = 1
};

#define ABS(X)(0>X?-X:X)

std::size_t collideUp(Mask &hum_m, Mask &map_m, Obj &hum, Obj &map,
    std::size_t range
)
{
    std::size_t min = range;
    bool map_b, hum_b;
    for (std::size_t y = 0; y < range; ++y)
        for (std::size_t x = 0; x < hum.width; ++x) {
            map_b = ((hum.x - map.x + x) +
                (ABS(hum.y) + y) * map.width)[map_m.pix];
            hum_b = (x + y * hum.width)[hum_m.pix];
            if (map_b && hum_b)
                min = min > y ? y : min;
        }
    return min;
}

std::size_t collideDown(Mask *hum_m, Mask *map_m, const sf::Sprite &hum, const sf::Sprite &map,
    std::size_t range
)
{
    std::size_t min = range;
    bool map_b, hum_b;
    for (std::size_t y = 0; y < range; ++y)
        for (std::size_t x = 0; x < (std::size_t)hum.getTexture()->getSize().x; ++x) {
            map_b = ((int)((hum.getPosition().x - map.getPosition().x + x) +
                (ABS(hum.getPosition().y) + hum.getTexture()->getSize().y - y) * map.getTexture()->getSize().x))[map_m->pix];
            hum_b = (x + (hum.getTexture()->getSize().y - y) * hum.getTexture()->getSize().x)[hum_m->pix];
            if (map_b && hum_b)
                min = min > y ? y : min;
        }
    return min;
}

std::size_t collideLeft(Mask &hum_m, Mask &map_m, Obj &hum, Obj &map,
    std::size_t range
)
{
    std::size_t min = range;
    bool map_b, hum_b;
    for (std::size_t y = 0; y < hum.height; ++y)
        for (std::size_t x = 0; x < range; ++x) {
            map_b = ((hum.x - map.x + x) +
                (ABS(hum.y) + y) * map.width)[map_m.pix];
            hum_b = (x + y * hum.width)[hum_m.pix];
            if (map_b && hum_b)
                min = min > x ? x : min;
        }
    return min;
}

std::size_t collideRight(Mask &hum_m, Mask &map_m, Obj &hum, Obj &map,
    std::size_t range
)
{
    std::size_t min = range;
    bool map_b, hum_b;
    for (std::size_t y = 0; y < hum.height; ++y)
        for (std::size_t x = 0; x < range; ++x) {
            map_b = ((hum.x - map.x + (hum.width - x)) +
                (ABS(hum.y) + y) * map.width)[map_m.pix];
            hum_b = ((hum.width - x) + y * hum.width)[hum_m.pix];
            if (map_b && hum_b)
                min = min > x ? x : min;
        }
    return min;
}

//bool pixelPerfectTest(const IGameObject &Object1, const IGameObject &Object2,
//    sf::Uint8 AlphaLimit
//)
//{
//    sf::FloatRect intersection;
//    if (Object1.getSprite().getGlobalBounds().intersects(Object2.getSprite().getGlobalBounds(),
//        intersection)) {
//        sf::IntRect O1SubRect = Object1.getSprite().getTextureRect();
//        sf::IntRect O2SubRect = Object2.getSprite().getTextureRect();
//
//        sf::Uint8 *mask1 = Object1.getMask();
//        sf::Uint8 *mask2 = Object2.getMask();
//
//        // Loop through our pixels
//
//        for (int i = intersection.left;
//            (float)i < intersection.left + intersection.width; i += 2) {
//            for (int j = intersection.top;
//                (float)j < intersection.top + intersection.height; j += 2) {
//
//                sf::Vector2f o1v = Object1.getSprite().getInverseTransform().transformPoint(
//                    (float)i, (float)j);
//                sf::Vector2f o2v = Object2.getSprite().getInverseTransform().transformPoint(
//                    (float)i, (float)j);
//
//                // Make sure pixels fall within the sprite's subrect
//                if (o1v.x > 0 && o1v.y > 0 && o2v.x > 0 && o2v.y > 0 &&
//                    o1v.x < O1SubRect.width && o1v.y < O1SubRect.height &&
//                    o2v.x < O2SubRect.width && o2v.y < O2SubRect.height) {
//
//                    if (getPixel(mask1, Object1.getTexture(),
//                        (int)(o1v.x) + O1SubRect.left,
//                        (int)(o1v.y) + O1SubRect.top) > AlphaLimit &&
//                        getPixel(mask2, Object2.getTexture(),
//                            (int)(o2v.x) + O2SubRect.left,
//                            (int)(o2v.y) + O2SubRect.top) > AlphaLimit) {
//                        return true;
//                    }
//                }
//            }
//        }
//    }
//    return false;
//}