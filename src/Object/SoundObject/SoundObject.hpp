/*
** EPITECH PROJECT, 2019
** GGJ2020
** File description:
** SoundObject.hpp
*/

#ifndef GGJ2020_SOUNDOBJECT_HPP
#define GGJ2020_SOUNDOBJECT_HPP

#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include "../../Utils/Exception/MusicError.hpp"


class SoundObject {
public:
    SoundObject(const std::string &);
    SoundObject(const SoundObject &);
    SoundObject &operator=(const SoundObject &);

    ~SoundObject();

    void play();
    void pause();
    void stop();
    void setLoop(bool);
    void setVolume(const float);
    float getVolume() const;
    const sf::SoundBuffer &getBuffer() const;
    const sf::Sound &getSound() const;
    const sf::Sound &getMusic() const = delete;

private:
    sf::SoundBuffer _buffer;
    sf::Sound _sound;
};

#endif /* GGJ2020_SOUNDOBJECT_HPP */
