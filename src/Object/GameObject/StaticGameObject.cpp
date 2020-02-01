/*
**
** GLOBAL GAME JAM
**
*/

#include "StaticGameObject.hpp"

StaticGameObject::StaticGameObject(sf::Time frameTime)
    : AGameObject(IGameObject::GameObjectType::STATIC, frameTime)
{

}

StaticGameObject::StaticGameObject(const StaticGameObject &other)
    : AGameObject(other)
{
}

StaticGameObject &StaticGameObject::operator=(const StaticGameObject &other)
{
    if (&other != this) {
        _type = other._type;
        _currentFrame = other._currentFrame;
        _t = other._t;
        _anim = other._anim;
        _frameTime = other._frameTime;
        _currentTime = other._currentTime;
    }
    return *this;
}

void StaticGameObject::update(sf::Time elapsedTime)
{

}