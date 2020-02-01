//
// Created by Jean-Gaël Choppe on 01/02/2020.
//

#include <SFML/Window/Event.hpp>
#include "Button.hpp"

Button::Button(const std::string &text, const sf::Font &font, sf::Vector2f tPos, unsigned int characterSize, const std::string &filename, sf::Vector2f sPos, sf::IntRect rect, Button::LambdaMethod func, int decade)
: _text(text, font, tPos, characterSize), _sprite(filename, rect, sPos), _function(func), _rect(decade), _state(NONE) {}

Text Button::getText() const {
    return _text;
}

void Button::setText(const Text &text) {
    _text = text;
}

Sprite Button::getSprite() const {
    return _sprite;
}

void Button::setSprite(const Sprite &sprite) {
    _sprite = sprite;
}

void Button::draw(sf::RenderWindow &window) const {
    _sprite.draw(window);
    _text.draw(window);
}

void Button::cb() {
    _function();
}

void Button::update() {
    if (_state == NONE) {
        setLeftRect(0);
    } else if (_state == HOVER) {
        setLeftRect(_rect);
    } else if (_state == CLICKED) {
        setLeftRect(_rect * 2);
    }
}

void Button::setLeftRect(int rect) {
    sf::IntRect bounds = _sprite.getTextureRect();
    bounds.left = rect;
    _sprite.setTextureRect(sf::IntRect(bounds));
}

bool Button::mouseInButton(sf::Event &e) const {
    return ((float)e.mouseButton.x >= _sprite.getPosition().x
    && (float)e.mouseButton.x <= _sprite.getPosition().x
    + _sprite.getTextureRect().width
    && (float)e.mouseButton.y >= _sprite.getPosition().y
    && (float)e.mouseButton.y <= _sprite.getPosition().y
    + _sprite.getTextureRect().height);
}

void Button::event(sf::RenderWindow &window, sf::Event &e) {
    if (e.type == sf::Event::MouseButtonPressed && mouseInButton(e)) {
        if (_state == HOVER) {
            _state = CLICKED;
        }
    } else if (e.type == sf::Event::MouseMoved && mouseInButtonMove(e) && _state != HOVER) {
        _state = HOVER;
    }
    if (e.type == sf::Event::MouseButtonReleased && mouseInButton(e) && _state == CLICKED) {
        std::cout << "WTF" << std::endl;
        _state = NONE;
        cb();
    } else if (e.type == sf::Event::MouseButtonReleased && !mouseInButton(e) && _state != CLICKED)
        _state = NONE;
    if (e.type == sf::Event::MouseMoved  && !mouseInButtonMove(e) && _state != CLICKED)
        _state = NONE;
}

bool Button::mouseInButtonMove(sf::Event &e) const {
    return ((float)e.mouseMove.x >= _sprite.getPosition().x
    && (float)e.mouseMove.x <= _sprite.getPosition().x
    + _sprite.getTextureRect().width
    && (float)e.mouseMove.y >= _sprite.getPosition().y
    && (float)e.mouseMove.y <= _sprite.getPosition().y
    + _sprite.getTextureRect().height);
}
