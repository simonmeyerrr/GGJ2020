//
// Created by chaoticks on 01/02/2020.
//

#ifndef GGJ2020_MUSICERROR_HPP
#define GGJ2020_MUSICERROR_HPP

#include "Exception.hpp"

class MusicError : public Exception {
public:
    MusicError(std::string const &message,
                std::string const &component = "Unknown");
};

#endif //GGJ2020_MUSICERROR_HPP
