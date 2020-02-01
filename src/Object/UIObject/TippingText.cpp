/*
** EPITECH PROJECT, 2019
** GGJ2020
** File description:
** TippingText.cpp
*/

#include "TippingText.hpp"

TippingText::TippingText(const std::string &str, const sf::Font &font,
    const sf::Vector2f &pos, const sf::Color &color, unsigned int size
)
    : Text("",font, pos, color, size), _str(str), _nbLetters(0), _state(CLEAN)
{

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
    if (_state != WRITTING)
        return;
   std::string str = _str.substr(0, _nbLetters);
   _text->setString(str);
   ++_nbLetters;
   if (_nbLetters > _str.length())
       _state = ENDED;
}

void TippingText::start()
{
    _state = WRITTING;
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
