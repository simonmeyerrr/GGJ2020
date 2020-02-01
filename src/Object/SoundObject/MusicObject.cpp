/*
** EPITECH PROJECT, 2019
** GGJ2020
** File description:
** MusicObject.cpp
*/

#include "MusicObject.hpp"

MusicObject::MusicObject(const std::string &str)
    : _filename(str), _music()
{
    if (!_music.openFromFile(_filename))
        throw "error load from file";
}

MusicObject::MusicObject(const MusicObject &cpy)
    : _music()
{
    _filename = cpy._filename;
    _music.openFromFile(_filename);
}

MusicObject &MusicObject::operator=(const MusicObject &cpy)
{
    _filename = cpy._filename;
    _music.openFromFile(_filename);
    return *this;
}

MusicObject::~MusicObject()
{
}

void MusicObject::play()
{
    _music.play();
}

void MusicObject::pause()
{
    _music.pause();
}

void MusicObject::stop()
{
    _music.stop();
}

void MusicObject::setLoop(bool a)
{
    _music.setLoop(a);
}

void MusicObject::setVolume(const float vol)
{
    _music.setVolume(vol);
}

float MusicObject::getVolume() const
{
    return _music.getVolume();
}

const sf::Music &MusicObject::getMusic() const
{
    return _music;
}

