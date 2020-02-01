//
// Created by chaoticks on 01/02/2020.
//

#include "MusicError.hpp"

MusicError::MusicError(std::string const &message, const std::string &component)
    : Exception(message, component)
{
}
