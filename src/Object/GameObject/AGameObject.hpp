/*
**
** GLOBAL GAME JAM
**
*/

#ifndef AGAMEOBJECT_HPP
    #define AGAMEOBJECT_HPP

    #include "IGameObject.hpp"

class AGameObject : public IGameObject {
    // Constructors
public:
    AGameObject(Type, const std::string &, const Frame &);
    AGameObject(const AGameObject &);
    AGameObject &operator=(const AGameObject &);
    virtual ~AGameObject() override = default;

    // Setters & Getters
    Type getType() const;
    const sf::Texture &getTexture() const;
    const sf::Sprite &getSprite() const;
    const sf::Vector2f &getPosition() const;

    void setTexture(const sf::Texture &);
    void setPosition(const sf::Vector2f &);

protected:
    // Variables
    Type _type;
    sf::Texture _t;
    sf::Sprite _s;


};

#endif /*AGAMEOBJECT_HPP*/
