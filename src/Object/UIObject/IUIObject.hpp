/*
**
** GLOBAL GAME JAM
**
*/

#ifndef IUIOBJECT_HPP
    #define IUIOBJECT_HPP

    #include <SFML/System/Vector2.hpp>
    #include <SFML/Graphics/Rect.hpp>
    #include <SFML/Graphics/Texture.hpp>
    #include <SFML/Graphics/Color.hpp>
    #include <SFML/Graphics/RenderWindow.hpp>

class IUIObject {
public:
    // Destructor
    virtual ~IUIObject() = default;

    // Methods
    virtual void update() = 0;
    virtual void event(sf::RenderWindow &window, sf::Event &) = 0;
    virtual void draw(sf::RenderWindow &window) const = 0;
};

#endif /* !IUIOBJECT_HPP */