/*
**
** GLOBAL GAME JAM
**
*/

#ifndef MAIN_MENU_HPP
    #define MAIN_MENU_HPP

    #include "AScene.hpp"

class MainMenu : public AScene {
public:
    // Constructors
    ~MainMenu() override = default;
    MainMenu();
    MainMenu(MainMenu &) = delete;
    MainMenu &operator=(const MainMenu &) = delete;

    Event update() override;
    Event event(sf::RenderWindow &, sf::Event &) override;
    void display(sf::RenderWindow &) override;
    void resume() override;
};

#endif /*MAIN_MENU_HPP*/