/*
**
** GLOBAL GAME JAM
**
*/

#include "Settings.hpp"

Settings::Settings()
        : AScene(SCENE_SETTINGS)
{

}

IScene::Event Settings::update()
{
    return Event{EVENT_NONE, SCENE_INTRO};
}

IScene::Event Settings::event(sf::RenderWindow &, sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        return Event{EVENT_POP_SCENE, SCENE_INTRO};
    return Event{EVENT_NONE, SCENE_INTRO};
}

void Settings::display(sf::RenderWindow &, sf::Shader *)
{}

void Settings::resume()
{}