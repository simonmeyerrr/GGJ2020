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
    Sprite();
    ~Sprite();

    const sf::Vector2f &getPosition() const override;
    void setPosition(sf::Vector2f &f) override;
    void setScale(const sf::Vector2f &f) override;
    const sf::Vector2f &getScale() const override;
    void setOrigin(const sf::Vector2f &f) override;
    const sf::Vector2f &getOrigin() const override;
    void setTexture(const sf::Texture &texture, bool resetRect) override;
    sf::Texture &getTexture() const override;
    void setTextureRect(const sf::IntRect &rectangle) override;
    const sf::IntRect &getTextureRect() override;
    void setColor(const sf::Color &color) override;
    const sf::Color &getColor() override;
    sf::FloatRect getGlobalBounds() override;

    void draw() const override;

private:
    s_ptr<sf::Sprite> _sprite;
};


#endif //GGJ2020_SPRITE_HPP
