/*
**
** GLOBAL GAME JAM
**
*/

#ifndef SETTINGS_HPP
    #define SETTINGS_HPP
    
    #include "AScene.hpp"

class Settings : virtual public AScene {
public:
    // Constructors
    Settings(IScene::TypeScene);
    Settings(Settings &) = delete;
    ~Settings();
    Settings &operator=(const Settings &) = delete;

    // Methods
    void update();
    void event(sf::Event &, s_ptr<MainWindow> &);
    void display(s_ptr<MainWindow> &);
};

#endif /*SETTINGS_HPP*/