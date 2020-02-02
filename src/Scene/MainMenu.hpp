/*
**
** GLOBAL GAME JAM
**
*/

#ifndef MAIN_MENU_HPP
    #define MAIN_MENU_HPP

    #include "AScene.hpp"
    #include "../Object/GameObject/Objects/Character.hpp"
    #include "../Utils/Erosion.hpp"

class MainMenu : public AScene {
public:
    // Constructors
    ~MainMenu() override = default;
    MainMenu();
    MainMenu(MainMenu &) = delete;
    MainMenu &operator=(const MainMenu &) = delete;

    Event update() override;
    Event event(sf::RenderWindow &, sf::Event &) override;
    void display(sf::RenderWindow &, sf::Shader *) override;
    void resume() override;

private:
    int inFrontOf() const;

    bool _right;
    bool _walking;
    bool _escape;
    int _x;

    Erosion _erosion;
};

#endif /*MAIN_MENU_HPP*/