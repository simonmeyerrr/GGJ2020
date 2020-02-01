//
// Created by Jean-Gaël Choppe on 01/02/2020.
//

#include "Sprite.hpp"

Sprite::Sprite(const sf::Texture &texture, const sf::IntRect &rect, const sf::Vector2f &pos)
: _sprite(std::make_shared<sf::Sprite>(texture, rect)) {
    _sprite->setPosition(pos);
}

const sf::Vector2f &Sprite::getPosition() const {
    return _sprite->getPosition();
}

void Sprite::setPosition(sf::Vector2f &f) {
    _sprite->setPosition(f.x, f.y);
}

void Sprite::setTextureRect(const sf::IntRect &rectangle) {
    _sprite->setTextureRect(rectangle);
}

sf::FloatRect Sprite::getGlobalBounds() {
    return sf::FloatRect();
}


Sprite &Sprite::operator=(Sprite const &sprite) {
    _sprite = sprite._sprite;
    return *this;
}

void Sprite::draw(sf::RenderWindow &window) const {
    window.draw(*_sprite);
}

void Sprite::update() {}

void Sprite::event(sf::RenderWindow &window, sf::Event &) {}
