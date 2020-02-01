//
// Created by Jean-Gaël Choppe on 01/02/2020.
//

#include "Text.hpp"

Text::Text(const std::string &string, const sf::Font &font, unsigned int characterSize)
: _text(std::make_shared<sf::Text>(sf::String(string), font, characterSize)) {}

sf::Vector2f const &Text::getPosition() const {
    return _text->getPosition();
}

void Text::setPosition(sf::Vector2f &v) {
    _text->setPosition(v.x, v.y);
}

void Text::setScale(const sf::Vector2f &f) {
    _text->setScale(f);
}

sf::Vector2f const &Text::getScale() const {
    return _text->getScale();
}

void Text::setOrigin(const sf::Vector2f &f) {
    _text->setOrigin(f);
}

sf::Vector2f const &Text::getOrigin() const {
    return _text->getOrigin();
}

void Text::setString(std::string const &string) {
    _text->setString(sf::String(string));
}

std::string Text::getString() const {
    std::string string(_text->getString().begin(), _text->getString().end());
    return string;
}

void Text::setFont(sf::Font const &font) {
    _text->setFont(font);
}

sf::Font const *Text::getFont() const {
    return _text->getFont();
}

void Text::setSize(size_t size) {
    _text->setCharacterSize(size);
}

size_t Text::getSize() const {
    return _text->getCharacterSize();
}

void Text::setLineSpacing(float spacing) {
    _text->setLineSpacing(spacing);
}

float Text::getLineSpacing() const {
    return _text->getLineSpacing();
}

void Text::setLetterSpacing(float spacing) {
    _text->setLetterSpacing(spacing);
}

float Text::getLetterSpacing() const {
    return _text->getLetterSpacing();
}

void Text::draw(sf::RenderWindow window) const {
    window.draw(*_text);
}
