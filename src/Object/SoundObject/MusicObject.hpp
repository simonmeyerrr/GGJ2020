/*
** EPITECH PROJECT, 2019
** GGJ2020
** File description:
** MusicObject.hpp
*/

#ifndef GGJ2020_MUSICOBJECT_HPP
#define GGJ2020_MUSICOBJECT_HPP

#include "ISoundObject.hpp"

class MusicObject : ISoundObject {

public:
    MusicObject(const std::string &);
    MusicObject(const MusicObject &);
    MusicObject &operator=(const MusicObject &);

    ~MusicObject() override;

    void play() override;
    void pause() override;
    void stop() override;
    void setLoop(bool) override;
    void setVolume(const float) override;
    float getVolume() const override;
    const sf::SoundBuffer &getBuffer() const override = delete;
    const sf::Sound &getSound() const override = delete;
    const sf::Music &getMusic() const override;

    std::string _filename;
private:
    sf::Music _music;
};

#endif /* GGJ2020_MUSICOBJECT_HPP */
