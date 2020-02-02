/*
**
** GLOBAL GAME JAM
**
*/

#ifndef SETTINGS_HPP
    #define SETTINGS_HPP
    
    #include "AScene.hpp"

class Settings : public AScene {
public:
    ~Settings() override = default;
    Settings();
    Settings(Settings &) = delete;
    Settings &operator=(const Settings &) = delete;

    Event update() override;
    Event event(sf::RenderWindow &, sf::Event &) override;
    void display(sf::RenderWindow &, shaders_map &) override;
    void resume() override;
};

#endif /*SETTINGS_HPP*/