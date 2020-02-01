//
// Created by Jean-Gaël Choppe on 01/02/2020.
//

#ifndef GGJ2020_SPRITE_HPP
    #define GGJ2020_SPRITE_HPP


#include "IUIObject.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include "../../Utils/Using.hpp"

class Sprite : IUIObject {
public:
    // Constructors
    Sprite(sf::Texture const &, const sf::IntRect &, const sf::Vector2f &);
    ~Sprite() override {std::cout << "Sprite end" << std::endl;};

    // Setters & Getters
    const sf::Vector2f &getPosition() const;
    void setPosition(sf::Vector2f &f);
    void setTextureRect(const sf::IntRect &rectangle);
    sf::IntRect getTextureRect() const;
    sf::FloatRect getGlobalBounds() const;

    // Operators
    Sprite &operator=(Sprite const &);

    // Methods
    void update() override;
    void event(sf::RenderWindow &window, sf::Event &) override;
    void draw(sf::RenderWindow &) const override;

private:
    s_ptr<sf::Texture> _texture;
    s_ptr<sf::Sprite> _sprite;
};


#endif //GGJ2020_SPRITE_HPP
