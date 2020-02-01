/*
**
** GLOBAL GAME JAM
**
*/

#ifndef STATICGAMEOBJECT_HPP
    #define STATICGAMEOBJECT_HPP

    #include "AGameObject.hpp"

class StaticGameObject : public AGameObject {
public:
    // Constructors
    StaticGameObject(sf::Time = sf::seconds(0.2f));
    StaticGameObject(const StaticGameObject &);
    StaticGameObject &operator=(const StaticGameObject &);
    virtual ~StaticGameObject() = default;

    // Methods
    void update(sf::Time);
};

#endif /*STATICGAMEOBJECT_HPP*/
