/*
**
** GLOBAL GAME JAM
**
*/

#ifndef AGAMEOBJECT_HPP
    #define AGAMEOBJECT_HPP

    #include <SFML/System/Vector2.hpp>
    #include "IGameObject.hpp"

class AGameObject {
public:
    // Constructors
    AGameObject(IGameObject::GameObjectType);
    AGameObject(const AGameObject &);
    AGameObject &operator=(const AGameObject &);
    ~AGameObject();

    // Setters & Getters
    IGameObject::GameObjectType getType() const;
    sf::FloatRect getLocalBounds() const;
    sf::FloatRect getGlobalBounds() const;
    void setColor(const sf::Color &);

private:
    // Variables
    IGameObject::GameObjectType _type;
    std::size_t _currentFrame;
    sf::Vertex _vertices[4];
    const sf::Texture *_t;
    const Animation* _anim;
};
    
#endif /*AGAMEOBJECT_HPP*/
