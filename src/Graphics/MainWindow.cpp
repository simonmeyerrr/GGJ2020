/*
**
** GLOBAL GAME JAM
**
*/

#include "MainWindow.hpp"

MainWindow::MainWindow()
    : _renderWindow(std::make_shared<sf::RenderWindow>(
        sf::VideoMode(1600, 900, 32), "GGJ20")) {
}

sf::Vector2i MainWindow::getMousePosition() const
{
    return sf::Mouse::getPosition(*_renderWindow);
}

const s_ptr<sf::RenderWindow> &MainWindow::getRenderWindow() const {
    return _renderWindow;
}