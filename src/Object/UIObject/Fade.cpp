#include "Fade.hpp"

Fade::Fade()
    : _actual(0), _goal(0), _in(false), _rect()
{
    _rect.setPosition(0, 0);
    _rect.setSize({1600, 900});
}

bool Fade::isOver() const
{
    return _actual >= _goal;
}

void Fade::start(sf::Color color, unsigned updates, bool in)
{
    _rect.setFillColor(color);
    _actual = 0;
    _goal = updates;
    _in = in;
}

void Fade::update()
{
    if (_actual >= _goal)
        return;

    auto color = _rect.getFillColor();
    ++_actual;
    color.a = _in ? static_cast<float>(_actual) / static_cast<float>(_goal) * 256 : 256 - static_cast<float>(_actual) / static_cast<float>(_goal) * 256;
    _rect.setFillColor(color);
}

void Fade::event(sf::RenderWindow &window, sf::Event &)
{}

void Fade::draw(sf::RenderWindow &window) const
{
    if (_actual >= _goal)
        return;
    window.draw(_rect);
}