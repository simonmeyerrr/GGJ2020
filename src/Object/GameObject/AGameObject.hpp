/*
**
** GLOBAL GAME JAM
**
*/

#ifndef AGAMEOBJECT_HPP
    #define AGAMEOBJECT_HPP

    #include <SFML/System/Vector2.hpp>
    #include "IGameObject.hpp"

class AGameObject : public IGameObject{
public:
    // Constructors
    AGameObject(GameObjectType, sf::Time = sf::seconds(0.2f));
    AGameObject(const AGameObject &);
    AGameObject &operator=(const AGameObject &);
    ~AGameObject();

    // Setters & Getters
    void setAnimation(const Animation &);
    void setFrame(std::size_t, bool = true);
    void setColor(const sf::Color &);
    void setFrameTime(sf::Time);

    GameObjectType getType() const;
    const Animation *getAnimation() const;
    std::size_t getCurrentFrame() const;
    const sf::Texture *getTexture() const;
    sf::FloatRect getLocalBounds() const;
    sf::FloatRect getGlobalBounds() const;
    sf::Time getFrameTime() const;

protected:
    // Methods
    virtual void draw(sf::RenderTarget &, sf::RenderStates) const;

    // Variables
    GameObjectType _type;
    std::size_t _currentFrame;
    sf::Vertex _vertices[4];
    const sf::Texture *_t;
    const Animation* _anim;
    sf::Time _frameTime;
    sf::Time _currentTime;
};

#endif /*AGAMEOBJECT_HPP*/
