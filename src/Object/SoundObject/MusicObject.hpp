/*
** EPITECH PROJECT, 2019
** GGJ2020
** File description:
** MusicObject.hpp
*/

#ifndef GGJ2020_MUSICOBJECT_HPP
#define GGJ2020_MUSICOBJECT_HPP

#include <SFML/Audio/Music.hpp>

class MusicObject {

public:
    MusicObject(const std::string &);
    MusicObject(const MusicObject &);
    MusicObject &operator=(const MusicObject &);

    ~MusicObject();

    void play();
    void pause();
    void stop();
    void setLoop(bool);
    void setVolume(const float);
    float getVolume() const;
    const sf::Music &getMusic() const;

    std::string _filename;
private:
    sf::Music _music;

};

#endif /* GGJ2020_MUSICOBJECT_HPP */
