//
// Created by chaoticks on 01/02/2020.
//

#include "SceneError.hpp"

SceneError::SceneError(std::string const &message, const std::string &component)
    : Exception(message, component)
{
}
