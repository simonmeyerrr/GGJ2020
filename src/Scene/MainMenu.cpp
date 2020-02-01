/*
**
** GLOBAL GAME JAM
**
*/

#include "MainMenu.hpp"
#include "../Object/UIObject/Text.hpp"
#include "../Object/UIObject/Rect.hpp"
#include "../Object/GameObject/StaticGameObject.hpp"

MainMenu::MainMenu()
        : AScene(SCENE_MAIN_MENU), _right(true), _walking(false), _escape(false), _x(0)
{
    _uiObject[0] = std::make_shared<Text>("", _font.get(), sf::Vector2f{600, 800}, sf::Color::White);
    _uiObject[1] = std::make_shared<Rect>(sf::Color{0, 0, 0, 125});
    _uiObject[2] = std::make_shared<Text>("Appuyez sur Entrer pour quitter le jeu, sinon appuyez sur Echape", _font.get(), sf::Vector2f{550, 400}, sf::Color::White);
    _gameObject[0] = std::make_shared<StaticGameObject>("./assets/textures/main_menu.png", sf::IntRect{0, 0, 8800, 900});
    _gameObject[1] = std::make_shared<StaticGameObject>("./assets/textures/tableau_militaire.png", sf::IntRect{0, 0, 330, 450});
    _gameObject[2] = std::make_shared<StaticGameObject>("./assets/textures/tableau_rentree.png", sf::IntRect{0, 0, 330, 450});
    _gameObject[3] = std::make_shared<StaticGameObject>("./assets/textures/tableau_maison.png", sf::IntRect{0, 0, 330, 450});
    _gameObject[1]->setPosition({2000, 200});
    _gameObject[2]->setPosition({4000, 200});
    _gameObject[3]->setPosition({6000, 200});
}

int MainMenu::inFrontOf() const
{
    for (int i = 1; i <= 3; ++i) {
        if (_x > (-2000 * i) + 575 && _x < (-2000 * i) + 775)
            return i;
    }
    return 0;
}

IScene::Event MainMenu::update()
{
    _player.update();
    if (_walking) {
        if (_right && _x > -8800 + 1600)
            _x -= 3;
        else if (!_right && _x < 0)
            _x += 3;
        _gameObject[0]->setPosition({static_cast<float>(_x), 0});
        _gameObject[1]->setPosition({static_cast<float>(_x + 2000), 200});
        _gameObject[2]->setPosition({static_cast<float>(_x + 4000), 200});
        _gameObject[3]->setPosition({static_cast<float>(_x + 6000), 200});
        auto front = inFrontOf();
        if (front)
            dynamic_cast<Text &>(*_uiObject[0]).setString("Fleche du haut pour entrer dans le souvenir");
        else
            dynamic_cast<Text &>(*_uiObject[0]).setString("");
    }
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
        } else if (e.key.code == sf::Keyboard::Up) {
            auto front = inFrontOf();
            switch (front) {
                case 1:
                    return Event{EVENT_PUSH_SCENE, SCENE_LEVEL1};
                case 2:
                    return Event{EVENT_PUSH_SCENE, SCENE_LEVEL2};
                case 3:
                    return Event{EVENT_PUSH_SCENE, SCENE_LEVEL2};
            }
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
    for (const auto &object: _gameObject)
        win.draw(object.second->getSprite());
    _uiObject[0]->draw(win);
    if (_escape) {
        _uiObject[1]->draw(win);
        _uiObject[2]->draw(win);
    }
    win.draw(_player.getSprite());
}

void MainMenu::resume()
{}

