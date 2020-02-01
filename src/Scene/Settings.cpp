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

IScene::Event Settings::event(sf::RenderWindow &, sf::Event &)
{
    return Event{EVENT_NONE, SCENE_INTRO};
}

void Settings::display(sf::RenderWindow &)
{}

void Settings::resume()
{}