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

void Button::update() {}

void Button::setLeftRect(int rect) {
    sf::FloatRect bounds = _sprite.getGlobalBounds();
    bounds.left = rect;
    _sprite.setTextureRect(sf::IntRect(bounds));
}

bool Button::mouseInButton(sf::Event &e) const {
    std::cout << "Pressed:" << std::endl;
    std::cout << e.mouseButton.x << " >= " << _sprite.getPosition().x << std::endl;
    std::cout << e.mouseButton.x << " <= " << (_sprite.getPosition().x + _sprite.getTextureRect().width) << std::endl;
    std::cout << e.mouseButton.y << " >= " << _sprite.getPosition().y << std::endl;
    std::cout << e.mouseButton.y << " >= " << (_sprite.getPosition().y + _sprite.getTextureRect().height) << std::endl;
    return ((float)e.mouseButton.x >= _sprite.getPosition().x
    && (float)e.mouseButton.x <= _sprite.getPosition().x
    + _sprite.getTextureRect().width
    && (float)e.mouseButton.y >= _sprite.getPosition().y
    && (float)e.mouseButton.y <= _sprite.getPosition().y
    + _sprite.getTextureRect().height);
}

void Button::event(sf::RenderWindow &window, sf::Event &e) {
    if (e.type == sf::Event::MouseButtonPressed && mouseInButton(e)) {
        std::cout << "MouseButtonPressed & mouseInButton" << std::endl;
        if (_state == HOVER) {
            _state = CLICKED;
            setLeftRect(_rect * 2);
        }
    } else if (mouseInButtonMove(e)) {
        std::cout << "HOVER" << std::endl;
        _state = HOVER;
        setLeftRect(_rect);
    }
    if (e.type == sf::Event::MouseButtonReleased && mouseInButtonMove(e)) {
        std::cout << "WTF" << std::endl;
        _state = NONE;
        setLeftRect(0);
        cb();
    } else if (e.type == sf::Event::MouseButtonReleased && !mouseInButtonMove(e)) {
        std::cout << "NONE" << std::endl;
        _state = NONE;
        setLeftRect(0);
    }
}

bool Button::mouseInButtonMove(sf::Event &e) const {
    std::cout << "Move:" << std::endl;
    std::cout << e.mouseMove.x << " >= " << _sprite.getPosition().x << std::endl;
    std::cout << e.mouseMove.x << " <= " << (_sprite.getPosition().x + _sprite.getTextureRect().width) << std::endl;
    std::cout << e.mouseMove.y << " >= " << _sprite.getPosition().y << std::endl;
    std::cout << e.mouseMove.y << " >= " << (_sprite.getPosition().y + _sprite.getTextureRect().height) << std::endl;
    return ((float)e.mouseMove.x >= _sprite.getPosition().x
    && (float)e.mouseMove.x <= _sprite.getPosition().x
    + _sprite.getTextureRect().width
    && (float)e.mouseMove.y >= _sprite.getPosition().y
    && (float)e.mouseMove.y <= _sprite.getPosition().y
    + _sprite.getTextureRect().height);
}
