#include "PlayerSchool.hpp"

PlayerSchool::PlayerSchool()
        : AnimatedGameObject("assets/textures/player_school.png")
{
    Frames idleRight;
    Frames idleLeft;
    Frames walkRight;
    Frames walkLeft;
    for (int i = 0; i < 24; ++i) {
        idleRight.push_back(sf::IntRect(i * 300, 0, 300, 300));
        idleLeft.push_back(sf::IntRect(i * 300, 300, 300, 300));
        walkRight.push_back(sf::IntRect(i * 300, 600, 300, 300));
        walkLeft.push_back(sf::IntRect(i * 300, 900, 300, 300));
    }
    addFrames("idleRight", idleRight, 0.03f);
    addFrames("idleLeft", idleLeft, 0.03f);
    addFrames("walkRight", walkRight, 0.015f);
    addFrames("walkLeft", walkLeft, 0.015f);
    setCurrentAnimation("walkRight");
}