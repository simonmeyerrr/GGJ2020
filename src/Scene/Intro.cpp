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
    _uiObject[1] = std::make_shared<Text>(std::string("INTRO"), _font.get(), sf::Vector2f(0, 0));
}

IScene::Event Intro::update()
{
    return Event{EVENT_NONE, SCENE_INTRO};
}

IScene::Event Intro::event(sf::RenderWindow &, sf::Event &)
{
    return Event{EVENT_NONE, SCENE_INTRO};
}

void Intro::display(sf::RenderWindow &win)
{
    for (const auto &object: _uiObject) {
        object.second->draw(win);
    }
}

void Intro::resume()
{}

