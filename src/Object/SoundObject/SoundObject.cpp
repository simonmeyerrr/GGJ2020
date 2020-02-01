/*
** EPITECH PROJECT, 2019
** GGJ2020
** File description:
** SoundObject.cpp
*/

#include "SoundObject.hpp"

SoundObject::SoundObject(const std::string &str)
    : _buffer(), _sound()
{
    if (!_buffer.loadFromFile(str))
        throw "erreur load file";
    _sound.setBuffer(_buffer);
}

SoundObject::SoundObject(const SoundObject &cpy)
{
    _buffer = cpy.getBuffer();
    _sound = cpy.getSound();

}

SoundObject &SoundObject::operator=(const SoundObject &cpy)
{
    return *this;
}

SoundObject::~SoundObject()
{
}

void SoundObject::play()
{
    _sound.play();
}

void SoundObject::pause()
{
    _sound.pause();
}

void SoundObject::stop()
{
    _sound.stop();
}

void SoundObject::setLoop(bool a)
{
    _sound.setLoop(a);
}

void SoundObject::setVolume(const float vol)
{
    _sound.setVolume(vol);
}

float SoundObject::getVolume() const
{
    return _sound.getVolume();
}

const sf::SoundBuffer &SoundObject::getBuffer() const
{
    return _buffer;
}

const sf::Sound &SoundObject::getSound() const
{
    return _sound;
}
