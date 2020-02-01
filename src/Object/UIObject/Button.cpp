//
// Created by Jean-Gaël Choppe on 01/02/2020.
//

#include <SFML/Window/Event.hpp>
#include "Button.hpp"

#define MOUSE_IN_BUTTON ((float)e.mouseButton.x >= _sprite->getPosition().x && (float)e.mouseButton.x <= _sprite->getPosition().x + _sprite->getGlobalBounds().width && (float)e.mouseButton.y >= _sprite->getPosition().y && (float)e.mouseButton.y <= _sprite->getPosition().y + _sprite->getGlobalBounds().height)

Button::Button(const Text &text, const Sprite &sprite, Button::LambdaMethod &func, int rect)
: _function(func), _state(NONE), _rect(rect) {
    *_text = text;
    *_sprite = sprite;
}

Text &Button::getText() const {
    return *_text;
}

void Button::setText(const Text &text) {
    *_text = text;
}

Sprite &Button::getSprite() const {
    return *_sprite;
}

void Button::setSprite(const Sprite &sprite) {
    *_sprite = sprite;
}

void Button::draw(sf::RenderWindow &window) const {
    _text->draw(window);
    _sprite->draw(window);
}

void Button::cb() {
    _function();
}

void Button::update() {}

void Button::setLeftRect(int rect) {
    sf::FloatRect bounds = _sprite->getGlobalBounds();
    bounds.left = rect;
    _sprite->setTextureRect(sf::IntRect(bounds));
}

void Button::event(sf::RenderWindow &window, sf::Event &e) {
    if (e.MouseButtonPressed && MOUSE_IN_BUTTON) {
        if (_state == HOVER) {
            _state = CLICKED;
            setLeftRect(_rect * 2);
        }
    } else if (MOUSE_IN_BUTTON) {
        _state = HOVER;
        setLeftRect(_rect);
    }
    if (e.MouseButtonReleased && MOUSE_IN_BUTTON) {
        _state = NONE;
        setLeftRect(0);
        cb();
    } else if (e.MouseButtonReleased && !MOUSE_IN_BUTTON) {
        _state = NONE;
        setLeftRect(0);
    }
}