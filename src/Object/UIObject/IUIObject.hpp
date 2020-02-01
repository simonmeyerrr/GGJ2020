/*
**
** GLOBAL GAME JAM
**
*/

#ifndef IUIOBJECT_HPP
    #define IUIOBJECT_HPP

    #include <SFML/System/Vector2.hpp>
    #include <SFML/Graphics/Rect.hpp>
    #include <SFML/Graphics/Texture.hpp>
    #include <SFML/Graphics/Color.hpp>
    #include <SFML/Graphics/RenderWindow.hpp>

class IUIObject {
public:
    // Destructor
    virtual ~IUIObject() = default;

    // Setters & Getters
    virtual sf::Vector2f const &getPosition() const = 0;
    virtual void setPosition(sf::Vector2f &) = 0;
    virtual void setScale(const sf::Vector2f &) = 0;
    virtual sf::Vector2f const &getScale() const = 0;
    virtual void setOrigin(const sf::Vector2f &) = 0;
    virtual sf::Vector2f const &getOrigin() const = 0;
    virtual void setTexture(const sf::Texture &texture, bool resetRect = false) = 0;
    virtual sf::Texture &getTexture() const = 0;
    virtual void setTextureRect(const sf::IntRect &rectangle) = 0;
    virtual void setColor(const sf::Color &) = 0;
    virtual sf::Color const &getColor() = 0;
    virtual sf::FloatRect getGlobalBounds() = 0;

    // Methods
    virtual void draw(sf::RenderWindow &window) const = 0;
};

#endif /* !IUIOBJECT_HPP */