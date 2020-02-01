/*
**
** GLOBAL GAME JAM
**
*/

#include "AnimatedGameObject.hpp"

AnimatedGameObject::AnimatedGameObject(const std::string &path, sf::Time frameTime)
    : AGameObject(IGameObject::Type::ANIMATED, path, sf::IntRect(0, 0, 0, 0)),
    _currentAnimation(""), _currentFrame(0), _frameTime(frameTime), _elapsedTime(sf::Time::Zero)
{

}

AnimatedGameObject::AnimatedGameObject(const AnimatedGameObject &other)
    : AGameObject(other)
{
    _anims = other._anims;
    _currentAnimation = other._currentAnimation;
    _frameTime = other._frameTime;
    _elapsedTime = other._elapsedTime;
}

AnimatedGameObject &AnimatedGameObject::operator=(const AnimatedGameObject &other)
{
    if (this != &other) {
        _type = other._type;
        _t = other._t;
        _s = other._s;
        _anims = other._anims;
        _currentAnimation = other._currentAnimation;
        _frameTime = other._frameTime;
        _elapsedTime = other._elapsedTime;
    }
    return *this;
}

void AnimatedGameObject::setCurrentAnimation(const std::string &anim)
{
    _currentAnimation = anim;
}

void AnimatedGameObject::setCurrentFrame(std::size_t frame)
{
    _currentFrame = frame;
    _s.setTextureRect(std::get<0>(_anims[_currentAnimation])[_currentFrame]);
}

void AnimatedGameObject::update(sf::Time elapsed)
{
    _elapsedTime += elapsed;
    if (_elapsedTime.asSeconds() >= std::get<1>(_anims[_currentAnimation])) {
        if (_currentFrame + 1 < std::get<0>(_anims[_currentAnimation]).size())
            _currentFrame += 1;
        else {
            _currentFrame = 0;
        }
        _elapsedTime -= _frameTime;
        setCurrentFrame(_currentFrame);
    }
}

void AnimatedGameObject::addFrame(const Animation &anim, Frame frame)
{
    std::get<0>(_anims[anim]).push_back(frame);
}

void AnimatedGameObject::addFrames(const Animation &anim, Frames frames, float frameTime)
{
    _anims[anim] = std::make_tuple(frames, frameTime);
}