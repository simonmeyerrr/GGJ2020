/*
**
** GLOBAL GAME JAM
**
*/

#ifndef IGAMEOBJECT_HPP
    #define IGAMEOBJECT_HPP

    #include <SFML/Graphics/Color.hpp>
    #include <SFML/Graphics/Drawable.hpp>
    #include <SFML/Graphics/RenderTarget.hpp>
    #include <SFML/Graphics/Transformable.hpp>
    #include "../../Utils/Using.hpp"

class IGameObject : public sf::Drawable, public sf::Transformable {
public:
    // Enum
    enum GameObjectType {
        STATIC,
        ANIMATED
    };

    // Constructors
    virtual ~IGameObject() = default;

    // Setters & Getters
    virtual GameObjectType getType() const = 0;
    virtual sf::FloatRect getLocalBounds() const = 0;
    virtual sf::FloatRect getGlobalBounds() const = 0;
    virtual void setColor(const sf::Color &) = 0;


protected:
    // Methods
    virtual void draw(sf::RenderTarget &, sf::RenderStates) const = 0;
};

#endif /*IGAMEOBJECT_HPP*/
