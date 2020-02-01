/*
**
** GLOBAL GAME JAM
**
*/

#ifndef ISCENE_HPP
    #define ISCENE_HPP

    #include <SFML/Window.hpp>
    #include <memory>
    #include "../Graphics/MainWindow.hpp"
    #include "../Utils/Using.hpp"

class IScene {
public:
    virtual ~IScene() = default;
    enum TypeScene {
        INTRO,
        MAIN_MENU,
        SETTINGS
    };
    virtual TypeScene getType() const = 0;
    virtual void update() = 0;
    virtual void event(const s_ptr<MainWindow>) = 0;
    virtual void display() = 0;
};

#endif /*ISCENE_HPP*/