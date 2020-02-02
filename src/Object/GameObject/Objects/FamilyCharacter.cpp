//
// Created by Jean-Gaël Choppe on 02/02/2020.
//

#include "FamilyCharacter.hpp"

FamilyCharacter::FamilyCharacter(std::string const &fileName)
: AnimatedGameObject(fileName)
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
    _pos = {0, 0};
    _basePos = {0, 0};
    _right = true;
    _isTalking = false;
}

void FamilyCharacter::setTalking(bool talking) {
    _isTalking = talking;
}

void FamilyCharacter::move(float max, float ratio) {
    if (!_isTalking) {
        if (_right) {
            setCurrentAnimation("walkLeft");
            _pos.x += ratio;
            if (_pos.x >= _basePos.x + max) {
                _right = false;
            }
        } else {
            _pos.x -= ratio;
            if (_pos.x <= _basePos.x - max)
                _right = true;
            setCurrentAnimation("walkLeft");
        }
        _s.setPosition(_pos);
    }
}

void FamilyCharacter::setPosition(sf::Vector2f f) {
    _pos = f;
    _basePos = f;
    _s.setPosition(f);
}
