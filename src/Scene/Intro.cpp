/*
**
** GLOBAL GAME JAM
**
*/

#include "Intro.hpp"
#include "../Object/UIObject/Text.hpp"
#include "../Object/UIObject/Fade.hpp"
#include "../Object/UIObject/Sprite.hpp"
#include "../Object/UIObject/Button.hpp"

Intro::Intro()
    : AScene(SCENE_INTRO), _text("Play", _font.get(), sf::Vector2f(0, 0)), _updates(0)
{
    _uiObject[1] = std::make_shared<Text>(std::string("INTRO"), _font.get(), sf::Vector2f(700, 50));
    _uiObject[2] = std::make_shared<Text>(std::string("0"), _font.get(), sf::Vector2f(700, 200));
    _uiObject[3] = std::make_shared<Fade>();
//    sf::Texture texture;
//    texture.loadFromFile("./nike.png");
    _texture.loadFromFile("./nike.png");
    //_text = Text("Play", _font.get(), sf::Vector2f(0, 0));
    _uiObject[4] = std::make_shared<Button>(_text,
    Sprite(_texture, sf::IntRect(100, 100, 100, 100), sf::Vector2f(0, 0)), []() {
                std::cout << "test" << std::endl;
            }, 100);

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

void Intro::display(sf::RenderWindow &win, sf::Shader *)
{
    for (const auto &object: _uiObject)
        object.second->draw(win);
}

void Intro::resume()
{
    _updates = 300;
}

