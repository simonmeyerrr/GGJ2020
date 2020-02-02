#ifndef GGJ2020_PLAYERSCHOOL_HPP
#define GGJ2020_PLAYERSCHOOL_HPP

#include "../AnimatedGameObject.hpp"

class PlayerSchool : public AnimatedGameObject {
public:
    // Constructors
    PlayerSchool();
    PlayerSchool(const PlayerSchool &) = delete;
    PlayerSchool &operator=(const PlayerSchool &) = delete;
    virtual ~PlayerSchool() = default;
};

#endif /* GGJ2020_PLAYERSCHOOL_HPP */
