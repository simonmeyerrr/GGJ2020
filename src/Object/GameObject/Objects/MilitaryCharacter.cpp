/*
**
** GLOBAL GAME JAM
**
*/

#include "MilitaryCharacter.hpp"

MilitaryCharacter::MilitaryCharacter()
: AnimatedGameObject("assets/textures/player_soldat.png")
{
    Frames idleRight;
    Frames idleLeft;
    Frames walkRight;
    Frames walkLeft;
    Frames crouchRight;
    Frames crouchLeft;
    Frames climbRight;
    Frames climbLeft;
    Frames runRight;
    Frames runLeft;
    for (int i = 0; i < 24; ++i) {
        idleRight.push_back(sf::IntRect(i * 300, 0, 300, 300));
        idleLeft.push_back(sf::IntRect(i * 300, 300, 300, 300));
        walkRight.push_back(sf::IntRect(i * 300, 600, 300, 300));
        walkLeft.push_back(sf::IntRect(i * 300, 900, 300, 300));
        crouchRight.push_back(sf::IntRect(i * 300, 1200, 300, 300));
        crouchLeft.push_back(sf::IntRect(i * 300, 1500, 300, 300));
        climbRight.push_back(sf::IntRect(i * 300, 1800, 300, 300));
        climbLeft.push_back(sf::IntRect(i * 300, 2100, 300, 300));
        runRight.push_back(sf::IntRect(i * 300, 2400, 300, 300));
        runLeft.push_back(sf::IntRect(i * 300, 2700, 300, 300));
    }
    addFrames("idleRight", idleRight, 0.03f);
    addFrames("idleLeft", idleLeft, 0.03f);
    addFrames("walkRight", walkRight, 0.035f);
    addFrames("walkLeft", walkLeft, 0.035f);
    addFrames("crouchRight", crouchRight, 0.035f);
    addFrames("crouchLeft", crouchLeft, 0.035f);
    addFrames("climbRight", climbRight, 0.035f);
    addFrames("climbLeft", climbLeft, 0.035f);
    addFrames("runRight", runRight, 0.035f);
    addFrames("runLeft", runLeft, 0.035f);
    setCurrentAnimation("walkRight");
}