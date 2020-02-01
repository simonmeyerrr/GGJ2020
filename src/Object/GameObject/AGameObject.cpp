/*
**
** GLOBAL GAME JAM
**
*/

#include "AGameObject.hpp"

AGameObject::AGameObject(IGameObject::Type type, const std::string &path, const Frame &r)
    : _type(type), _t(), _s()
{
    _t.loadFromFile(path);
    _s.setTexture(_t);
    _s.setTextureRect(r);
    sf::Image image;
    image.loadFromFile(path);
    _mask = std::make_shared<sf::Uint8 *>(createMask(*_texture, image));
    _sprite->setTextureRect(rect);

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

void AGameObject::setTexture(const sf::Texture &t)
{
    _t = t;
}