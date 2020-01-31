#ifndef ISCENE_HPP
    #define ISCENE_HPP

#include <SFML/Window.hpp>
#include <memory>
#include "../Graphics/MainWindow.hpp"

class IScene {
protected:
    virtual ~IScene() = default;
    enum TypeScene {
        INTRO,
        MAIN_MENU,
        SCENE_MANAGER,
        SETTINGS
    };
    virtual TypeScene getType() const = 0;
    virtual void update() = 0;
    virtual void event(const  std::shared_ptr<MainWindow>) = 0;
    virtual void display() = 0;
};

#endif /*ISCENE_HPP*/