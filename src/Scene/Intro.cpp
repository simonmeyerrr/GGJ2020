/*
**
** GLOBAL GAME JAM
**
*/

#include "Intro.hpp"

Intro::Intro()
    : AScene(SCENE_INTRO)
{

}

IScene::Event Intro::update()
{
    return Event{EVENT_NONE, SCENE_INTRO};
}

IScene::Event Intro::event(sf::RenderWindow &, sf::Event &)
{
    return Event{EVENT_NONE, SCENE_INTRO};
}

void Intro::display(sf::RenderWindow &)
{}

void Intro::resume()
{}

