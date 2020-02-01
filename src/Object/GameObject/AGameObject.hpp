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
    virtual ~AGameObject() = default;

    // Setters & Getters
    Type getType() const;
    const sf::Texture &getTexture() const;
    const sf::Sprite &getSprite() const;
    sf::Uint8 *getMask() const;
    void setTexture(const sf::Texture &);

protected:
    // Variables
    Type _type;
    sf::Texture _t;
    sf::Sprite _s;
    sf::Uint8 *_mask;


};

#endif /*AGAMEOBJECT_HPP*/
