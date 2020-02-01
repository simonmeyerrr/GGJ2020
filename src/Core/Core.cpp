/*
**
** GLOBAL GAME JAM
**
*/

#include "Core.hpp"

Core::Core()
    : _sceneManager(std::make_unique<SceneManager>())
{
}

void Core::initShaders()
{
    for (int i = 0; i < SHADERS_SIZE; ++i) {
        if (!_shaders[static_cast<ShaderType>(i)].loadFromFile("resources/shaders/" + SHADERS[i] + ".vert", "resources/shaders/" + SHADERS[i] + ".frag")) {
            std::cerr << "Error: Unable to load shader " << SHADERS[i] << std::endl;
        }
    }
}
