/*
**
** GLOBAL GAME JAM
**
*/

#ifndef IGAMEOBJECT_HPP
    #define IGAMEOBJECT_HPP

    #include <SFML/System/Time.hpp>
    #include <SFML/Graphics/Color.hpp>
    #include <SFML/Graphics/Drawable.hpp>
    #include <SFML/Graphics/RenderTarget.hpp>
    #include <SFML/Graphics/Transformable.hpp>
    #include "../../Utils/Using.hpp"
    #include "Animation.hpp"

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
    virtual void setAnimation(const Animation &) = 0;
    virtual void setFrame(std::size_t, bool = true) = 0;
    virtual void setColor(const sf::Color &) = 0;
    virtual void setFrameTime(sf::Time) = 0;

    virtual IGameObject::GameObjectType getType() const = 0;
    virtual const Animation *getAnimation() const = 0;
    virtual std::size_t getCurrentFrame() const = 0;
    virtual const sf::Texture *getTexture() const = 0;
    virtual sf::FloatRect getLocalBounds() const = 0;
    virtual sf::FloatRect getGlobalBounds() const = 0;
    virtual sf::Time getFrameTime() const = 0;

    // Methods
    virtual void update(sf::Time) = 0;

protected:
    // Methods
    void draw(sf::RenderTarget &, sf::RenderStates) const override = 0;
};

#endif /*IGAMEOBJECT_HPP*/
