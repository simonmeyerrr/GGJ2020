/*
**
** GLOBAL GAME JAM
**
*/

#ifndef CHARACTER_HPP
    #define CHARACTER_HPP

    #include "../AnimatedGameObject.hpp"

class PlayerOld : public AnimatedGameObject {
public:
    // Constructors
    PlayerOld();
    PlayerOld(const PlayerOld &) = delete;
    PlayerOld &operator=(const PlayerOld &) = delete;
    virtual ~PlayerOld() = default;
};

#endif /*CHARACTER_HPP*/
