/*
**
** GLOBAL GAME JAM
**
*/

#include "Core.hpp"

Core::Core()
    : _displayTimer(), _updateTimer(), _updateRest(0),
    _win(std::make_unique<sf::RenderWindow>(sf::VideoMode(1600, 900, 32), "GGJ2020")),
    _sceneManager(std::make_unique<SceneManager>())
{
}

void Core::initShaders()
{
    for (int i = 0; i < SHADERS_SIZE; ++i) {
        if (!_shaders[static_cast<ShaderType>(i)].loadFromFile(
            "resources/shaders/" + SHADERS[i] + ".vert",
            "resources/shaders/" + SHADERS[i] + ".frag")
            ) {
            throw ShaderError("Unable to load shader " + SHADERS[i]);
        }
    }
}

void Core::start()
{
    _sceneManager->push(IScene::SCENE_INTRO);
    initShaders();

    _displayTimer.restart();
    _updateTimer.restart();
    _updateRest = 0;
    while (_win->isOpen() && !_sceneManager->isEmpty()) {
        event();
        update();
        display();
    }
    if (_win->isOpen())
        _win->close();
}

void Core::event()
{
    sf::Event event{};

    while (_win->isOpen() && !_sceneManager->isEmpty() && _win->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            _win->close();
        else
            manageEvent(_sceneManager->get()->event(*_win, event));
    }
}

void Core::update()
{
    auto elapsed = _updateTimer.getElapsedTime().asMilliseconds() + _updateRest;

    _updateTimer.restart();
    while (elapsed >= (1.0 / 30.0) * 1000.0) {
        if (_win->isOpen() && !_sceneManager->isEmpty())
            manageEvent(_sceneManager->get()->update());
        elapsed -= (1.0 / 30.0) * 1000.0;
    }
    _updateRest = elapsed;
}

void Core::display()
{
    auto elapsed = _displayTimer.getElapsedTime().asMilliseconds();

    if (elapsed >= (1.0 / 30.0) * 1000.0) {
        _displayTimer.restart();
        if (_win->isOpen() && !_sceneManager->isEmpty()) {
            _win->clear(sf::Color::Black);
            _sceneManager->get()->display(*_win);
            _win->display();
        }
    }
}

void Core::manageEvent(IScene::Event event)
{
    switch (event.event) {
        case IScene::EVENT_CLOSE_WINDOW:
            _win->close();
            break;
        case IScene::EVENT_POP_SCENE:
            _sceneManager->pop();
            break;
        case IScene::EVENT_PUSH_SCENE:
            _sceneManager->push(event.scene);
        default:
            break;
    }
}
