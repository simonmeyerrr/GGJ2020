/*
**
** GLOBAL GAME JAM
**
*/

#ifndef INTRO_HPP
    #define INTRO_HPP
    #include "AScene.hpp"

class Intro : virtual public AScene {
public:
    Intro(IScene::TypeScene);
    Intro(Intro &) = delete;
    ~Intro();
    Intro &operator=(const Intro &) = delete;

    void update();
    void event(sf::Event &, s_ptr<MainWindow> &);
    void display(s_ptr<MainWindow> &);
};

#endif /*INTRO_HPP*/