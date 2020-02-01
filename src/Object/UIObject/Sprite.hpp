//
// Created by Jean-Gaël Choppe on 01/02/2020.
//

#ifndef GGJ2020_SPRITE_HPP
    #define GGJ2020_SPRITE_HPP


#include "AUIObject.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include "../../Utils/Using.hpp"

class Sprite : AUIObject {
public:
    // Constructors
    Sprite(const sf::Texture &, const sf::IntRect &);
    ~Sprite() override = default;

    // Setters & Getters
    const sf::Vector2f &getPosition() const override;
    void setPosition(sf::Vector2f &f) override;
    void setScale(const sf::Vector2f &f) override;
    const sf::Vector2f &getScale() const override;
    void setOrigin(const sf::Vector2f &f) override;
    const sf::Vector2f &getOrigin() const override;
    void setTexture(const sf::Texture &texture, bool resetRect) override;
    void setTextureRect(const sf::IntRect &rectangle) override;
    void setColor(const sf::Color &color) override;
    const sf::Color &getColor() override;
    sf::FloatRect getGlobalBounds() override;

    // Operators
    Sprite &operator=(Sprite const &);

    // Methods
    void draw(sf::RenderWindow &) const override;

private:
    s_ptr<sf::Sprite> _sprite;
};


#endif //GGJ2020_SPRITE_HPP
