#ifndef GGJ2020_PLAYERKID_HPP
#define GGJ2020_PLAYERKID_HPP

#include "../AnimatedGameObject.hpp"

class PlayerKid : public AnimatedGameObject {
public:
    // Constructors
    PlayerKid();
    PlayerKid(const PlayerKid &) = delete;
    PlayerKid &operator=(const PlayerKid &) = delete;
    virtual ~PlayerKid() = default;
};

#endif /* GGJ2020_PLAYERKID_HPP */
