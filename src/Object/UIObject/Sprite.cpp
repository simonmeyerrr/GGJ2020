//
// Created by Jean-Gaël Choppe on 01/02/2020.
//

#include "Sprite.hpp"
#include ".././../Utils/Collision/Collision.hpp"

Sprite::Sprite(const std::string &filename, const sf::IntRect &rect, const sf::Vector2f &pos)
    : _texture(std::make_shared<sf::Texture>()), _sprite(std::make_shared<sf::Sprite>()), _mask(
    nullptr)
{
    _texture.get()->loadFromFile(filename);
    _sprite.get()->setTexture(*_texture);
    _sprite.get()->setPosition(pos);
    sf::Image image;
    image.loadFromFile(filename);
    _mask = std::make_shared<sf::Uint8 *>(createMask(*_texture, image));
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

sf::FloatRect Sprite::getGlobalBounds() const {
    return sf::FloatRect();
}

Sprite &Sprite::operator=(Sprite const &sprite) {
    _sprite = sprite._sprite;
    _texture = sprite._texture;
    _mask = sprite._mask;
    return *this;
}

void Sprite::draw(sf::RenderWindow &window) const {
    window.draw(*_sprite);
}

void Sprite::update() {}

void Sprite::event(sf::RenderWindow &window, sf::Event &) {}

sf::IntRect Sprite::getTextureRect() const {
    return _sprite->getTextureRect();
}

sf::Texture Sprite::getTexture() const
{
    return *_texture;
}

sf::Sprite Sprite::getSprite() const
{
    return *_sprite;
}

sf::Uint8 *Sprite::getMask() const
{
    return *_mask;
}
