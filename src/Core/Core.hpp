/*
**
** GLOBAL GAME JAM
**
*/

#ifndef CORE_HPP
    #define CORE_HPP

    #include "../Scene/SceneManager.hpp"
    #include <string>
    #include <memory>
    #include <map>
    #include <SFML/Graphics/Shader.hpp>
    #include "../Utils/Exception/ShaderError.hpp"

    #define SHADERS_SIZE 1

class Core {
public:
    enum ShaderType {
        NONE = -1,
        TEST_SHADER = 0
    };

    const std::string SHADERS[SHADERS_SIZE] = {
        "test_shader"
    };

    const std::map<IScene::TypeScene, ShaderType> _sceneShaders = {
        { IScene::TypeScene::SCENE_INTRO, NONE },
        { IScene::TypeScene::SCENE_MAIN_MENU, NONE },
        { IScene::TypeScene::SCENE_LEVEL2, NONE },
        { IScene::TypeScene::SCENE_LEVEL1, NONE }
    };

    Core();
    Core(Core &) = delete;
    Core &operator=(Core &) = delete;
    ~Core() = default;

    void initShaders();
    void start();

private:
    void event();
    void update();
    void display();
    void manageEvent(IScene::Event);

    sf::Clock _displayTimer;
    sf::Clock _updateTimer;
    sf::Int64  _updateRest;
    std::unique_ptr<sf::RenderWindow> _win;
    std::unique_ptr<SceneManager> _sceneManager;

    std::map<ShaderType, sf::Shader> _shaders;
    ShaderType _currentShader;
    IScene::Saves _save;
};

#endif /*CORE_HPP*/
