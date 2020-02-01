//
// Created by chaoticks on 01/02/2020.
//

#include <iostream>
#include "Erosion.hpp"

void redraw();

Erosion::Erosion()
    : _sprite(_texture), _update(0), _progress(0)
{
    _texture.create(1600, 900);
}

void Erosion::putPixel(unsigned int x, unsigned int y, sf::Color color)
{
    _pixels[(y * 1600 + x) * 4] = color.r;
    _pixels[(y * 1600 + x) * 4 + 1] = color.g;
    _pixels[(y * 1600 + x) * 4 + 2] = color.b;
    _pixels[(y * 1600 + x) * 4 + 3] = color.a;
}

void Erosion::clearBuffer()
{
    for (unsigned char & _pixel : _pixels)
        _pixel = 0;
}

void Erosion::setProgress(unsigned int progress)
{
    _progress = progress;
}

void Erosion::update()
{
    _update += 1;

    if (_update >= 10) {
        std::cout << "update" << std::endl;
        for (int i = 0; i < 1600 * 3; i += 4) {
            if (i % 1600 > 50)
                continue;
            printf("%3d, ", _pixels[i]);
            if (i % 1600 == 50)
                printf("\n");
        }

        _update = 0;
        redraw();
    }
}

void Erosion::redraw() {
    clearBuffer();
    if (_progress == 0)
        return;
    for (unsigned int y = 0; y < 900; ++y)
        for (unsigned int x = 0; x < _progress * 1600 / 100 + (random() % 20); ++x)
            putPixel(x, y, sf::Color::Black);
    _texture.update(_pixels);
}

void Erosion::display(sf::RenderWindow &win) {
    _texture.update(_pixels);
    _sprite.setTexture(_texture);
    win.draw(_sprite);
}
