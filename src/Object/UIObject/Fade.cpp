#include "Fade.hpp"

Fade::Fade()
    : _actual(0), _goal(0), _in(false), _rect()
{
    _rect.setFillColor(sf::Color::Transparent);
    _rect.setPosition(0, 0);
    _rect.setSize({1600, 900});
}

bool Fade::isOver() const
{
    return _actual >= _goal;
}

void Fade::start(sf::Color color, unsigned updates, bool in)
{
    _actual = 0;
    _goal = updates;
    _in = in;
    color.a = _in ? 0 : 256;
    _rect.setFillColor(color);
}

void Fade::update()
{
    if (_actual >= _goal - 1)
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
    window.draw(_rect);
}