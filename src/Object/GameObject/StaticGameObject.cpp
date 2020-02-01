/*
**
** GLOBAL GAME JAM
**
*/

#include "StaticGameObject.hpp"

StaticGameObject::StaticGameObject(const std::string &path, sf::IntRect r)
    : AGameObject(IGameObject::Type::STATIC, path, r)
{

}

StaticGameObject::StaticGameObject(const StaticGameObject &other)
    : AGameObject(other)
{
}

StaticGameObject &StaticGameObject::operator=(const StaticGameObject &other)
{
    return *this;
}

void StaticGameObject::update()
{
    
}