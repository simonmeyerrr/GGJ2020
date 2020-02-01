/*
**
** GLOBAL GAME JAM
**
*/

#ifndef CORE_HPP
    #define CORE_HPP

#include <string>
#include <memory>
#include <SFML/Graphics.hpp>
#include "../Scene/SceneManager.hpp"

class Core {
public:
    Core();
    Core(Core &) = delete;
    Core &operator=(Core &) = delete;
    ~Core() = default;

    void start();

private:
    void event();
    void update();
    void display();
    void manageEvent(IScene::Event);

    sf::Clock _displayTimer;
    sf::Clock _updateTimer;
    sf::Int32  _updateRest;
    std::unique_ptr<sf::RenderWindow> _win;
    std::unique_ptr<SceneManager> _sceneManager;
};

#endif /*CORE_HPP*/
