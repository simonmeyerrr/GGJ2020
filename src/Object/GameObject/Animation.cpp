/*
**
** GLOBAL GAME JAM
**
*/

#include "Animation.hpp"

Animation::Animation()
{

}

Animation::Animation(const Animation &other)
{

}

Animation &Animation::operator=(const Animation &other)
{

}

Animation::~Animation()
{

}

void Animation::setTexture(const sf::Texture *texture)
{
    _t = texture;
}

const sf::Texture *Animation::getTexture() const
{
    return _t;
}

const frames &Animation::getFrames() const
{
    return _frames;
}

const frame &Animation::getFrame(std::size_t index) const
{
    return _frames[index];
}

std::size_t Animation::getSize() const
{
    return _frames.size();
}

void Animation::addFrame(const frame &frame)
{
    _frames.push_back(frame);
}