/*
**
** GLOBAL GAME JAM
**
*/

#ifndef MAIN_MENU_HPP
    #define MAIN_MENU_HPP

    #include "AScene.hpp"
    #include "../Object/GameObject/Objects/PlayerOld.hpp"

class MainMenu : public AScene {
public:
    // Enums
    enum Sounds {
        MAIN
    };

    // Constructors
    ~MainMenu() override = default;
    MainMenu(Saves &save);
    MainMenu(MainMenu &) = delete;
    MainMenu &operator=(const MainMenu &) = delete;

    Event update() override;
    Event event(sf::RenderWindow &, sf::Event &) override;
    void display(sf::RenderWindow &, shaders_map &) override;
    void resume() override;

private:
    int inFrontOf() const;

    bool _right;
    bool _walking;
    bool _escape;
    int _x;

    bool _anim;
    bool _in;
    float _zoom;
    IScene::TypeScene _scene;

    bool _lights[3];
};

#endif /*MAIN_MENU_HPP*/