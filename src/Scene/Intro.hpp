#ifndef INTRO_HPP
    #define INTRO_HPP
#include "AScene.hpp"

class Intro : virtual public AScene {
public:
    Intro(IScene::TypeScene unnamed);
    Intro(Intro &) = delete;
    ~Intro();
    Intro &operator=(const Intro &) = delete;

    void update() override;
    void event(std::shared_ptr<MainWindow> &) override ;
    void display() override;
private:

};

#endif /*INTRO_HPP*/