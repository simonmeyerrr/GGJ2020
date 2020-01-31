#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Mouse.hpp>
#include <memory>

class MainWindow {
public:
    MainWindow();
    MainWindow(MainWindow const &) = delete;
    ~MainWindow();

    MainWindow &operator=(MainWindow const &) = delete;

    sf::Vector2i getMousePosition() const;
    void setMousePosition(sf::Vector2i pos);

private:
    std::shared_ptr<sf::RenderWindow> _renderWindow;
    sf::Vector2i _posMouse;
};