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
    #include "../Utils/Shaders.hpp"
#include "../Object/SoundObject/SoundObject.hpp"

class Core {
public:
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

    shaders_map _shaders;
    IScene::Saves _save;
};

#endif /*CORE_HPP*/
