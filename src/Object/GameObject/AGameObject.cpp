/*
**
** GLOBAL GAME JAM
**
*/

#include "../../Utils/Collision/Collision.hpp"
#include "AGameObject.hpp"

AGameObject::AGameObject(IGameObject::Type type, const std::string &path, const Frame &r)
    : _type(type), _t(), _s()
{
    _t.loadFromFile(path);
    _s.setTexture(_t);
    sf::Image image;
    image.loadFromFile(path);
    _mask = createMask(&_t, image);
    _s.setTextureRect(r);
}

AGameObject::AGameObject(const AGameObject &other)
{
    _type = other._type;
    _t = other._t;
    _s = other._s;
}

AGameObject &AGameObject::operator=(const AGameObject &other)
{
    if (this != &other) {
        _type = other._type;
        _t = other._t;
        _s = other._s;
    }
    return *this;
}

IGameObject::Type AGameObject::getType() const
{
    return _type;
}

const sf::Texture &AGameObject::getTexture() const
{
    return _t;
}

const sf::Sprite &AGameObject::getSprite() const
{
    return _s;
}

const sf::Vector2f &AGameObject::getPosition() const
{
    return _s.getPosition();
}

void AGameObject::setTexture(const sf::Texture &t)
{
    _t = t;
}

void AGameObject::setPosition(const sf::Vector2f &pos)
{
    _s.setPosition(pos);
}

Mask *AGameObject::getMask() const
{
    return _mask;
}
