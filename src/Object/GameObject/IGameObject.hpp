/*
**
** GLOBAL GAME JAM
**
*/

#ifndef IGAMEOBJECT_HPP
    #define IGAMEOBJECT_HPP

    #include <unordered_map>
    #include <SFML/Graphics/Rect.hpp>
    #include <SFML/Graphics/Texture.hpp>
    #include <SFML/Graphics/Sprite.hpp>
    #include <SFML/System/Time.hpp>
    #include "../../Utils/Using.hpp"

using Frame = sf::IntRect;
using Frames = std::vector<Frame>;
using Animation = std::string;
using Animations = std::unordered_map<std::string, Frames>;

class IGameObject {
public:
    // Enum
    enum Type {
        STATIC,
        ANIMATED
    };

    // Constructors
    virtual ~IGameObject() = default;

    // Setters & Getters
    virtual Type getType() const = 0;
    virtual const sf::Texture &getTexture() const = 0;
    virtual const sf::Sprite &getSprite() const = 0;
    virtual void setTexture(const sf::Texture &) = 0;

    // Methods
    virtual void update(sf::Time) = 0;
};

#endif /*IGAMEOBJECT_HPP*/
