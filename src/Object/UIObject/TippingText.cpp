/*
** EPITECH PROJECT, 2019
** GGJ2020
** File description:
** TippingText.cpp
*/

#include "TippingText.hpp"

TippingText::TippingText(const sf::Font &font)
: Text("", font, {420, 690}, sf::Color::Black, 60), _str(""), _nbLetters(0), _state(CLEAN)
{
    _t.loadFromFile("./assets/textures/bulle.png");
    _s.setTexture(_t);
    _s.setPosition(400, 680);
}

void TippingText::update()
{
    if (_state != WRITING)
        return;
   std::string str = _str.substr(0, _nbLetters);
   _text->setString(str);
   ++_nbLetters;
   if (_nbLetters > _str.length())
       _state = ENDED;
}

void TippingText::start(const std::string &str)
{
    clean();
    _str = str;
    _state = WRITING;
}

TippingText::State TippingText::getState() const
{
    return _state;
}

void TippingText::clean()
{
    _state = CLEAN;
    _text->setString("");
    _nbLetters = 0;
}

void TippingText::draw(sf::RenderWindow &w) const {
    if (_state == WRITING || _state == ENDED) {
        w.draw(_s);
        w.draw(*_text);
    }
}
