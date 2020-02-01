/*
**
** GLOBAL GAME JAM
**
*/

#ifndef ISCENE_HPP
    #define ISCENE_HPP

    #include <SFML/Graphics.hpp>
    #include "../Utils/Using.hpp"

class IScene {
public:
    virtual ~IScene() = default;
    enum TypeScene {
        SCENE_INTRO,
        SCENE_MAIN_MENU,
        SCENE_SETTINGS,
        SCENE_LEVEL1,
        SCENE_LEVEL2
    };

    enum TypeEvent {
        EVENT_NONE,
        EVENT_CLOSE_WINDOW,
        EVENT_POP_SCENE,
        EVENT_PUSH_SCENE,
    };

    struct Event {
        TypeEvent event;
        TypeScene scene;
    };

    virtual TypeScene getType() const = 0;
    virtual Event update() = 0;
    virtual Event event(sf::RenderWindow &, sf::Event &) = 0;
    virtual void display(sf::RenderWindow &, sf::Shader *) = 0;
    virtual void resume() = 0;
};

#endif /*ISCENE_HPP*/