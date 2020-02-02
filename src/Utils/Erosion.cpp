//
// Created by chaoticks on 01/02/2020.
//

#include <iostream>
#include "Erosion.hpp"

void redraw();

Erosion::Erosion()
    : _sprite(_texture), _update(0), _progress(0)
{
    _image.create(1600, 900, sf::Color::Transparent);
    _texture.create(1600, 900);
}

void Erosion::setProgress(unsigned int progress)
{
    _progress = progress;
}

void Erosion::update()
{
    _update += 1;

    if (_update >= 10) {
        _update = 0;
        redraw();
    }
}

void Erosion::redraw()
{
    if (_progress == 0)
        return;
    for (unsigned int y = 0; y < 900; ++y)
        for (unsigned int x = 0; x < 1600; ++x)
            _image.setPixel(x, y, sf::Color::Transparent);

    for (unsigned int y = 0; y < 900; ++y) {
        /*int width = _progress * 1600 / 100 + (random() % 20 - 10);
        if (width < 0)
            width = 0;
        for (unsigned int x = 0; x < (unsigned int) width; ++x) {
            std::cout << "lol" << std::endl;
            _image.setPixel(x, y, sf::Color::Black);
        }*/
    }

    _texture.update(_image);
    _sprite.setTexture(_texture);
}

void Erosion::display(sf::RenderWindow &win)
{
    win.draw(_sprite);
}
