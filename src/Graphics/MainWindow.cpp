#include "MainWindow.hpp"

MainWindow::MainWindow() :
_renderWindow(std::make_shared<sf::RenderWindow>(
        sf::VideoMode(1600,
                900,
                32), "GGJ20")) {
}

MainWindow::~MainWindow() = default;

sf::Vector2i MainWindow::getMousePosition() const {
    return sf::Mouse::getPosition(*_renderWindow);
}

void MainWindow::setMousePosition(sf::Vector2i pos) {
    _posMouse = sf::Mouse::getPosition(*_renderWindow);
}
