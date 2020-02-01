//
// Created by Jean-Gaël Choppe on 01/02/2020.
//

#include "Button.hpp"

Button::Button(const Text &text, const Sprite &sprite, Button::LambdaMethod &func)
: _function(func), _state(NONE) {
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
