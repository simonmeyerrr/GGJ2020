//
// Created by Jean-Gaël Choppe on 01/02/2020.
//

#include "LevelOne.hpp"
#include "../Utils/Collision/Collision.hpp"
#include "../Object/GameObject/AnimatedGameObject.hpp"
#include "../Object/GameObject/StaticGameObject.hpp"
#include "../Object/GameObject/Objects/MilitaryCharacter.hpp"
#include "../Object/UIObject/Fade.hpp"
#include "../Object/UIObject/Text.hpp"
#include "../Object/UIObject/Rect.hpp"

LevelOne::LevelOne(Saves &save) : AScene(SCENE_LEVEL1, save), _pos(sf::Vector2f(200, 700)), _escape(false), _end(false) {
    _left = true;
    _angle = 0.0f;
    _isJumping = false;
    _right = false;
    _velocity = {0, 0};
    _walking = false;
    _sounds[FOREST] = std::make_shared<SoundObject>("./assets/sound/scene1/forest_fx.ogg");
    _sounds[JUMP_END] = std::make_shared<SoundObject>("./assets/sound/scene1/landing_forest.ogg");
    _sounds[STEPS] = std::make_shared<SoundObject>("./assets/sound/scene1/steps_woods.ogg");
    _sounds[WATER] = std::make_shared<SoundObject>("./assets/sound/scene1/water.ogg");
    _music = std::make_shared<MusicObject>("./assets/sound/scene1/military_theme.ogg");
    _music->setLoop(true);
    _music->setVolume(0);
    _music->play();
    _sounds[FOREST]->setLoop(true);
    _sounds[FOREST]->play();
    _gameObject[SKY] = std::make_shared<StaticGameObject>("./assets/textures/5ciel_fond.png", sf::IntRect(0, 0, 1600, 900));
    _gameObject[MONTAGNE] = std::make_shared<StaticGameObject>("./assets/textures/4montagne_fond.png", sf::IntRect(0, 0, 1600, 900));
    _gameObject[FOREST2_B] = std::make_shared<StaticGameObject>("./assets/textures/3arbre_arriere_fond.png", sf::IntRect(0, 0, 1600, 900));
    _gameObject[FOREST_B] = std::make_shared<StaticGameObject>("./assets/textures/2arbre_devant_fond.png", sf::IntRect(0, 0, 1600, 900));
    _gameObject[SOL] = std::make_shared<StaticGameObject>("./assets/textures/1sol_fond.png", sf::IntRect(0, 0, 1600, 900));
    _gameObject[PLATFORMS] = std::make_shared<StaticGameObject>("./assets/textures/lvl1_map.png", sf::IntRect(0, 0, 16000, 900));
    _gameObject[CHARACTER] = std::make_shared<MilitaryCharacter>();
    _pos = {0, 0};
    _gameObject[CHARACTER]->setPosition(_pos);
    _uiObject[0] = std::make_shared<Fade>();
    _uiObject[1] = std::make_shared<Rect>(sf::Color{0, 0, 0, 125});
    _uiObject[2] = std::make_shared<Text>("Appuyez sur Entrer pour quitter le jeu, sinon appuyez sur Echape", _font.get(), sf::Vector2f{550, 400}, sf::Color::White);
    dynamic_cast<Fade &>(*_uiObject[0]).start(sf::Color::Black, 200, false);
}

void LevelOne::rotateBlock(sf::RectangleShape &elem, float ratio, float maxAngle) {
    if (!_left) {
        _angle += ratio;
        if (_angle >= maxAngle)
            _left = true;
    } else {
        _angle -= ratio;
        if (_angle <= -maxAngle)
            _left = false;
    }
    elem.setRotation(_angle);
}

void LevelOne::fullRotate(sf::RectangleShape &elem, float ratio) {
    _angle += ratio;
    _angle = (float)((int)_angle % (int)360.0f);
    elem.setRotation(_angle);
}

IScene::Event LevelOne::update() {
    if (_music->getVolume() < 50)
        _music->setVolume(_music->getVolume() + 0.1);
    _uiObject[0]->update();
    if (_escape)
        return Event{EVENT_NONE, SCENE_INTRO};
    for (const auto &object: _gameObject)
        object.second->update();
    if (_walking) {
        if (_right)
            moveRight();
        else
            moveLeft();
    } else
        _velocity.x = 0;
    gravity();
    move();
    if (_end && dynamic_cast<Fade &>(*_uiObject[0]).isOver()) {
        _save.level1 = true;
        return {EVENT_POP_SCENE, SCENE_INTRO};
    }
    return {EVENT_NONE, SCENE_INTRO};
}

