/*
**
** GLOBAL GAME JAM
**
*/

#include "MainMenu.hpp"
#include "../Object/UIObject/Text.hpp"
#include "../Object/UIObject/Rect.hpp"

MainMenu::MainMenu()
        : AScene(SCENE_MAIN_MENU), _right(true), _walking(false), _escape(false)
{
    _uiObject[0] = std::make_shared<Text>("A: Settings, Z: LEVEL1, E: LEVEL2", _font.get(), sf::Vector2f{600, 800}, sf::Color::White);
    _uiObject[1] = std::make_shared<Rect>(sf::Color{0, 0, 0, 125});
    _uiObject[2] = std::make_shared<Text>("Appuyez sur Entrer pour quitter le jeu, sinon appuyez sur Echape", _font.get(), sf::Vector2f{550, 400}, sf::Color::White);
}

IScene::Event MainMenu::update()
{
    for (const auto &object: _uiObject)
        object.second->update();
    return Event{EVENT_NONE, SCENE_INTRO};
}

IScene::Event MainMenu::event(sf::RenderWindow &win, sf::Event &e)
{
    if (e.type == sf::Event::KeyPressed) {
        if (e.key.code == sf::Keyboard::Escape) {
            _escape = !_escape;
        } else if (_escape && e.key.code == sf::Keyboard::Enter) {
            win.close();
        } else if (!_walking && (e.key.code == sf::Keyboard::Right || e.key.code == sf::Keyboard::Left)) {
            _walking = true;
            _right = e.key.code == sf::Keyboard::Right;
        } else if (e.key.code == sf::Keyboard::A) {
            return Event{EVENT_PUSH_SCENE, SCENE_SETTINGS};
        } else if (e.key.code == sf::Keyboard::Z) {
            return Event{EVENT_PUSH_SCENE, SCENE_LEVEL1};
        } else if (e.key.code == sf::Keyboard::E) {
            return Event{EVENT_PUSH_SCENE, SCENE_LEVEL2};
        }
    }
    if (e.type == sf::Event::KeyReleased) {
        if (_walking && ((e.key.code == sf::Keyboard::Right && _right) || (e.key.code == sf::Keyboard::Left && !_right)))
            _walking = false;
    }
    return Event{EVENT_NONE, SCENE_INTRO};
}

void MainMenu::display(sf::RenderWindow &win, sf::Shader *shader)
{
    _uiObject[0]->draw(win);
    if (_escape) {
        _uiObject[1]->draw(win);
        _uiObject[2]->draw(win);
    }
}

void MainMenu::resume()
{}

