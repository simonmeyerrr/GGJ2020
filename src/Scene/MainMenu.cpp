/*
**
** GLOBAL GAME JAM
**
*/

#include "MainMenu.hpp"
#include "../Object/UIObject/Text.hpp"

MainMenu::MainMenu()
        : AScene(SCENE_MAIN_MENU)
{
    _uiObject[1] = std::make_shared<Text>(std::string("MAIN MENU"), _font.get(), sf::Vector2f(700, 50));
}

IScene::Event MainMenu::update()
{
    for (const auto &object: _uiObject)
        object.second->update();
    return Event{EVENT_NONE, SCENE_INTRO};
}

IScene::Event MainMenu::event(sf::RenderWindow &win, sf::Event &e)
{
    for (const auto &object: _uiObject)
        object.second->event(win, e);
    if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape)
        win.close();
    return Event{EVENT_NONE, SCENE_INTRO};
}

void MainMenu::display(sf::RenderWindow &win)
{
    for (const auto &object: _uiObject)
        object.second->draw(win);
}

void MainMenu::resume()
{}

