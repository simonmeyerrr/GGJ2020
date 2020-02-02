/*
**
** GLOBAL GAME JAM
**
*/

#include <stdlib.h>
#include <time.h>
#include "Corruption.hpp"

Corruption::Corruption(std::size_t moveTime)
    : _width(30), _height(900), _elapsed(0), _move(0),
    _frameTime(3), _moveTime(moveTime)
{
    srand(time(NULL));
    _i.create(_width, _height, sf::Color::Black);
    _iBck.create(1600, 900, sf::Color::Black);
    clear(_i);
    fill(_i);
    randBck(_iBck);
    apply(_i, _t, _s);
    apply(_iBck, _tBck, _sBck);
    _sBck.setPosition(-1600, 0);
}

void Corruption::clear(sf::Image &img)
{
    for (std::size_t i = 0; i < _width; ++i)
        for (std::size_t j = 0; j < _height; ++j)
            img.setPixel(i, j, sf::Color::Transparent);
}

void Corruption::randBck(sf::Image &img)
{
    std::size_t gray = 0;
    for (std::size_t i = 0; i < 1600; ++i)
        for (std::size_t j = 0; j < 900; ++j) {
            gray = rand() % 3;
            if (gray == 0)
                img.setPixel(i, j, sf::Color(44, 44, 44, 180));
            if (gray == 1)
                img.setPixel(i, j, sf::Color(56, 56, 56, 180));
            if (gray == 2)
                img.setPixel(i, j, sf::Color(32, 32, 32, 180));
        }
}

void Corruption::fill(sf::Image &img)
{
    std::size_t gray = 0;
    std::size_t line = 0;
    for (std::size_t j = 0; j < _height; ++j) {
        if (rand() % 2 == 0) {
            if (line < _width)
                line += 1;
        } else {
            if (line > 0)
                line -= 1;
        }
        for (std::size_t i = 0; i < line; ++i) {
            gray = rand() % 3;
            if (gray == 0)
                img.setPixel(i, j, sf::Color(44, 44, 44, 180));
            if (gray == 1)
                img.setPixel(i, j, sf::Color(56, 56, 56, 180));
            if (gray == 2)
                img.setPixel(i, j, sf::Color(32, 32, 32, 180));
        }
        img.setPixel(line, j, sf::Color(120, 120, 120));
    }
}

void Corruption::apply(sf::Image &i, sf::Texture &t, sf::Sprite &s)
{
    t.loadFromImage(i);
    s.setTexture(t);
}

void Corruption::update()
{
    _elapsed += 1;
    _move += 1;
    if (_elapsed >= _frameTime) {
        clear(_i);
        fill(_i);
        randBck(_iBck);
        apply(_iBck, _tBck, _sBck);
        apply(_i, _t, _s);
        if (_move >= _moveTime) {
            _s.setPosition(_s.getPosition().x + 1, _s.getPosition().y);
            _sBck.setPosition(_sBck.getPosition().x + 1, _sBck.getPosition().y);
        }
        _elapsed -= _frameTime;
    }
    if (_move >= _moveTime) {
         _s.setPosition(_s.getPosition().x + 1, _s.getPosition().y);
        _sBck.setPosition(_sBck.getPosition().x + 1, _sBck.getPosition().y);
        _move -= _moveTime;
    }
}

void Corruption::display(sf::RenderWindow &win)
{
    win.draw(_s);
    win.draw(_sBck);
}