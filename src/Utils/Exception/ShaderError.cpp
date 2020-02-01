//
// Created by chaoticks on 01/02/2020.
//

#include "ShaderError.hpp"

ShaderError::ShaderError(std::string const &message, const std::string &component)
    : Exception(message, component)
{
}
