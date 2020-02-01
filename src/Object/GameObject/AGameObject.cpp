/*
**
** GLOBAL GAME JAM
**
*/

#include "AGameObject.hpp"

AGameObject::AGameObject(IGameObject::GameObjectType type)
    : _type(type)
{

}

AGameObject::AGameObject(const AGameObject &other)
{
    _type = other._type;
}

AGameObject &AGameObject::operator=(const AGameObject &other)
{
    if (&other != this) {
        _type = other._type;
    }
    return *this;
}

AGameObject::~AGameObject()
{

}

IGameObject::GameObjectType AGameObject::getType() const
{
    return _type;
}

void AGameObject::setColor(const sf::Color &color)
{
    _vertices[0].color = color;
    _vertices[1].color = color;
    _vertices[2].color = color;
    _vertices[3].color = color;
}
