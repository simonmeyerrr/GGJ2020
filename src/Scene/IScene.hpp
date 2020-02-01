/*
**
** GLOBAL GAME JAM
**
*/

#ifndef ISCENE_HPP
    #define ISCENE_HPP

    #include <SFML/Window.hpp>
    #include <SFML/Window/Event.hpp>
    #include <memory>
    #include "../Graphics/MainWindow.hpp"
    #include "../Utils/Using.hpp"

class IScene {
public:
    // Enum
    enum TypeScene {
        INTRO,
        MAIN_MENU,
        SETTINGS
    };
    
    // Constructors
    virtual ~IScene() = default;

    // Setters & Getters
    virtual TypeScene getType() const = 0;

    // Methods
    virtual void update() = 0;
    virtual void event(sf::Event &, s_ptr<MainWindow> &) = 0;
    virtual void display(s_ptr<MainWindow> &) = 0;
};

#endif /*ISCENE_HPP*/