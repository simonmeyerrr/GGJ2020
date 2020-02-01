/*
**
** GLOBAL GAME JAM
**
*/

#include "AnimatedGameObject.hpp"

AnimatedGameObject::AnimatedGameObject(sf::Time frameTime, bool paused, bool looped)
    : AGameObject(IGameObject::GameObjectType::ANIMATED, frameTime), _isPaused(paused), _isLooped(looped)
{

}

AnimatedGameObject::AnimatedGameObject(const AnimatedGameObject &other)
    : AGameObject(other)
{
    _isPaused = other._isPaused;
    _isLooped = other._isLooped;
}

AnimatedGameObject &AnimatedGameObject::operator=(const AnimatedGameObject &other)
{
    if (&other != this) {
        _type = other._type;
        _currentFrame = other._currentFrame;
        _t = other._t;
        _anim = other._anim;
        _frameTime = other._frameTime;
        _currentTime = other._currentTime;
        _isPaused = other._isPaused;
        _isLooped = other._isLooped;
    }
    return *this;
}

bool AnimatedGameObject::isPaused() const
{
    return _isPaused;
}

bool AnimatedGameObject::isLooped() const
{
    return _isLooped;
}

void AnimatedGameObject::setPaused(bool paused)
{
    _isPaused = paused;
}

void AnimatedGameObject::setLooped(bool looped)
{
    _isLooped = looped;
}

void AnimatedGameObject::update(sf::Time elapsedTime)
{
    if (!_isPaused && _anim) {
        _currentTime += elapsedTime;
        if (_currentTime >= _frameTime) {
            _currentTime = sf::microseconds(_currentTime.asMicroseconds() % _frameTime.asMicroseconds());
            if (_currentFrame + 1 < _anim->getSize())
                _currentFrame += 1;
            else {
                if (!_isLooped)
                    _isPaused = true;
                else
                    _currentFrame = 0;
            }
            setFrame(_currentFrame, false);
        }
    }
}

void AnimatedGameObject::play()
{
    _isPaused = false;
}

void AnimatedGameObject::play(const Animation &anim)
{
    if (getAnimation() != &anim)
        setAnimation(anim);
    play();
}

void AnimatedGameObject::pause()
{
    _isPaused = true;
}

void AnimatedGameObject::stop()
{
    _isPaused = true;
    _currentFrame = 0;
    setFrame(_currentFrame);
}