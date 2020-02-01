#ifndef GGJ2020_FADE_HPP
#define GGJ2020_FADE_HPP

#include <SFML/Graphics/RectangleShape.hpp>
#include "IUIObject.hpp"

class Fade : public IUIObject {
public:
    Fade();
    ~Fade() override = default;

    bool isOver() const;
    void start(sf::Color, unsigned updates, bool in);

    void update() override;
    void event(sf::RenderWindow &window, sf::Event &) override;
    void draw(sf::RenderWindow &window) const override;

private:
    unsigned int _actual;
    unsigned int _goal;
    bool _in;
    sf::RectangleShape _rect;
};

#endif /* GGJ2020_FADE_HPP */
