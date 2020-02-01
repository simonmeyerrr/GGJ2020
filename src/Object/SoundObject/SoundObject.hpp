/*
** EPITECH PROJECT, 2019
** GGJ2020
** File description:
** SoundObject.hpp
*/

#ifndef GGJ2020_SOUNDOBJECT_HPP
#define GGJ2020_SOUNDOBJECT_HPP

#include "ISoundObject.hpp"

class SoundObject : ISoundObject {
public:
    SoundObject(const std::string &);
    SoundObject(const SoundObject &);
    SoundObject &operator=(const SoundObject &);

    ~SoundObject() override;

    void play() override;
    void pause() override;
    void stop() override;
    void setLoop(bool) override;
    void setVolume(const float) override;
    float getVolume() const override;
    const sf::SoundBuffer &getBuffer() const override;
    const sf::Sound &getSound() const override;
    const sf::Sound &getMusic() const override = delete;

private:
    sf::SoundBuffer _buffer;
    sf::Sound _sound;
};

#endif /* GGJ2020_SOUNDOBJECT_HPP */
