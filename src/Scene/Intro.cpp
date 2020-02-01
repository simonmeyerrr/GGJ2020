/*
**
** GLOBAL GAME JAM
**
*/

#include "Intro.hpp"
#include "../Object/UIObject/Text.hpp"

Intro::Intro()
    : AScene(SCENE_INTRO)
{
    _uiObject.push_back(std::make_shared<Text>("INTRO", _font.get()));
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

