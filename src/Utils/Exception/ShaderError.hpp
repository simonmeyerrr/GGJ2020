//
// Created by chaoticks on 01/02/2020.
//

#ifndef GGJ2020_SHADERERROR_HPP
#define GGJ2020_SHADERERROR_HPP

#include "Exception.hpp"

class ShaderError : public Exception {
public:
    ShaderError(std::string const &message,
                std::string const &component = "Unknown");
};

#endif //GGJ2020_SHADERERROR_HPP
