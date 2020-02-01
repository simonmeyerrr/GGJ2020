//
// Created by Jean-Gaël Choppe on 01/02/2020.
//

#include "LevelOne.hpp"
#include "../Utils/Collision/Collision.hpp"

LevelOne::LevelOne() : AScene(SCENE_LEVEL1), _pos(sf::Vector2f(200, 700)) {
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
    _velocity = {0, 0};
    _erosion.setProgress(30);
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
    _erosion.update();
    return {EVENT_NONE, SCENE_INTRO};
}

IScene::Event LevelOne::event(sf::RenderWindow &w, sf::Event &e) {
    if (e.type == sf::Event::KeyPressed) {
        if (e.key.code == sf::Keyboard::Right)
            moveRight();
        if (e.key.code == sf::Keyboard::Left)
            moveLeft();
    }
    return {EVENT_NONE, SCENE_INTRO};
}

void LevelOne::display(sf::RenderWindow &w, sf::Shader *shader) {
    w.draw(_bg);
    w.draw(_rect);
    w.draw(_back);
    _erosion.display(w);
}

void LevelOne::resume() {

}

void LevelOne::moveRight() {
    std::cout << _bg.getPosition().x << " + " << _bg.getSize().x << std::endl;
    if ((int)_rect.getPosition().x < 1600 / 2 || _bg.getPosition().x + _bg.getSize().x <= 1600) {
        _pos.x += 10;
        _rect.setPosition(_pos);
    } else {
//        for (auto &object : _objectCritic) {
//            sf::Vector2f pos = object->getPosition();
//            object->setPosition(pos.x - 10, pos.y);
//        }
        sf::Vector2f pos = _back.getPosition();
        sf::Vector2f pos2 = _bg.getPosition();
        _back.setPosition(pos.x - 10, pos.y);
        _bg.setPosition(pos2.x - 10, pos2.y);
    }
}

void LevelOne::moveLeft() {
    if (_bg.getPosition().x >= 0 || (int)_rect.getPosition().x >= 1600 / 2) {
        _pos.x -= 10;
        _rect.setPosition(_pos);
    } else {
//        for (auto &object : _objectCritic) {
//            sf::Vector2f pos = object->getPosition();
//            object->setPosition(pos.x - 10, pos.y);
//        }
        sf::Vector2f pos = _back.getPosition();
        sf::Vector2f pos2 = _bg.getPosition();
        _back.setPosition(pos.x + 10, pos.y);
        _bg.setPosition(pos2.x + 10, pos2.y);
    }
}

void LevelOne::gravity() {
    if (_pos.y < 700) {
        _velocity.y += 7;
    }
    if (_velocity.y == 0) {
        _isJumping = false;
    } //else if ()
}