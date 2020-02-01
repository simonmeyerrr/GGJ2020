//
// Created by chaoticks on 01/02/2020.
//

#ifndef GGJ2020_OBJECTERROR_HPP
#define GGJ2020_OBJECTERROR_HPP

#include "Exception.hpp"

class ObjectError : public Exception {
public:
    ObjectError(std::string const &message,
    std::string const &component = "Unknown");
};


#endif //GGJ2020_OBJECTERROR_HPP
