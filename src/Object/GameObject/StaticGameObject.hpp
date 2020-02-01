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
    StaticGameObject(const std::string &, sf::IntRect);
    StaticGameObject(const StaticGameObject &);
    StaticGameObject &operator=(const StaticGameObject &);
    virtual ~StaticGameObject() = default;

    // Methods
    void update();
};

#endif /*STATICGAMEOBJECT_HPP*/
