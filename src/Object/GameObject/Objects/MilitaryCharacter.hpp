/*
**
** GLOBAL GAME JAM
**
*/

#ifndef MILITARY_CHARACTER_HPP
#define MILITARY_CHARACTER_HPP

#include "../AnimatedGameObject.hpp"

class MilitaryCharacter : public AnimatedGameObject {
public:
    // Constructors
    MilitaryCharacter();
    MilitaryCharacter(const MilitaryCharacter &) = delete;
    MilitaryCharacter &operator=(const MilitaryCharacter &) = delete;
    virtual ~MilitaryCharacter() = default;
};

#endif /*MILITARY_CHARACTER_HPP*/
