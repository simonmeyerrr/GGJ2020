/*
**
** GLOBAL GAME JAM
**
*/

#ifndef CHARACTER_HPP
    #define CHARACTER_HPP

    #include "../AnimatedGameObject.hpp"

class Character : public AnimatedGameObject {
public:
    // Constructors
    Character();
    Character(const Character &) = delete;
    Character &operator=(const Character &) = delete;
    virtual ~Character() = default;
};

#endif /*CHARACTER_HPP*/
