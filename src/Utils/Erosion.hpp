//
// Created by chaoticks on 01/02/2020.
//

#include <SFML/Config.hpp>
#include <SFML/Graphics.hpp>

#ifndef GGJ2020_EROSION_HPP
#define GGJ2020_EROSION_HPP

class Erosion {
public:
    Erosion();
    Erosion(Erosion &) = delete;
    ~Erosion() = default;
    Erosion &operator=(Erosion &) = delete;

    void setProgress(unsigned int);
    void update();
    void redraw();
    void display(sf::RenderWindow &);

private:
    sf::Image _image;
    sf::Texture _texture;
    sf::Sprite _sprite;

    unsigned int _update;
    unsigned int _progress;
};

#endif //GGJ2020_EROSION_HPP
