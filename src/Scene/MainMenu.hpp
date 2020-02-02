/*
**
** GLOBAL GAME JAM
**
*/

#ifndef MAIN_MENU_HPP
    #define MAIN_MENU_HPP

    #include "AScene.hpp"
    #include "../Object/GameObject/Objects/PlayerOld.hpp"
    #include "../Utils/Erosion.hpp"

class MainMenu : public AScene {
public:
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

    Erosion _erosion;

    bool _anim;
    bool _in;
    float _zoom;
    IScene::TypeScene _scene;
};

#endif /*MAIN_MENU_HPP*/