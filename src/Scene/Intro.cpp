/*
**
** GLOBAL GAME JAM
**
*/

#include "Intro.hpp"
#include "../Object/UIObject/Text.hpp"
#include "../Object/UIObject/Fade.hpp"

Intro::Intro()
    : AScene(SCENE_INTRO), _updates(0)
{
    _uiObject[1] = std::make_shared<Text>(std::string("INTRO"), _font.get(), sf::Vector2f(700, 50));
    _uiObject[2] = std::make_shared<Text>(std::string("0"), _font.get(), sf::Vector2f(700, 200));
    _uiObject[3] = std::make_shared<Fade>();

    dynamic_cast<Fade &>(*(_uiObject[3])).start(sf::Color::Black, 120, false);
}

IScene::Event Intro::update()
{
    for (const auto &object: _uiObject)
        object.second->update();
    ++_updates;
    if (_updates >= 300)
        return Event{EVENT_PUSH_SCENE, SCENE_MAIN_MENU};
    if (_updates % 30 == 0)
        dynamic_cast<Text &>(*(_uiObject[2])).setString(std::to_string(_updates / 30));
    return Event{EVENT_NONE, SCENE_INTRO};
}

IScene::Event Intro::event(sf::RenderWindow &win, sf::Event &event)
{
    for (const auto &object: _uiObject)
        object.second->event(win, event);
    return Event{EVENT_NONE, SCENE_INTRO};
}

void Intro::display(sf::RenderWindow &win)
{
    for (const auto &object: _uiObject)
        object.second->draw(win);
}

void Intro::resume()
{
    _updates = 300;
}

