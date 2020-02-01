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
}

AGameObject::~AGameObject()
{

}

IGameObject::GameObjectType AGameObject::getType() const
{
    return _type;
}

sf::FloatRect AGameObject::getLocalBounds() const
{

}

sf::FloatRect AGameObject::getGlobalBounds() const
{
    
}

void AGameObject::setColor(const sf::Color &)
{

}
