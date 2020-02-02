/*
**
** GLOBAL GAME JAM
**
*/

#include "MainMenu.hpp"
#include "../Object/UIObject/Text.hpp"
#include "../Object/UIObject/Rect.hpp"
#include "../Object/GameObject/StaticGameObject.hpp"
#include "../Object/UIObject/Fade.hpp"

MainMenu::MainMenu(Saves &save)
        : AScene(SCENE_MAIN_MENU, save), _right(true), _walking(false), _escape(false), _x(0), _erosion(), _anim(false), _in(false), _zoom(1.0), _scene(SCENE_MAIN_MENU)
{
    _uiObject[0] = std::make_shared<Text>("", _font.get(), sf::Vector2f{600, 800}, sf::Color::White);
    _uiObject[1] = std::make_shared<Rect>(sf::Color{0, 0, 0, 125});
    _uiObject[2] = std::make_shared<Text>("Appuyez sur Entrer pour quitter le jeu, sinon appuyez sur Echape", _font.get(), sf::Vector2f{550, 400}, sf::Color::White);
    _uiObject[3] = std::make_shared<Fade>();
    _gameObject[0] = std::make_shared<StaticGameObject>("./assets/textures/main_menu.png", sf::IntRect{0, 0, 8800, 900});
    _gameObject[1] = std::make_shared<StaticGameObject>("./assets/textures/tableau_soldat_flou.png", sf::IntRect{0, 0, 330, 500});
    _gameObject[2] = std::make_shared<StaticGameObject>("./assets/textures/tableau_ecole_flou.png", sf::IntRect{0, 0, 330, 500});
    _gameObject[3] = std::make_shared<StaticGameObject>("./assets/textures/tableau_maison_flou.png", sf::IntRect{0, 0, 330, 500});
    _gameObject[5] = std::make_shared<StaticGameObject>("./assets/textures/tableau_soldat.png", sf::IntRect{0, 0, 330, 500});
    _gameObject[6] = std::make_shared<StaticGameObject>("./assets/textures/tableau_ecole.png", sf::IntRect{0, 0, 330, 500});
    _gameObject[7] = std::make_shared<StaticGameObject>("./assets/textures/tableau_maison.png", sf::IntRect{0, 0, 330, 500});
    _gameObject[4] = std::make_shared<PlayerOld>();
    _gameObject[0]->setPosition({-1500, 0});
    _gameObject[1]->setPosition({1000, 150});
    _gameObject[2]->setPosition({2000, 150});
    _gameObject[3]->setPosition({3000, 150});
    _gameObject[4]->setPosition({500, 250});
    _gameObject[5]->setPosition({1000, 150});
    _gameObject[6]->setPosition({2000, 150});
    _gameObject[7]->setPosition({3000, 150});
    dynamic_cast<AnimatedGameObject &>(*_gameObject[4]).setCurrentAnimation("idleRight");
    _erosion.setProgress(30);
}

int MainMenu::inFrontOf() const
{
    for (int i = 1; i <= 3; ++i) {
        if (_x > (-1000 * i) + 575 && _x < (-1000 * i) + 775)
            return i;
    }
    return 0;
}

IScene::Event MainMenu::update()
{
    _uiObject[3]->update();
    if (_anim) {
        _zoom += _in ? -0.01 : 0.01;
        if (_in && _zoom <= 0.25)
            return Event{EVENT_PUSH_SCENE, _scene};
        else if (!_in && _zoom >= 1.0) {
            _zoom = 1.0;
            _anim = false;
        }
        return Event{EVENT_NONE, SCENE_INTRO};
    }
    if (_escape)
        return Event{EVENT_NONE, SCENE_INTRO};
    for (const auto &object: _gameObject)
        object.second->update();
    if (_walking) {
        if (_right && _x > -3500)
            _x -= 3;
        else if (!_right && _x < 500)
            _x += 3;
        _gameObject[0]->setPosition({static_cast<float>(_x - 1500), 0});
        _gameObject[1]->setPosition({static_cast<float>(_x + 1000), 150});
        _gameObject[2]->setPosition({static_cast<float>(_x + 2000), 150});
        _gameObject[3]->setPosition({static_cast<float>(_x + 3000), 150});
        _gameObject[5]->setPosition({static_cast<float>(_x + 1000), 150});
        _gameObject[6]->setPosition({static_cast<float>(_x + 2000), 150});
        _gameObject[7]->setPosition({static_cast<float>(_x + 3000), 150});
        auto front = inFrontOf();
        if (front)
            dynamic_cast<Text &>(*_uiObject[0]).setString("Fleche du haut pour entrer dans le souvenir");
        else
            dynamic_cast<Text &>(*_uiObject[0]).setString("");
    }
    _erosion.update();
    return Event{EVENT_NONE, SCENE_INTRO};
}

