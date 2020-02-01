//
// Created by Jean-Gaël Choppe on 01/02/2020.
//

#include "Sprite.hpp"

Sprite::Sprite(const sf::Texture &texture, const sf::IntRect &rect)
: _sprite(std::make_shared<sf::Sprite>(texture, rect)) {}

const sf::Vector2f &Sprite::getPosition() const {
    return _sprite->getPosition();
}

void Sprite::setPosition(sf::Vector2f &f) {
    _sprite->setPosition(f.x, f.y);
}

void Sprite::setScale(const sf::Vector2f &f) {
    _sprite->setScale(f.x, f.y);
}

const sf::Vector2f &Sprite::getScale() const {
    return _sprite->getScale();
}

void Sprite::setOrigin(const sf::Vector2f &f) {
    _sprite->setOrigin(f.x, f.y);
}

const sf::Vector2f &Sprite::getOrigin() const {
    return _sprite->getOrigin();
}

void Sprite::setTexture(const sf::Texture &texture, bool resetRect) {
    _sprite->setTexture(texture, resetRect);
}

void Sprite::setTextureRect(const sf::IntRect &rectangle) {
    _sprite->setTextureRect(rectangle);
}

const sf::IntRect &Sprite::getTextureRect() {
    return _sprite->getTextureRect();
}

void Sprite::setColor(const sf::Color &color) {
    _sprite->setColor(color);
}

const sf::Color &Sprite::getColor() {
    return _sprite->getColor();
}

sf::FloatRect Sprite::getGlobalBounds() {
    return sf::FloatRect();
}

void Sprite::draw(sf::RenderWindow window) const {
    window.draw(*_sprite);
}