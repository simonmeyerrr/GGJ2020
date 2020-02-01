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
    void display(sf::RenderWindow &, sf::Shader *) override;
    void resume() override;

private:
    unsigned int _updates;
};

#endif /*INTRO_HPP*/