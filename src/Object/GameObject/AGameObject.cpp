/*
**
** GLOBAL GAME JAM
**
*/

#include "AGameObject.hpp"

AGameObject::AGameObject(IGameObject::GameObjectType type, sf::Time frameTime)
    : _type(type), _currentFrame(0), _t(nullptr), _anim(nullptr), _frameTime(frameTime), _currentTime(sf::Time::Zero)
{

}

AGameObject::AGameObject(const AGameObject &other)
{
    _type = other._type;
    _currentFrame = other._currentFrame;
    _t = other._t;
    _anim = other._anim;
    _frameTime = other._frameTime;
    _currentTime = other._currentTime;
}

AGameObject &AGameObject::operator=(const AGameObject &other)
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

AGameObject::~AGameObject()
{

}

void AGameObject::setAnimation(const Animation &anim)
{
    _anim = &anim;
    _t = _anim->getTexture();
    _currentFrame = 0;
    setFrame(_currentFrame);
}

void AGameObject::setFrame(std::size_t index, bool reset)
{
    if (!_anim)
        return;
    sf::IntRect rect = _anim->getFrame(index);
    _vertices[0].position = sf::Vector2f(0.f, 0.f);
    _vertices[1].position = sf::Vector2f(0.f, static_cast<float>(rect.height));
    _vertices[2].position = sf::Vector2f(static_cast<float>(rect.width), static_cast<float>(rect.height));
    _vertices[3].position = sf::Vector2f(static_cast<float>(rect.width), 0.f);
    float left = static_cast<float>(rect.left) + 0.0001f;
    float right = left + static_cast<float>(rect.width);
    float top = static_cast<float>(rect.top);
    float bottom = top + static_cast<float>(rect.height);
    _vertices[0].texCoords = sf::Vector2f(left, top);
    _vertices[1].texCoords = sf::Vector2f(left, bottom);
    _vertices[2].texCoords = sf::Vector2f(right, bottom);
    _vertices[3].texCoords = sf::Vector2f(right, top);
    if (reset)
        _currentTime = sf::Time::Zero;
}

void AGameObject::setColor(const sf::Color &color)
{
    _vertices[0].color = color;
    _vertices[1].color = color;
    _vertices[2].color = color;
    _vertices[3].color = color;
}

void AGameObject::setFrameTime(sf::Time time)
{
    _frameTime = time;
}

IGameObject::GameObjectType AGameObject::getType() const
{
    return _type;
}

const Animation *AGameObject::getAnimation() const
{
    return _anim;
}

std::size_t AGameObject::getCurrentFrame() const
{
    return _currentFrame;
}

const sf::Texture *AGameObject::getTexture() const
{
    return _t;
}

sf::FloatRect AGameObject::getLocalBounds() const
{
    sf::IntRect rect = _anim->getFrame(_currentFrame);
    float width = static_cast<float>(std::abs(rect.width));
    float height = static_cast<float>(std::abs(rect.height));
    return sf::FloatRect(0.f, 0.f, width, height);
}

sf::FloatRect AGameObject::getGlobalBounds() const
{
    return getTransform().transformRect(getLocalBounds());
}

void AGameObject::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    if (_anim && _t) {
        states.transform *= getTransform();
        states.texture = _t;
        target.draw(_vertices, 4, sf::Quads, states);
    }
}

sf::Time AGameObject::getFrameTime() const
{
    return _frameTime;
}
