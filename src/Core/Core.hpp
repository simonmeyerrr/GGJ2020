/*
**
** GLOBAL GAME JAM
**
*/

#ifndef CORE_HPP
    #define CORE_HPP

    #include "../Scene/SceneManager.hpp"
    #include <string>
    #include <bits/unique_ptr.h>
    #include <map>
    #include <SFML/Graphics/Shader.hpp>

    #define SHADERS_SIZE 1

class Core {
public:

    enum ShaderType {
        TEST_SHADER
    };

    const std::string SHADERS[SHADERS_SIZE] = {
        "test_shader"
    };

    Core();
    Core(Core &) = delete;
    Core &operator=(Core &) = delete;
    ~Core() = default;

    void initShaders();

private:
    std::unique_ptr<SceneManager> _sceneManager;

    std::map<ShaderType, sf::Shader> _shaders;
};

#endif /*CORE_HPP*/
