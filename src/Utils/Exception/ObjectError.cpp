//
// Created by chaoticks on 01/02/2020.
//

#include "ObjectError.hpp"

ObjectError::ObjectError(std::string const &message, const std::string &component)
    : Exception(message, component)
{
}
