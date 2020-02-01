#include "Rect.hpp"

Rect::Rect(const sf::Color &color, const sf::Vector2f &size, const sf::Vector2f &pos)
        : _rect()
{
    _rect.setPosition(pos);
    _rect.setSize(size);
    _rect.setFillColor(color);
}

void Rect::update()
{
}

void Rect::event(sf::RenderWindow &window, sf::Event &)
{}

void Rect::draw(sf::RenderWindow &window) const
{
    window.draw(_rect);
}