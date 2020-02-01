/*
** EPITECH PROJECT, 2019
** GGJ2020
** File description:
** ISoundObject.hpp
*/

#ifndef GGJ2020_ISOUNDOBJECT_HPP
#define GGJ2020_ISOUNDOBJECT_HPP

#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

class ISoundObject {

public:
    virtual ~ISoundObject() = 0;
    virtual void play() = 0;
    virtual void pause() = 0;
    virtual void stop() = 0;
    virtual void setLoop(bool) = 0;
    virtual void setVolume(const float) = 0;
    virtual float getVolume() const = 0;
    virtual const sf::SoundBuffer &getBuffer() const = 0;
    virtual const sf::Sound &getSound() const = 0;
    virtual const sf::Music &getMusic() const = 0;

};

#endif /* GGJ2020_ISOUNDOBJECT_HPP */
