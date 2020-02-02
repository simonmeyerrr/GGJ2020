/*
**
** GLOBAL GAME JAM
**
*/

#include "PlayerOld.hpp"

PlayerOld::PlayerOld()
    : AnimatedGameObject("assets/textures/player_old.png")
{
    Frames idleRight;
    Frames idleLeft;
    Frames walkRight;
    Frames walkLeft;
    for (int i = 0; i < 24; ++i) {
        idleRight.push_back(sf::IntRect(i * 600, 0, 600, 600));
        idleLeft.push_back(sf::IntRect(i * 600, 600, 600, 600));
        walkRight.push_back(sf::IntRect(i * 600, 1200, 600, 600));
        walkLeft.push_back(sf::IntRect(i * 600, 1800, 600, 600));
    }
    addFrames("idleRight", idleRight, 0.03f);
    addFrames("idleLeft", idleLeft, 0.03f);
    addFrames("walkRight", walkRight, 0.035f);
    addFrames("walkLeft", walkLeft, 0.035f);
    setCurrentAnimation("walkRight");
}