IScene::Event MainMenu::event(sf::RenderWindow &win, sf::Event &e)
{
    if (_escape) {
        if (e.type == sf::Event::KeyPressed && _escape && e.key.code == sf::Keyboard::Enter)
            win.close();
        else if (e.type == sf::Event::KeyPressed && _escape && e.key.code == sf::Keyboard::Escape)
            _escape = false;
        return Event{EVENT_NONE, SCENE_INTRO};
    }
    if (e.type == sf::Event::KeyPressed) {
        if (e.key.code == sf::Keyboard::Escape) {
            _escape = !_escape;
        } else if (_escape && e.key.code == sf::Keyboard::Enter) {
            win.close();
        } else if (!_walking && (e.key.code == sf::Keyboard::Right || e.key.code == sf::Keyboard::Left)) {
            _walking = true;
            _right = e.key.code == sf::Keyboard::Right;
            dynamic_cast<AnimatedGameObject &>(*_gameObject[4]).setCurrentAnimation(std::string("walk") + (_right ? "Right" : "Left"));
        } else if (e.key.code == sf::Keyboard::Up) {
            auto front = inFrontOf();
            if (front == 1 || front == 2) {
                _anim = true;
                _in = true;
                _zoom = 1.0;
                _scene = front == 1 ? SCENE_LEVEL1 : SCENE_LEVEL2;
                dynamic_cast<Fade &>(*_uiObject[3]).start(sf::Color::Black, 75, true);
            }
        }
    }
    if (e.type == sf::Event::KeyReleased) {
        if (_walking && ((e.key.code == sf::Keyboard::Right && _right) || (e.key.code == sf::Keyboard::Left && !_right))) {
            _walking = false;
            dynamic_cast<AnimatedGameObject &>(*_gameObject[4]).setCurrentAnimation(std::string("idle") + (_right ? "Right" : "Left"));
        }
    }
    return Event{EVENT_NONE, SCENE_INTRO};
}

void MainMenu::display(sf::RenderWindow &win, shaders_map &shaders)
{
    sf::Vector2f firstCenter = sf::Vector2f(_gameObject[1]->getSprite().getPosition().x + _gameObject[1]->getSprite().getLocalBounds().width / 2, 700);
    sf::Vector2f secondCenter = sf::Vector2f(_gameObject[2]->getSprite().getPosition().x + _gameObject[2]->getSprite().getLocalBounds().width / 2, 700);
    sf::Vector2f thirdCenter = sf::Vector2f(_gameObject[3]->getSprite().getPosition().x + _gameObject[3]->getSprite().getLocalBounds().width / 2, 700);

    shaders[TEST_SHADER].setUniform("first", firstCenter);
    shaders[TEST_SHADER].setUniform("second", secondCenter);
    shaders[TEST_SHADER].setUniform("third", thirdCenter);
    
    _uiObject[0]->draw(win);
    win.draw(_gameObject[0]->getSprite(), &shaders[TEST_SHADER]);
    win.draw(_gameObject[_save.level1 ? 5 : 1]->getSprite(), &shaders[TEST_SHADER]);
    win.draw(_gameObject[_save.level2 ? 6 : 2]->getSprite(), &shaders[TEST_SHADER]);
    win.draw(_gameObject[_save.level3 ? 7 : 3]->getSprite(), &shaders[TEST_SHADER]);
    if (!_anim) {
        win.draw(_gameObject[4]->getSprite(), &shaders[TEST_SHADER]);
        _uiObject[0]->draw(win);
    }
    _uiObject[3]->draw(win);
    if (_escape) {
        _uiObject[1]->draw(win);
        _uiObject[2]->draw(win);
    }
    _erosion.display(win);
    sf::View view = win.getDefaultView();
    view.zoom(_zoom);
    win.setView(view);
}

void MainMenu::resume()
{
    _zoom = 0.25;
    _in = false;
    _anim = true;
    dynamic_cast<Fade &>(*_uiObject[3]).start(sf::Color::Black, 75, false);
}

