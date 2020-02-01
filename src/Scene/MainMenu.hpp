/*
**
** GLOBAL GAME JAM
**
*/

#ifndef MAIN_MENU_HPP
    #define MAIN_MENU_HPP

    #include "AScene.hpp"

class MainMenu : virtual public AScene {
public:
    // Constructors
    MainMenu(IScene::TypeScene);
    MainMenu(MainMenu &) = delete;
    ~MainMenu();
    MainMenu &operator=(const MainMenu &) = delete;

    // Methods
    void update();
    void event(sf::Event &, s_ptr<MainWindow> &);
    void display(s_ptr<MainWindow> &);
};

#endif /*MAIN_MENU_HPP*/