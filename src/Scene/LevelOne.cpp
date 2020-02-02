//
// Created by Jean-Gaël Choppe on 01/02/2020.
//

#include "LevelOne.hpp"
#include "../Utils/Collision/Collision.hpp"
#include "../Object/GameObject/AnimatedGameObject.hpp"
#include "../Object/GameObject/StaticGameObject.hpp"
#include "../Object/GameObject/Objects/PlayerSchool.hpp"

LevelOne::LevelOne(Saves &save) : AScene(SCENE_LEVEL1, save), _pos(sf::Vector2f(200, 700)) {
    _rect.setFillColor(sf::Color::Red);
    _rect.setSize(sf::Vector2f(100, 100));
    _rect.setPosition(sf::Vector2f(200, 700));
    _rect.setOrigin(50, 50);
    _back.setFillColor(sf::Color::White);
    _back.setSize(sf::Vector2f(100, 200));
    _back.setPosition(sf::Vector2f(700, 700));
    _back.setOrigin(50, 100);
    _bg.setFillColor(sf::Color::Green);
    _bg.setSize(sf::Vector2f(2000, 700));
    _bg.setPosition(sf::Vector2f(0, 0));
    _left = true;
    _angle = 0.0f;
    _isJumping = false;
    _right = false;
    _velocity = {0, 0};
    _walking = false;
    _sounds[FOREST] = std::make_shared<SoundObject>("./assets/sound/scene1/forest_fx.ogg");
    std::cout << "fail" << std::endl;
    _sounds[JUMP_END] = std::make_shared<SoundObject>("./assets/sound/scene1/landing_forest.wav");
    _sounds[STEPS] = std::make_shared<SoundObject>("./assets/sound/scene1/steps_woods.wav");
    _sounds[WATER] = std::make_shared<SoundObject>("./assets/sound/scene1/water.wav");
    _music = std::make_shared<MusicObject>("./assets/sound/scene1/military_theme.wav");
    _music->setLoop(true);
    _music->play();
    _sounds[FOREST]->setLoop(true);
    _sounds[FOREST]->play();
//     _gameObject[BACKGROUND] = std::make_shared<AnimatedGameObject>("./assets/textures/lvl1_map.png");
    _gameObject[BACKGROUND] = std::make_shared<StaticGameObject>("./assets/textures/lvl1_map.png", sf::IntRect(0, 0, 16000, 900));
    _gameObject[CHARACTER] = std::make_shared<PlayerSchool>();
    _pos = {0, 0};
    _gameObject[CHARACTER]->setPosition(_pos);
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
//    rotateBlock(_rect, 2.0f, 30.0f);
//    fullRotate(_rect, -3.0f);
    if (_walking) {
        if (_right)
            moveRight();
        else
            moveLeft();
    }
    gravity();
    return {EVENT_NONE, SCENE_INTRO};
}

IScene::Event LevelOne::event(sf::RenderWindow &w, sf::Event &e) {
    if (e.type == sf::Event::KeyPressed) {
        if (!_walking && (e.key.code == sf::Keyboard::Right ||
        e.key.code == sf::Keyboard::Left)) {
            _walking = true;
            _right = e.key.code == sf::Keyboard::Right;
        }
        if (e.key.code == sf::Keyboard::Space && !_isJumping) {
            _isJumping = true;
            _velocity.y -= 20;
        }
    }
    if (e.type == sf::Event::KeyReleased) {
        if (_walking && ((e.key.code == sf::Keyboard::Right && _right) || (e.key.code == sf::Keyboard::Left && !_right)))
            _walking = false;
    }
    return {EVENT_NONE, SCENE_INTRO};
}

void LevelOne::display(sf::RenderWindow &w, shaders_map  &shaders) {
    w.draw(_bg);
    w.draw(_rect);
    w.draw(_back);
    for (auto &elem : _gameObject) {
        w.draw(elem.second->getSprite());
    }
}

void LevelOne::resume() {

}

void LevelOne::moveRight() {

    collisionDirection_t collision = pixelPerfectTest(*_gameObject[CHARACTER], *_gameObject[BACKGROUND]);

    if (collision.right)
        return;
    if ((int) _gameObject[CHARACTER]->getPosition().x < 1600 / 2 ||
            _gameObject[BACKGROUND]->getPosition().x + _gameObject[BACKGROUND]->getSprite().getTextureRect().width <= 1600) {
        _pos.x += 10;
    } else {
//    for (auto &object : _objectCritic) {
//        sf::Vector2f pos = object->getPosition();
//        object->setPosition(pos.x - 10, pos.y);
//    }
        sf::Vector2f pos = _back.getPosition();
        sf::Vector2f pos2 = _gameObject[BACKGROUND]->getPosition();
        _back.setPosition(pos.x - 10, pos.y);
        _gameObject[BACKGROUND]->setPosition(sf::Vector2f(pos2.x - 10, pos2.y));
    }
}

void LevelOne::moveLeft()
{
    collisionDirection_t collision = pixelPerfectTest(*_gameObject[CHARACTER], *_gameObject[BACKGROUND]);

    if (collision.left)
        return;
    if (_gameObject[BACKGROUND]->getPosition().x >= 0 ||
        (int) _gameObject[CHARACTER]->getPosition().x >= 1600 / 2) {
        _pos.x -= 10;
    } else {
//        for (auto &object : _objectCritic) {
//            sf::Vector2f pos = object->getPosition();
//            object->setPosition(pos.x - 10, pos.y);
//        }
        sf::Vector2f pos = _back.getPosition();
        sf::Vector2f pos2 = _gameObject[BACKGROUND]->getPosition();
        _back.setPosition(pos.x + 10, pos.y);
        _gameObject[BACKGROUND]->setPosition(sf::Vector2f(pos2.x + 10, pos2.y));
    }
}

void LevelOne::gravity() {
    collisionDirection_t collision = pixelPerfectTest(*_gameObject[CHARACTER], *_gameObject[BACKGROUND]);

    std::cout << "collision:\nup: " << collision.up << std::endl << "down: " << collision.down << std::endl << "left: " << collision.left << std::endl << "right: " << collision.right << std::endl;
    if (collision.down) {
        if (_velocity.y > 0) {
            _velocity.y = 0;
            if (_isJumping)
                _isJumping = false;
        }
    } else {
        _velocity.y += 1;
    }
    //    if (!pixelPerfectTest(*_gameObject[BACKGROUND], *_gameObject[CHARACTER])) {
//        _pos.x += _velocity.x;
//        _pos.y += _velocity.y;
//        _velocity.y += 1;
//    } else if (pixelPerfectTest(*_gameObject[BACKGROUND], *_gameObject[CHARACTER])) {
//        _velocity.y = 0;
//        //_pos.y = 700;
//        _isJumping = false;
//    }
    //        _pos.x += _velocity.x;
    _pos.y += _velocity.y;
    _pos.x += _velocity.x;
    _gameObject[CHARACTER]->setPosition(_pos);
}