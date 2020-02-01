/*
**
** GLOBAL GAME JAM
**
*/

#ifndef IGAMEOBJECT_HPP
    #define IGAMEOBJECT_HPP

    #include <tuple>
    #include <unordered_map> 
    #include <SFML/Graphics/Rect.hpp>
    #include <SFML/Graphics/Texture.hpp>
    #include <SFML/Graphics/Sprite.hpp>
    #include <SFML/System/Time.hpp>
    #include "../../Utils/Using.hpp"

using Frame = sf::IntRect;
using Frames = std::vector<Frame>;
using Animation = std::string;
using Animations = std::unordered_map<std::string, std::tuple<Frames, float>>;

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
    virtual const sf::Vector2f &getPosition() const = 0;
    virtual void setTexture(const sf::Texture &) = 0;
    virtual void setPosition(const sf::Vector2f &) = 0;
    virtual sf::Uint8 *getMask() const = 0;

    // Methods
    virtual void update() = 0;
};

#endif /*IGAMEOBJECT_HPP*/
