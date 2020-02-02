/*
** EPITECH PROJECT, 2019
** GGJ2020
** File description:
** TippingText.cpp
*/

#include "TippingText.hpp"

TippingText::TippingText(const std::string &str, const sf::Font &font,
const sf::Vector2f &pos, const sf::Color &color, unsigned int size)
: Text("", font, pos, color, size), _str(str), _nbLetters(0), _state(CLEAN)
{
    _t.loadFromFile("./assets/textures/bubbleChat.png");
    _s.setTexture(_t);
    _s.setTextureRect(sf::IntRect(0, 0, 800, 200));
    _s.setPosition(400, 680);
    _text->setPosition(420, 690);
}

TippingText &TippingText::operator=(TippingText const &text)
{
    _text = text._text;
    _str = text._str;
    _nbLetters = text._nbLetters;
    _state = text._state;
    return *this;
}

void TippingText::setString(std::string const &str)
{
    _str = str;
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

void TippingText::start()
{
//    if (_s.getTextureRect().left < 11 * 800) {
//        std::cout << "test" << std::endl;
//        sf::IntRect rect = _s.getTextureRect();
//        rect.left += 800;
//        _s.setTextureRect(rect);
//    } else {
//        _state = WRITING;
//    }
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

void TippingText::drawAll(sf::RenderWindow &w) const {
    if (_state == WRITING || _state == ENDED) {
        w.draw(_s);
        draw(w);
    }
}

void TippingText::draw(sf::RenderWindow &w) const {
    w.draw(*_text);
}
