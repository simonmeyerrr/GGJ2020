/*
** EPITECH PROJECT, 2020
** GGJ2020
** File description:
** Shaders.hpp
*/

#ifndef GGJ2020_SHADERS_HPP
    #define GGJ2020_SHADERS_HPP

    #include <string>

    #define SHADERS_SIZE 1

enum ShaderType {
    AMBIENT_LIGHTS
};

const std::string shaderPaths[SHADERS_SIZE] = {
    "ambient_lights"
};

using shaders_map = std::map<ShaderType, sf::Shader>;

#endif //GGJ2020_SHADERS_HPP