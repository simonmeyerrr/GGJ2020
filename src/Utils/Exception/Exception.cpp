//
// Created by chaoticks on 01/02/2020.
//

#include "Exception.hpp"

const char *Exception::what() const noexcept {
    return exception::what();
}

Exception::Exception(std::string const &message, const std::string &component)
    : _message(message), _component(component)
{
}