IScene::Event LevelOne::event(sf::RenderWindow &w, sf::Event &e) {
    if (_escape) {
        if (e.type == sf::Event::KeyPressed && _escape && e.key.code == sf::Keyboard::Enter)
            return Event{EVENT_POP_SCENE, SCENE_INTRO};
        else if (e.type == sf::Event::KeyPressed && _escape && e.key.code == sf::Keyboard::Escape)
            _escape = false;
        return Event{EVENT_NONE, SCENE_INTRO};
    }
    if (e.type == sf::Event::KeyPressed) {
        if (e.key.code == sf::Keyboard::Escape) {
            _escape = !_escape;
        } else if (!_walking && (e.key.code == sf::Keyboard::Right || e.key.code == sf::Keyboard::Left)) {
            _walking = true;
            _right = e.key.code == sf::Keyboard::Right;
            dynamic_cast<AnimatedGameObject &>(*_gameObject[CHARACTER]).setCurrentAnimation(std::string("walk") + (_right ? "Right" : "Left"));
        }
        if (e.key.code == sf::Keyboard::Space && !_isJumping) {
            _isJumping = true;
            _velocity.y -= 20;
        }
    }
    if (e.type == sf::Event::KeyReleased) {
        if (_walking && ((e.key.code == sf::Keyboard::Right && _right) || (e.key.code == sf::Keyboard::Left && !_right))) {
            _walking = false;
            dynamic_cast<AnimatedGameObject &>(*_gameObject[CHARACTER]).setCurrentAnimation(std::string("idle") + (_right ? "Right" : "Left"));
        }

    }
    return {EVENT_NONE, SCENE_INTRO};
}

void LevelOne::display(sf::RenderWindow &w, shaders_map  &shaders) {
    for (auto &elem : _gameObject) {
        w.draw(elem.second->getSprite());
    }
    if (_escape) {
        _uiObject[1]->draw(w);
        _uiObject[2]->draw(w);
    }
    _uiObject[0]->draw(w);
}

void LevelOne::resume() {

}

void LevelOne::moveRight() {

    if ((int) _gameObject[CHARACTER]->getPosition().x < 1600 / 2 ||
            _gameObject[PLATFORMS]->getPosition().x + _gameObject[PLATFORMS]->getSprite().getTextureRect().width <= 1600) {
        _velocity.x = 10;
    } else {
        _velocity.x = 0;
        sf::Vector2f pos2 = _gameObject[PLATFORMS]->getPosition();
        _gameObject[PLATFORMS]->setPosition(sf::Vector2f(pos2.x - 10, pos2.y));
        if (pos2.x < -10000 && !_end) {
            _end = true;
            dynamic_cast<Fade &>(*_uiObject[0]).start(sf::Color::Black, 200, true);
        }
    }
}

void LevelOne::moveLeft()
{
    if (_gameObject[PLATFORMS]->getPosition().x >= 0 ||
        (int) _gameObject[CHARACTER]->getPosition().x >= 1600 / 2) {
        _velocity.x = -10;
    } else {
        _velocity.x = 0;
        sf::Vector2f pos2 = _gameObject[PLATFORMS]->getPosition();
        _gameObject[PLATFORMS]->setPosition(sf::Vector2f(pos2.x + 10, pos2.y));
    }
}

void LevelOne::gravity() {
//    if (!pixelPerfectTest(*_gameObject[PLATFORMS], *_gameObject[CHARACTER])) {
//        _pos.x += _velocity.x;
//        _pos.y += _velocity.y;
//    _velocity.y += 1;
//    } else if (pixelPerfectTest(*_gameObject[PLATFORMS], *_gameObject[CHARACTER])) {
//        _velocity.y = 0;
//        //_pos.y = 700;
//        _isJumping = false;
//    }

}

void LevelOne::move()
{
//    if (_velocity.y > 0)
//        _velocity.y = collideDown(_gameObject[CHARACTER]->getMask(),_gameObject[PLATFORMS]->getMask(), _gameObject[CHARACTER]->getSprite(), _gameObject[PLATFORMS]->getSprite(), _velocity.y);
    _pos.y += _velocity.y;
    _pos.x += _velocity.x;
    _gameObject[CHARACTER]->setPosition(_pos);
}

void LevelOne::updateParallax() {

}
