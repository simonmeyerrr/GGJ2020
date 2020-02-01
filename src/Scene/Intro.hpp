/*
**
** GLOBAL GAME JAM
**
*/

#ifndef INTRO_HPP
    #define INTRO_HPP
    #include "AScene.hpp"

class Intro : public AScene {
public:
    ~Intro() override = default;
    Intro();
    Intro(Intro &) = delete;
    Intro &operator=(const Intro &) = delete;

    Event update() override;
    Event event(sf::RenderWindow &, sf::Event &) override;
    void display(sf::RenderWindow &) override;
    void resume() override;
};

#endif /*INTRO_HPP*/