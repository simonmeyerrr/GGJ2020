//
// Created by chaoticks on 01/02/2020.
//

#ifndef GGJ2020_SCENEERROR_HPP
#define GGJ2020_SCENEERROR_HPP

#include "Exception.hpp"

class SceneError : public Exception {
public:
    SceneError(std::string const &message,
                std::string const &component = "Unknown");
};

#endif //GGJ2020_SCENEERROR_HPP
