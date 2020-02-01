/*
**
** GLOBAL GAME JAM
**
*/

#ifndef IGAMEOBJECT_HPP
    #define IGAMEOBJECT_HPP

    #include <SFML/Graphics/Drawable.hpp>
    #include <SFML/Graphics/Transformable.hpp>

class IGameObject : public sf::Drawable, public sf::Transformable {
public:
    // Enum
    enum GameType {
        STATIC,
        ANIMATED
    };

    // Constructors
    virtual ~IGameObject() = default;

    // Setters & Getters
    virtual GameType getType() const = 0;
    virtual void setColor(const sf::Color &) = 0;

    // Methods
    virtual sf::FloatRect getLocalBounds() const = 0;
    virtual sf::FloatRect getGlobalBounds() const = 0;

private:
    // Methods
    virtual void draw(sf::RenderTarget &, sf::RenderStates) const = 0;
};

#endif /*IGAMEOBJECT_HPP*/
