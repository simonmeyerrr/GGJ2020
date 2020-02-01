//
// Created by Jean-Gaël Choppe on 01/02/2020.
//

#include "Text.hpp"

Text::Text(const std::string &string, const sf::Font &font, const sf::Vector2f &pos, unsigned int characterSize)
: _text(std::make_shared<sf::Text>(sf::String(string), font, characterSize))
{
    _text->setPosition(pos);
}

sf::Vector2f const &Text::getPosition() const {
    return _text->getPosition();
}

void Text::setPosition(const sf::Vector2f &v) {
    _text->setPosition(v);
}

void Text::setString(std::string const &string) {
    _text->setString(sf::String(string));
}

std::string Text::getString() const {
    std::string string(_text->getString().begin(), _text->getString().end());
    return string;
}

void Text::update()
{}

void Text::event(sf::RenderWindow &window, sf::Event &)
{}

void Text::draw(sf::RenderWindow &window) const {
    window.draw(*_text);
}

Text &Text::operator=(Text const &text) {
    _text = text._text;
    return *this;
}
