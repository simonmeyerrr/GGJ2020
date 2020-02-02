#ifndef GGJ2020_PLAYERSOLDAT_HPP
#define GGJ2020_PLAYERSOLDAT_HPP

#include "../AnimatedGameObject.hpp"

class PlayerSoldat : public AnimatedGameObject {
    public:
        // Constructors
        PlayerSoldat();
        PlayerSoldat(const PlayerSoldat &) = delete;
        PlayerSoldat &operator=(const PlayerSoldat &) = delete;
        virtual ~PlayerSoldat() = default;
};


#endif /* GGJ2020_PLAYERSOLDAT_HPP */
