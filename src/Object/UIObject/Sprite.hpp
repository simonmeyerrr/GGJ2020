//
// Created by Jean-Gaël Choppe on 01/02/2020.
//

#ifndef GGJ2020_SPRITE_HPP
    #define GGJ2020_SPRITE_HPP


#include "IUIObject.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include "../../Utils/Using.hpp"

class Sprite : public IUIObject {
public:
    // Constructors
    Sprite(const std::string &filename, const sf::IntRect &, const sf::Vector2f &);
    ~Sprite() override = default;

    // Setters & Getters
    const sf::Vector2f &getPosition() const;
    void setPosition(sf::Vector2f &f);
    void setTextureRect(const sf::IntRect &rectangle);
    sf::IntRect getTextureRect() const;
    sf::FloatRect getGlobalBounds() const;
    sf::Texture getTexture() const;
    sf::Sprite getSprite() const;
    sf::Uint8 *getMask() const;

    // Operators
    Sprite &operator=(Sprite const &);

    // Methods
    void update() override;
    void event(sf::RenderWindow &window, sf::Event &) override;
    void draw(sf::RenderWindow &) const override;

private:
    s_ptr<sf::Texture> _texture;
    s_ptr<sf::Sprite> _sprite;
    s_ptr<sf::Uint8 *> _mask;
};


#endif //GGJ2020_SPRITE_HPP
