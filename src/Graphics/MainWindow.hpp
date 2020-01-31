/*
**
** GLOBAL GAME JAM
**
*/

#ifndef MAINWINDOW_HPP
    #define MAINWINDOW_HPP

    #include <SFML/Graphics/RenderWindow.hpp>
    #include <SFML/Window/Mouse.hpp>
    #include <memory>
    #include "../Utils/Using.hpp"

class MainWindow {
public:
    // Constructors
    MainWindow();
    MainWindow(MainWindow const &) = delete;
    MainWindow &operator=(MainWindow const &) = delete;
    ~MainWindow() = default;

    // Setters & Getters
    sf::Vector2i getMousePosition() const;
    const s_ptr<sf::RenderWindow> &getRenderWindow() const;
    void setMousePosition(sf::Vector2i);


private:
    // Variables
    s_ptr<sf::RenderWindow> _renderWindow;
    sf::Vector2i _posMouse;
};

#endif /* !MAINWINDOW_HPP */
