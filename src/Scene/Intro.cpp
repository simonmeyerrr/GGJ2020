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
    _gameObject[0] = std::make_shared<StaticGameObject>("./assets/textures/intro1.png", sf::IntRect{0, 0, 1600, 900});
    _gameObject[1] = std::make_shared<StaticGameObject>("./assets/textures/intro2.png", sf::IntRect{0, 0, 1600, 900});
    _gameObject[2] = std::make_shared<StaticGameObject>("./assets/textures/intro3.png", sf::IntRect{0, 0, 1600, 900});
    _uiObject[0] = std::make_shared<Fade>();
    _sounds[0] = std::make_shared<SoundObject>("./assets/sound/common/main_theme.ogg");
    _sounds[0]->setLoop(true);
    _sounds[0]->play();
    dynamic_cast<Fade &>(*(_uiObject[0])).start(sf::Color::Black, 100, false);
}

IScene::Event Intro::update()
{
    _uiObject[0]->update();
    ++_updates;
    if (_updates >= 900) {
        _sounds[0]->stop();
        return Event{EVENT_PUSH_SCENE, SCENE_MAIN_MENU};
    }
    if (_updates == 280 || _updates == 580 || _updates == 860)
        dynamic_cast<Fade &>(*(_uiObject[0])).start(sf::Color::Black, 40, true);
    if (_updates == 300 || _updates == 600 || _updates == 900)
        dynamic_cast<Fade &>(*(_uiObject[0])).start(sf::Color::Black, 30, false);
    return Event{EVENT_NONE, SCENE_INTRO};
}

IScene::Event Intro::event(sf::RenderWindow &win, sf::Event &event)
{
    return Event{EVENT_NONE, SCENE_INTRO};
}

void Intro::display(sf::RenderWindow &win, shaders_map &)
{
    if (_updates < 299)
        win.draw(_gameObject[0]->getSprite());
    else if (_updates > 299 && _updates < 600)
        win.draw(_gameObject[1]->getSprite());
    else if (_updates > 599 && _updates < 900)
        win.draw(_gameObject[2]->getSprite());
    _uiObject[0]->draw(win);
}

void Intro::resume()
{
    _updates = 800;
}

