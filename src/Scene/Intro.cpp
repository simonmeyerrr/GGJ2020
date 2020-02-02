/*
**
** GLOBAL GAME JAM
**
*/

#include "Intro.hpp"
#include "../Object/UIObject/Text.hpp"
#include "../Object/UIObject/Fade.hpp"
#include "../Object/GameObject/StaticGameObject.hpp"

Intro::Intro(Saves &save)
    : AScene(SCENE_INTRO, save),_updates(0)
{
    _gameObject[0] = std::make_shared<StaticGameObject>("./assets/textures/classroom.png", sf::IntRect{0, 0, 1600, 900});
    _gameObject[1] = std::make_shared<StaticGameObject>("./assets/textures/coridor.png", sf::IntRect{0, 0, 1600, 900});
    _gameObject[2] = std::make_shared<StaticGameObject>("./assets/textures/classroom.png", sf::IntRect{0, 0, 1600, 900});
    _gameObject[3] = std::make_shared<StaticGameObject>("./assets/textures/coridor.png", sf::IntRect{0, 0, 1600, 900});
    _uiObject[0] = std::make_shared<Fade>();
    dynamic_cast<Fade &>(*(_uiObject[0])).start(sf::Color::Black, 100, false);
}

IScene::Event Intro::update()
{
    _uiObject[0]->update();
    ++_updates;
    if (_updates >= 800)
        return Event{EVENT_PUSH_SCENE, SCENE_MAIN_MENU};
    if (_updates == 700)
        dynamic_cast<Fade &>(*(_uiObject[0])).start(sf::Color::Black, 100, true);
    return Event{EVENT_NONE, SCENE_INTRO};
}

IScene::Event Intro::event(sf::RenderWindow &win, sf::Event &event)
{
    return Event{EVENT_NONE, SCENE_INTRO};
}

void Intro::display(sf::RenderWindow &win, shaders_map &)
{
    if (_updates < 200)
        win.draw(_gameObject[0]->getSprite());
    else if (_updates < 400)
        win.draw(_gameObject[1]->getSprite());
    else if (_updates < 600)
        win.draw(_gameObject[2]->getSprite());
    else
        win.draw(_gameObject[3]->getSprite());
    _uiObject[0]->draw(win);
}

void Intro::resume()
{
    _updates = 800;
}

