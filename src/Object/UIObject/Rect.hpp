#ifndef GGJ2020_RECT_HPP
#define GGJ2020_RECT_HPP


#include <SFML/Graphics/RectangleShape.hpp>
#include "IUIObject.hpp"

class Rect : public IUIObject {
public:
    Rect(const sf::Color &, const sf::Vector2f &size = {1600, 900}, const sf::Vector2f &pos = {0, 0});
    ~Rect() override = default;

    void update() override;
    void event(sf::RenderWindow &window, sf::Event &) override;
    void draw(sf::RenderWindow &window) const override;

private:
    sf::RectangleShape _rect;
};


#endif /* GGJ2020_RECT_HPP */
