/*
**
** GLOBAL GAME JAM
**
*/

#ifndef CORRUPTION_HPP
    #define CORRUPTION_HPP

    #include <SFML/Graphics/Image.hpp>
    #include <SFML/Graphics/Texture.hpp>
    #include <SFML/Graphics/Sprite.hpp>
    #include <SFML/Graphics/RenderWindow.hpp>

class Corruption {
public:
    // Constructors
    Corruption(std::size_t = 1);
    Corruption(const Corruption &) = delete;
    Corruption &operator=(const Corruption &) = delete;
    ~Corruption() = default;

    // Methods
    void update();
    void display(sf::RenderWindow &);

private:
    // Methods
    void clear(sf::Image &);
    void fill(sf::Image &);
    void randBck(sf::Image &);
    void apply(sf::Image &, sf::Texture &, sf::Sprite &);

    // Variables
    sf::Image _i;
    sf::Image _iBck;
    sf::Texture _t;
    sf::Texture _tBck;
    sf::Sprite _s;
    sf::Sprite _sBck;
    std::size_t _width;
    std::size_t _height;
    std::size_t _elapsed;
    std::size_t _move;
    std::size_t _frameTime;
    std::size_t _moveTime;
};

#endif /* CORRUPTION_HPP */